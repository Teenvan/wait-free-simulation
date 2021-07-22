#include "normalized_lock_free.h"
    
namespace WaitFreeSimulation
{
    NormalizedLockFree::Cases NormalizedLockFree::generator(const Operation& op, ContentionMeasure& cm) const
    {
        return ;
    }

    int NormalizedLockFree::wrapUp(const Cases& performed, int executed, ContentionMeasure& cm) const
    {
        // Do something
        return 0;
    }
}