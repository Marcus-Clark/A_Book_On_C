/* Echo the command line arguments. */

#include <stdio.h>

int main(int argc, char *argv[])
{
   int   i;

   printf("\n   argc = %d\n\n", argc);
   for (i = 0; i < argc; ++i)
      printf("   argv[%d] = %s\n", i, argv[i]);
   putchar('\n');
   return 0;
}
