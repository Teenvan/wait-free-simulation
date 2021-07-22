#include "wait_free_simulator.h"
#include "operation_record_box.h"
#include <atomic>
#include <utility>

namespace WaitFreeSimulation
{
    template <class O>
    WaitFreeSimulator<O>::WaitFreeSimulator(NormalizedLockFree l, WaitFreeQueue<O> h)
    : algorithm(std::move(l)),
    helpQueue(std::move(h))
    {}

    template <class O>
    int WaitFreeSimulator<O>::casExecutor(const Cases &cases, ContentionMeasure& cm) const
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

    template <class O>
    void WaitFreeSimulator<O>::helpMakeProgress()
    {
        if (auto help = helpQueue.peek()) 
        {
            // Do something to help
        }
    }

    template <class O>
    int WaitFreeSimulator<O>::run(Operation &op)
    {
        // You can keep retrying the fast path
        // until a certain point which is based on contention
        // or a predetermined retry threshold.
        int retry = 0;
        while (retry >= 0)
        {
            bool helpNeeded = /* Once in a while */ true;
            if (helpNeeded)
            {
                helpMakeProgress();
            }
            auto contention = ContentionMeasure();

            if (contention.use_slow_path()) {
                break;
            }
            const auto& cases =  algorithm.generator(op, contention);
            if (contention.use_slow_path()) {
                break;
            }
            const int rcode = casExecutor(cases, contention);
            if (contention.use_slow_path()) {
                break;
            }
            const auto& result = algorithm.wrapUp(cases, rcode, contention);

            if (result != -1) {
                // Wrap-up was successful
                return result;
            } else {
                continue;
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
        int rcode = 0;
        if (rcode != -1)
        {
            // Error
            // slow-path : ask for help
            // rcode refers to the position where we started failing
            OperationRecord<O> record(rcode);
            OperationRecordBox<O> box(&record);
            // Enqueue the pointer to the record box
            helpQueue.add(&box);
            // Using sequentially consistent ordering
            // While we haven't completed, we will keep on helping
            while (!box.operationPointer()
                            .load(std::memory_order_seq_cst)->completed)
            {
                // This will be a safe operation once we have hazard pointers
                helpMakeProgress();
            }
        }
    }   
}