#include "wait_free_queue.h"
#include "operation_record.h"
#include <memory>

namespace WaitFreeSimulation
{
    OperationRecordBox* WaitFreeQueue::peek() const {
        return nullptr;
    }

    bool WaitFreeQueue::tryRemoveFront(OperationRecordBox* completed) {
        // Returns true if succeeded else
        return false;
    }

    void WaitFreeQueue::add(OperationRecordBox* record)
    {
        // Do something here.
    }
}