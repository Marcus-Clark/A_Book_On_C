/* Use bisection to solve the Kepler equation. */

#include "kepler.h"

int         cnt = 0;
const dbl   eps = 1e-15;           /* epsilon, a small quantity */
const dbl   e   = 0.5;         /* a parameter in the Kepler eqn */
const dbl   m   = 2.2;         /* a parameter in the Kepler eqn */

int main(void)
{
   dbl   a = -100.0;
   dbl   b = +100.0;
   dbl   root;

   assert(kepler(a) * kepler(b) <= 0.0);
   root = bisection(kepler, a, b);        /* recursive fct call */
   printf("%s%d\n%s% .15f\n%s% .15f\n",
      "No. of fct calls: ", cnt,
      "Approximate root: ", root,
      "  Function value: ", kepler(root));
   return 0;
}
