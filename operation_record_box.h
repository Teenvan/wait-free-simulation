#pragma once

#include "operation_record.h"
#include <atomic>

namespace WaitFreeSimulation
{
    template<class I, class O>
    class OperationRecordBox
    {
        public:
            OperationRecordBox(OperationRecord<I, O>* v);
            std::atomic<OperationRecord<I, O>*> operationPointer() const;
        private:    
            std::atomic<OperationRecord<I, O>*> v;
    };
}