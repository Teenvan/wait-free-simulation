#pragma once

// A Wait-free queue that is required for the 
// helper tasks

#include <string>
#include "operation_record.h"
#include "operation_record_box.h"

namespace WaitFreeSimulation
{
    template <class I, class O>
    class WaitFreeQueue
    {
        public:
            // Add takes in a description of help
            void add(OperationRecordBox<I, O>* help);
            OperationRecordBox<I, O>* peek() const;
            bool tryRemoveFront(OperationRecordBox<I, O>* completed);
    };
}