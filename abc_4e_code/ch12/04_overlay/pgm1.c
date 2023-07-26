#include <stdio.h>

int main(int argc, char **argv)
{
   int   i;

   printf("%s: ", argv[0]);
   for (i = 1; i < argc; ++i)                    /* print the arg list */
      printf("%s ", argv[i]);
   printf("\n\n");
   return 0;
}
