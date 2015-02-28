#include <math.h>
#include "Table.h"

double mysqrt(double value)
{
    // if we have both log and exp then use them
    #if defined (HAVE_LOG) && defined (HAVE_EXP)
        return exp(log(value)*0.5);
    #else // otherwise use an iterative approach
        return value < 10 && value >= 0 ? sqrtTable[static_cast<int>(value)] : sqrt(value);
    #endif
}