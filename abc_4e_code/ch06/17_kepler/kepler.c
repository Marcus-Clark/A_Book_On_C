#include "kepler.h"

dbl kepler(dbl x)
{
   return (x - e * sin(x) - m);
}
