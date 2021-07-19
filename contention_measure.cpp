#include "contention_measure.h"

namespace WaitFreeSimulation{
    ContentionMeasure::ContentionMeasure()
    : countContention {0} 
    {}

    void ContentionMeasure::detected()
    {
        ++countContention;
    }
}