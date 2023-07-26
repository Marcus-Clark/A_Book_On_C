#include <assert.h>
#include <stdio.h>

typedef   double   dbl;

extern int         cnt;
extern const dbl   eps;            /* epsilon, a small quantity */

dbl   bisection(dbl f(dbl x), dbl a, dbl b);
dbl   f(dbl x);
