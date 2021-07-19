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
    typedef std::vector<CasDescriptor> Cases;

    public:

        Cases prepare(Operation& op);
        int   execute(const Cases& c, ContentionMeasure& cm);
        void  cleanup();
};
}