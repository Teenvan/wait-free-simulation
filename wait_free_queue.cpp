#include "wait_free_queue.h"
#include "operation_record.h"
#include <memory>

namespace WaitFreeSimulation
{
    template <class I, class O>
    std::shared_ptr<OperationRecord<I, O> > WaitFreeQueue<I, O>::peek() const {
        return std::make_shared<OperationRecord>(0);
    }

    template <class I, class O>
    bool WaitFreeQueue<I, O>::tryRemoveFront(OperationRecordBox<I, O>* completed) {
        // Returns true if succeeded else
        return false;
    }
}