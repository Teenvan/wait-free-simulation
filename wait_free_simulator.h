#pragma once

#include "normalized_lock_free.h"
#include "wait_free_queue.h"

namespace WaitFreeSimulation
{
    class WaitFreeSimulator
    {
        using Cases = std::vector<CasDescriptor>;

        public:
            WaitFreeSimulator(NormalizedLockFree l, WaitFreeQueue h);
            int run(Operation& op);
            void helpMakeProgress();
            int casExecutor(const Cases& cases, ContentionMeasure& cm) const;

        private:
            NormalizedLockFree algorithm;
            WaitFreeQueue helpQueue;
            const int RETRY_THRESHOLD = 2;
    };
}