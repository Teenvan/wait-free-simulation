#pragma once

#include "operation_state.h"
#include <vector>
#include "input.h"
#include "output.h"
#include "cas_descriptor.h"
#include <cstdint>
#include <thread>

namespace WaitFreeSimulation
{   
    class OperationRecord
    {
        using Cases = std::vector<CasDescriptor>;

        public:
            bool completed;
            std::thread::id ownerTid; // Owner thread identifier
            Input input; // Object with operation and input parameters
            OperationState state;
            Output out;
            Cases casDescriptors;
            uint64_t failedIndex;

            OperationRecord(std::thread::id owner, Input& i,
            OperationState s, Cases cases, uint64_t failed);
            // Copy constructor
            OperationRecord(OperationRecord& otherRecord);

            bool isCompleted() const;
    };
}