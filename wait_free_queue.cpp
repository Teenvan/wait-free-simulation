#include "wait_free_queue.h"
#include "help.h"
#include <memory>

namespace WaitFreeSimulation
{
    std::shared_ptr<Help> WaitFreeQueue::peek() const {
        return std::make_shared<Help>(0);
    }

}