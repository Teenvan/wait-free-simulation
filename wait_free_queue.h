#pragma once

// A Wait-free queue that is required for the 
// helper tasks

#include <string>
#include "operation_record.h"
#include "operation_record_box.h"

namespace WaitFreeSimulation
{
    template <class O>
    class WaitFreeQueue
    {
        public:
            // Add takes in a description of help
            void add(OperationRecordBox<O>* help);
            OperationRecordBox<O>* peek() const;
            bool tryRemoveFront(OperationRecordBox<O>* completed);
    };
}