#include "wait_free_queue.h"
#include "operation_record.h"
#include <memory>

namespace WaitFreeSimulation
{
    template <class O>
    std::shared_ptr<OperationRecord<O>> WaitFreeQueue<O>::peek() const {
        return std::make_shared<OperationRecord>(0);
    }

    template <class O>
    bool WaitFreeQueue<O>::tryRemoveFront(OperationRecordBox<O>* completed) {
        // Returns true if succeeded else
        return false;
    }
}