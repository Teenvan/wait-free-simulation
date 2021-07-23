#include "operation_record.h"
#include <_types/_uint32_t.h>
#include <algorithm>

namespace WaitFreeSimulation
{
    OperationRecord::OperationRecord(std::thread::id owner, Input& i,
            OperationState s, Cases cases, uint64_t failed) 
    : ownerTid(owner),
    input(i),
    state(s),
    casDescriptors(std::move(cases)),
    completed(false),
    failedIndex(failed)
    {}

    OperationRecord::OperationRecord(OperationRecord& otherRecord)
    : ownerTid(otherRecord.ownerTid),
    input(otherRecord.input),
    state(otherRecord.state),
    casDescriptors(otherRecord.casDescriptors),
    completed(otherRecord.completed),
    failedIndex(otherRecord.failedIndex)
    {}

    bool OperationRecord::isCompleted() const
    {
        if (state == OperationState::Completed)
        {
            return true;
        }
        return false;
    }

}