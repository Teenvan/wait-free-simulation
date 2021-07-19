#pragma once
// Base class for a NormalizedLockFree implementation
// of a Lock free data structure for eg.  LockFreeLinkedList

#include "cas_descriptor.h"
#include "contention_measure.h"
#include "operation.h"
#include "result.h"
#include <vector>

namespace WaitFreeSimulation
{
class NormalizedLockFree 
{
    using Cases = std::vector<CasDescriptor>;

    public:

        Cases generator(const Operation& op) const;
        void  wrapUp(const Cases& performed) const;
};
}