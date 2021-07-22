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
            void add(OperationRecord* help);
            std::shared_ptr<OperationRecord> peek() const;
            void tryRemoveFront(OperationRecord completed);
    };
}