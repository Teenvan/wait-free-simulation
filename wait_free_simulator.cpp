#include "wait_free_simulator.h"
#include <atomic>
#include <utility>

namespace WaitFreeSimulation
{
    WaitFreeSimulator::WaitFreeSimulator(NormalizedLockFree l,
    WaitFreeQueue h)
    : algorithm {std::move(l)},
    helpQueue {std::move(h)}
    {}

    int WaitFreeSimulator::casExecutor(const Cases &cases, ContentionMeasure& cm) const
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
            // Do something to help
        }
    }

    int WaitFreeSimulator::run(Operation &op)
    {
        int retry = 0;
        while (retry >= 0)
        {
            bool helpNeeded = /* Once in a while */false;
            if (retry == 0) {
                if (helpNeeded)
                {
                    helpMakeProgress();
                } else {
                    // helping
                }
            }

            auto contention = ContentionMeasure();
            const auto& cases =  algorithm.generator(op);
            const int rcode = casExecutor(cases, contention);
            const auto& result = algorithm.wrapUp(cases, rcode);

            if (result != -1) {
                // Wrap-up was successful
                return result;
            } else {
                continue;
            }

            /*
            if (rcode != -1)
            {
                // Error
                // slow-path : ask for help
                // rcode refers to the position where we started failing
                Help help(rcode);
                helpQueue.add(help);
                // Using sequentially consistent ordering
                while (!help.completed.load(std::memory_order_seq_cst))
                {
                    helpMakeProgress();
                }
            }
            */

            ++retry;
        }
    }   
}