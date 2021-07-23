#pragma once
// Base class for a NormalizedLockFree implementation
// of a Lock free data structure for eg.  LockFreeLinkedList

#include "cas_descriptor.h"
#include "contention_measure.h"
#include "contention.h"
#include "input.h"
#include "output.h"
#include <vector>
#include <variant>

namespace WaitFreeSimulation
{
class NormalizedLockFree 
{
    using Cases = std::vector<CasDescriptor>;
    using WrapUpOutput = std::variant<Output, std::optional<Contention>>;
    using GeneratorOutput = std::variant<Cases, Contention>;

    public:

        GeneratorOutput generator(const Input& op, 
                                                ContentionMeasure& cm) const;
        // Wrap up takes in the outcome of the execution
        // Wrap runs regardless if execute succeeded or not
        WrapUpOutput wrapUp(const Cases& performed, 
                                                int executed, 
                                                ContentionMeasure& cm) const;
};
}