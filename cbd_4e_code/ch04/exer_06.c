#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
   int   i, n, seed;

   seed = time(NULL);
   srand(seed);
   printf("\n%s",
      "Some randomly distributed "
      "integers will be printed.\n"
      "How many do you want to see?  ");
   .....
