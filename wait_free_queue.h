#pragma once

// A Wait-free queue that is required for the 
// helper tasks

#include "operation_record.h"
#include "operation_record_box.h"

namespace WaitFreeSimulation
{
    class WaitFreeQueue
    {
        public:
            // Add takes in a description of help
            void add(OperationRecordBox* help);
            OperationRecordBox* peek() const;
            bool tryRemoveFront(OperationRecordBox* completed);
    };
}