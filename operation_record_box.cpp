#include "operation_record_box.h"

namespace WaitFreeSimulation
{
    template <class I, class O>
    OperationRecordBox<I, O>::OperationRecordBox(OperationRecord<I, O>* value)
    : v(value)
    {}

    template <class I, class O>
    std::atomic<OperationRecord<I, O>*> OperationRecordBox<I, O>::operationPointer() const
    {
        return v;
    }
}