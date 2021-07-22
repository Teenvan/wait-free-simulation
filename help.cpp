#pragma once
#include "help.h"
#include <_types/_uint32_t.h>
#include <algorithm>

namespace WaitFreeSimulation
{
    template <class O>
    OperationRecord<O>::OperationRecord(uint64_t current) 
    : completed(false),
    at(current)
    {}

    template <class O>
    OperationRecord<O>::OperationRecord(OperationRecord<O>& otherRecord):
    completed(otherRecord.completed), at(otherRecord.at)
    {}

}