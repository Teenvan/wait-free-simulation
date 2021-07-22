#include "contention_measure.h"

namespace WaitFreeSimulation{
    ContentionMeasure::ContentionMeasure()
    : countContention(0) 
    {}

    void ContentionMeasure::detected()
    {
        ++countContention;
    }

    bool ContentionMeasure::use_slow_path() const 
    {
        return countContention > THRESHOLD;
    }
}