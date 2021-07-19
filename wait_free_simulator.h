#pragma once

#include "normalized_lock_free.h"
#include "wait_free_queue.h"

namespace WaitFreeSimulation
{
    class WaitFreeSimulator
    {
        public:
            WaitFreeSimulator(NormalizedLockFree l, WaitFreeQueue h);
            Result run(Operation& op);
            void helpMakeProgress();

        private:
            NormalizedLockFree algorithm;
            WaitFreeQueue helpQueue;
    };
}