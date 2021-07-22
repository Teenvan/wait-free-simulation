#pragma once

#include "help.h"
#include <atomic>

namespace WaitFreeSimulation
{
    template<class O>
    class OperationRecordBox
    {
        public:
            OperationRecordBox(OperationRecord<O>* v);
            std::atomic<OperationRecord<O>*> operationPointer() const;
        private:    
            std::atomic<OperationRecord<O>*> v;
    };
}