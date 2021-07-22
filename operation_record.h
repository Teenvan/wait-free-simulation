#pragma once

#include "operation_state.h"
#include <vector>
#include "input.h"
#include "output.h"
#include "cas_descriptor.h"
#include <cstdint>

namespace WaitFreeSimulation
{   
    class OperationRecord
    {
        using Cases = std::vector<CasDescriptor>;

        public:
            bool completed;
            uint32_t at;
            uint32_t ownerTid; // Owner thread identifier
            Input input; // Object with operation and input parameters
            OperationState state;
            Output out;
            Cases casDescriptors;

            OperationRecord(uint64_t current);
            // Copy constructor
            OperationRecord(OperationRecord& otherRecord);   
    };
}