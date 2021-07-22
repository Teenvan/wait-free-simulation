#include "wait_free_queue.h"
#include "help.h"
#include <memory>

namespace WaitFreeSimulation
{
    std::shared_ptr<OperationRecord> WaitFreeQueue::peek() const {
        return std::make_shared<OperationRecord>(0);
    }

    bool WaitFreeQueue::tryRemoveFront(OperationRecord& completed) {
        // Returns true if succeeded else false
        return false;
    }
}