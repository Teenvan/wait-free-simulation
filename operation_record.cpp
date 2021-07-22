#include "operation_record.h"
#include <_types/_uint32_t.h>
#include <algorithm>

namespace WaitFreeSimulation
{
    OperationRecord::OperationRecord(uint64_t current) 
    : completed(false),
    at(current)
    {}

    OperationRecord::OperationRecord(OperationRecord& otherRecord):
    completed(otherRecord.completed), at(otherRecord.at)
    {}

}