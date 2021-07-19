#pragma once
#include "help.h"
#include <_types/_uint32_t.h>
#include <algorithm>

namespace WaitFreeSimulation
{
    Help::Help(uint32_t current) 
    : completed {false},
    at {current}
    {}

}