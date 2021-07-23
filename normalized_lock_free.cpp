#include "normalized_lock_free.h"
    
namespace WaitFreeSimulation
{
    NormalizedLockFree::GeneratorOutput 
                NormalizedLockFree::generator
                (const Input& op, ContentionMeasure& cm) const
    {
        return ;
    }

    NormalizedLockFree::WrapUpOutput 
                NormalizedLockFree::wrapUp(const Cases& performed, 
                                           int executed, 
                                           ContentionMeasure& cm) const
    {
        // Do something
        return;
    }
}