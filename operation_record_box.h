#pragma once

#include "operation_record.h"
#include <atomic>

namespace WaitFreeSimulation
{
    class OperationRecordBox
    {
        public:
            OperationRecordBox(OperationRecord* v);   
            std::atomic<OperationRecord*> v;
    };
}