#include "contention_measure.h"

namespace WaitFreeSimulation{
    ContentionMeasure::ContentionMeasure()
    : countContention(0) 
    {}

    std::optional<Contention> ContentionMeasure::detected()
    {
        ++countContention;
        if (countContention < THRESHOLD)
        {
            return std::nullopt;
        } else {
            return Contention();
        }
    }

    bool ContentionMeasure::use_slow_path() const 
    {
        return countContention > THRESHOLD;
    }
}