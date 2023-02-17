#include <stdio.h>

int main(int argc, char *argv[], char *env[])
{
   int   i;

   printf("\n%s\n\n",
      "---\n"
      "Getting the environment variables via the 3rd arg to main():");

   fflush(stdout);
   for (i = 0; env[i] != NULL; ++i)
      printf("%s\n", env[i]);

   return 0;
}
