#pragma once

#include <_types/_uint32_t.h>
#include <cstdint>
#include <atomic>
namespace WaitFreeSimulation
{
    class Help
    {
        public:
            std::atomic<bool> completed;
            std::atomic<uint32_t> at;
            Help(uint32_t current);      
    };
}