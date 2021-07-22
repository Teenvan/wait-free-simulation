#pragma once

#include "operation_state.h"
#include <cstdint>

namespace WaitFreeSimulation
{   
    template<class I, class O>
    class OperationRecord
    {
        public:
            bool completed;
            uint32_t at;
            uint32_t ownerTid; // Owner thread identifier
            I input; // Object with operation and input parameters
            OperationState state;

            OperationRecord(uint64_t current);
            // Copy constructor
            OperationRecord(OperationRecord<I, O>& otherRecord);   
    };
}