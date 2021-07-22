#include "operation_record_box.h"

namespace WaitFreeSimulation
{
    template <class O>
    OperationRecordBox<O>::OperationRecordBox(OperationRecord<O>* value)
    : v(value)
    {}

    template <class O>
    std::atomic<OperationRecord<O>*> OperationRecordBox<O>::operationPointer() const
    {
        return v;
    }
}