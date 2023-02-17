#include <stdio.h>

int main(int argc, char **argv)
{
   int   i, sum = 0, value;

   for (i = 0; i < argc; ++i)                     /* sum the arguments */
      if (sscanf(argv[i], "%d", &value) == 1)
         sum += value;
   printf("%s: sum of command line args = %d\n\n", argv[0], sum);
   return 0;
}
