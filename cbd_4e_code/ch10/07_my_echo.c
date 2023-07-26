/* Echo the command line arguments in uppercase letters */

#include <ctype.h>
#include <stdio.h>

const int   maxstring = 100;

int main(int argc, char *argv[])
{
   char   copy[maxstring];
   char   *p;
   int    i;

   printf("\n   argc = %d\n\n", argc);
   for (i = 0; i < argc; ++i) {
      strcpy(copy, argv[i]);
      for (p = copy; *p != '\0'; ++p)
         *p = toupper(*p);
      printf("   argv[%d] = %s\n", i, copy);
   }
   putchar('\n');
   return 0;
}
