#pragma once
#include "operation_record.h"
#include <_types/_uint32_t.h>
#include <algorithm>

namespace WaitFreeSimulation
{
    template <class I, class O>
    OperationRecord<I, O>::OperationRecord(uint64_t current) 
    : completed(false),
    at(current)
    {}

    template <class I, class O>
    OperationRecord<I, O>::OperationRecord(OperationRecord<I, O>& otherRecord):
    completed(otherRecord.completed), at(otherRecord.at)
    {}

}