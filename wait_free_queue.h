#pragma once

// A Wait-free queue that is required for the 
// helper tasks

#include <string>
#include "help.h"

namespace WaitFreeSimulation
{
    class WaitFreeQueue
    {
        public:
            // Add takes in a description of help
            void add(Help& help);
            std::shared_ptr<Help> peek() const;
            void tryRemoveFront(Help completed);
    };
}