#pragma once

#include "normalized_lock_free.h"
#include "wait_free_queue.h"

namespace WaitFreeSimulation
{
    template <class I, class O>
    class WaitFreeSimulator
    {
        using Cases = std::vector<CasDescriptor>;

        public:
            WaitFreeSimulator(NormalizedLockFree l, WaitFreeQueue<I, O> h);
            int run(Operation& op);
            void helpMakeProgress();
            int casExecutor(const Cases& cases, ContentionMeasure& cm) const;

        private:
            NormalizedLockFree algorithm;
            WaitFreeQueue<I, O> helpQueue;
            const int RETRY_THRESHOLD = 2;
    };
}