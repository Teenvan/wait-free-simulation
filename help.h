#pragma once

#include <cstdint>

namespace WaitFreeSimulation
{   
    template<class O>
    class OperationRecord
    {
        public:
            bool completed;
            uint32_t at;
            uint32_t ownerTid; // Owner thread identifier
            O operation;
            
            OperationRecord(uint64_t current);
            // Copy constructor
            OperationRecord(OperationRecord<O>& otherRecord);   
    };
}