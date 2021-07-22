#include "operation_record_box.h"

namespace WaitFreeSimulation
{
    OperationRecordBox::OperationRecordBox(OperationRecord* value)
    : v(value)
    {}

    // std::atomic<OperationRecord*>& OperationRecordBox::operationPointer() const
    // {
    //     return v;
    // }
}