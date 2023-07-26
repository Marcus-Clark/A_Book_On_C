#include <stdio.h>
#include <stdlib.h>                           /* for abort() */

#if defined(NDEBUG)
   #define   assert(ignore)   ((void) 0)      /* ignore it */
#else
   #define   assert(expr)                \
      if (!(expr)) {                     \
       printf("\n%s%s\n%s%s\n%s%d\n\n",  \
          "Assertion failed: ", #expr,   \
          "in file ", __FILE__,          \
          "at line ", __LINE__);         \
       abort();                          \
      }
#endif

int main(void)
{
   assert(1 > 2);
   return 0;
}
