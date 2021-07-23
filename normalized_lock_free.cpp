#include "normalized_lock_free.h"
    
namespace WaitFreeSimulation
{
    std::variant<NormalizedLockFree::Cases, Contention> 
                NormalizedLockFree::generator
                (const Input& op, ContentionMeasure& cm) const
    {
        return ;
    }

    int NormalizedLockFree::wrapUp(const Cases& performed, int executed, ContentionMeasure& cm) const
    {
        // Do something
        return 0;
    }
}