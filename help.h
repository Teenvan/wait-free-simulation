#pragma once

#include <_types/_uint32_t.h>
#include <cstdint>
#include <atomic>
namespace WaitFreeSimulation
{
    class OperationRecord
    {
        public:
            std::atomic<bool> completed;
            std::atomic<uint32_t> at;
            OperationRecord(uint32_t current);      
    };
}