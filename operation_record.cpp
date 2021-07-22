#include "operation_record.h"
#include <_types/_uint32_t.h>
#include <algorithm>

namespace WaitFreeSimulation
{
    OperationRecord::OperationRecord(std::thread::id owner, Input& i,
            OperationState& s, Cases cases) 
    : ownerTid(owner),
    input(i),
    state(s),
    casDescriptors(std::move(cases))
    {}

    OperationRecord::OperationRecord(OperationRecord& otherRecord)
    : ownerTid(otherRecord.ownerTid),
    input(otherRecord.input),
    state(otherRecord.state),
    casDescriptors(std::move(otherRecord.casDescriptors))
    {}

}