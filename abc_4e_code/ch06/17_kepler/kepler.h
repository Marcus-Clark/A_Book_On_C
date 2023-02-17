#include <assert.h>
#include <math.h>
#include <stdio.h>

typedef   double   dbl;

extern int         cnt;
extern const dbl   eps;            /* epsilon, a small quantity */
extern const dbl   e;          /* a parameter in the Kepler eqn */
extern const dbl   m;          /* a parameter in the Kepler eqn */

dbl   bisection(dbl f(dbl x), dbl a, dbl b);
dbl   kepler(dbl x);
