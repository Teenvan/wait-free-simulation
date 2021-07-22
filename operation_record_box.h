#pragma once

#include "help.h"
#include <atomic>

namespace WaitFreeSimulation
{
    class OperationRecordBox
    {
        public:
            OperationRecordBox(OperationRecord* v);
        private:    
            std::atomic<OperationRecord*> v;
    };
}