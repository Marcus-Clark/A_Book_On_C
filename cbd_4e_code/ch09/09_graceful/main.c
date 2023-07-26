#include "try_me.h"

int main(void)
{
   char   answer;
   int    *a;
   int    n = 4000000000U;     /* unsigned */

   printf("%s",
      "Arrays can be large, but not super large.\n"
      "\n"
      "Would you like to try to allocate space\n"
      "for an array of integers of size 4 billion?  ");
   scanf(" %c", &answer);
   if (answer == 'y' || answer == 'Y') {
      a = gcalloc(n, sizeof(int));
      printf("\n"
             "You got one!\n"
             "Now you should write some code that uses the array!\n"
             "\n");
   }
   else
      printf("\nBye!\n\n");
   return 0;
}
