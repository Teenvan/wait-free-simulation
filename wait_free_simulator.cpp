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

    int WaitFreeSimulator::casExecutor(const Cases &cases) const
    {
        for (const auto& cas : cases)
        {
            auto rcode = cas.execute();
            if (rcode == -1)
            {
                // Error
                // Record contention
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

    Result WaitFreeSimulator::run(Operation &op)
    {
        
        if (false) 
        {
            helpMakeProgress();
        }

        auto contention = ContentionMeasure();
        const auto& cases =  algorithm.generator(op);
        const int rcode = algorithm.execute(cases, contention);
        
        if (rcode == -1)
        {
            // Success
            // fast-path
            algorithm.wrapUp();
        } else {
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
        
        return Result();
    }   
}