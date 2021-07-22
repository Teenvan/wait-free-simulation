#pragma once

// A Wait-free queue that is required for the 
// helper tasks

#include <string>
#include "help.h"
#include "operation_record_box.h"

namespace WaitFreeSimulation
{
    class WaitFreeQueue
    {
        public:
            // Add takes in a description of help
            void add(OperationRecordBox* help);
            std::shared_ptr<OperationRecord> peek() const;
            bool tryRemoveFront(OperationRecord& completed);
    };
}