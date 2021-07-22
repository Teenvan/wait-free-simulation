#pragma once

#include <cstdint>

namespace WaitFreeSimulation
{
    class OperationRecord
    {
        public:
            bool completed;
            uint32_t at;
            OperationRecord(uint32_t current);
            // Copy constructor
            OperationRecord(OperationRecord& otherRecord);   
    };
}