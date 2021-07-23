#include "wait_free_simulator.h"
#include "wait_free_queue.h"
#include "cas_descriptor.h"
#include "operation_record_box.h"
#include "operation_state.h"
#include <atomic>
#include <utility>
#include <thread>

namespace WaitFreeSimulation
{
    WaitFreeSimulator::WaitFreeSimulator(NormalizedLockFree l, WaitFreeQueue h)
    : algorithm(std::move(l)),
    helpQueue(std::move(h))
    {}

    int WaitFreeSimulator::casExecutor(const Cases &cases, 
                                            ContentionMeasure& cm) const
    {
        for (const auto& cas : cases)
        {
            auto rcode = cas.execute();
            if (rcode == -1)
            {
                // Error
                // Record contention
                cm.detected();
                return rcode;
            }
                   
        }

        // No error so return a positive result code
        return 1;
    }

    void WaitFreeSimulator::helpMakeProgress()
    {
        if (auto help = helpQueue.peek()) 
        {
            // Hazard pointers will help us here.
            helpOp(help);
        }
    }

    // Guarantees that on return , orb is no longer in help queue
    void WaitFreeSimulator::helpOp(OperationRecordBox* orb)
    {
        while(true)
        {
            auto _or = orb->v.load(std::memory_order_seq_cst);
            // Create a copy of the operational record
            OperationRecord or_clone(*_or);
            // Contention Measure to be used for the PreCas stage
            ContentionMeasure m;
            std::variant<Cases, Contention> genVariant;
            switch (_or->state)
            {
                case OperationState::Completed:
                    helpQueue.tryRemoveFront(orb);
                    return;
                case OperationState::PreCas:
                    // This is the RCU part (Read->Copy->Update)
                    or_clone.state = OperationState::ExecuteCas;
                    genVariant = algorithm.generator(or_clone.input, m);
                    if (std::holds_alternative<Cases>(genVariant))
                    {
                        or_clone.casDescriptors = std::get<Cases>(genVariant);
                    } else if (std::holds_alternative<Contention>(genVariant))
                    {
                        break;
                    }
                    // Some other thread may have tried to help and 
                    // would be trying to update the or with 
                    // their version of the or.
                    // Hence, we require a compare_exchange
                    // It is fine if we fail here. 
                    orb->v.compare_exchange_strong(_or, &or_clone);
                    break;
                case OperationState::ExecuteCas:
                    or_clone.failedIndex = casExecutor(or_clone.casDescriptors
                                                                        , m);
                    or_clone.state = OperationState::PostCas;
                    orb->v.compare_exchange_strong(_or, &or_clone);
                    break;
                case OperationState::PostCas:
                    const auto& resVariant = algorithm.wrapUp(or_clone.casDescriptors, 
                                                or_clone.failedIndex, m);
    
                    if (std::holds_alternative<Output>(resVariant))
                    {
                        // Success
                        or_clone.state = OperationState::Completed;
                    } else if (std::holds_alternative<std::optional<Contention>>(resVariant))
                    {
                        const auto& optContentional = std::get<std::optional<Contention>>(resVariant);
                        if (optContentional.has_value())
                        {
                            // Exited because there was contention
                            // Not up to us to restart 
                            break;
                        } else {
                            // Failed. We need to restart from the generator.
                            or_clone.state = OperationState::PreCas;
                        }
                    }
                    orb->v.compare_exchange_strong(_or, &or_clone);
                    break;
            }
        }
    }

    int WaitFreeSimulator::run(Input& op)
    {
        // You can keep retrying the fast path
        // until a certain point which is based on contention
        // or a predetermined retry threshold.

        int retry = 0;
        bool helpNeeded = /* Once in a while */ true;
        if (helpNeeded)
        {
            helpMakeProgress();
        }
        while (retry >= 0)
        {
            auto contention = ContentionMeasure();

            if (contention.use_slow_path()) {
                break;
            }
            const auto& genVariant =  algorithm.generator(op, 
                                                        contention);

            if (std::holds_alternative<Cases>(genVariant))
            {
                const auto& cases = std::get<Cases>(genVariant);
                const int rcode = casExecutor(cases, contention);
                const auto& resultVariant = algorithm.wrapUp(cases, 
                                                            rcode, contention);
                

            } else if (std::holds_alternative<Contention>(genVariant))
            {
                break;
            }


            if (contention.use_slow_path()) {
                break;
            }

            if (retry > RETRY_THRESHOLD) {
                // slow path
                break;
            }
            ++retry;
        }

        // Slow Path
        std::vector<CasDescriptor> cases{};
        OperationRecord record(
            std::this_thread::get_id(),
            op,
            OperationState::PreCas,
            cases,
            0
        );
        OperationRecordBox box(&record);
        // Enqueue the pointer to the record box
        helpQueue.add(&box);
        // Using sequentially consistent ordering
        // While we haven't completed, we will keep on helpin g
        while (!box.v.load(std::memory_order_seq_cst)->isCompleted())
        {
            // This will be a safe operation once we have hazard pointers
            helpMakeProgress();
        }
    }   
}