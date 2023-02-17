/*
// Operations on complex numbers.
*/

#include "complex.h"

void add(complex *a, complex *b, complex *c)       /* a = b + c */
{
   a -> re = b -> re + c -> re;
   a -> im = b -> im + c -> im;
}

void mult(complex *a, complex *b, complex *c)       /* a = b * c */
{
   a -> re = (b -> re) * (c -> re) - (b -> im) * (c -> im);
   a -> im = (b -> re) * (c -> im) + (b -> im) * (c -> re);
}
