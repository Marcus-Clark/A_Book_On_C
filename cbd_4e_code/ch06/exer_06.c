/*
// Experiment with integer overflow.
*/

#include <stdio.h>

#define   BIG   2000000000     /* 2 billion is big? */

int main(void)
{
   int        i = BIG + BIG;
   unsigned   u = BIG + BIG;

   printf("\n%s%d\n%s%d\n%s%u\n%s%u\n\n",
      "---\n"
      "Possible integer overflow:\n"
      "\n"
      "   i with %d format is ", i,
      "   u with %d format is ", u,
      "   i with %u format is ", i,
      "   u with %u format is ", u);
   return 0;
}
