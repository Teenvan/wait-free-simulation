#include "wait_free_queue.h"
#include "operation_record.h"
#include <memory>

namespace WaitFreeSimulation
{
    std::shared_ptr<OperationRecord> WaitFreeQueue::peek() const {
        return std::make_shared<OperationRecord>(0);
    }

    bool WaitFreeQueue::tryRemoveFront(OperationRecordBox* completed) {
        // Returns true if succeeded else
        return false;
    }
}