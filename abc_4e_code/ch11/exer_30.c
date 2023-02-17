#include <stdio.h>

int main(void)
{
   printf("Hello!\n");
   fclose(stdout);
   printf("Goodbye!\n");
   return 0;
}
