#include "polish.h"

int main(void)
{
   char    *str[3];
   int     i;
   stack   polish;

   str[0] = "7, 6, -, 3, *";
   str[1] = "9, 2, 3, *, 4, -, +";
   str[2] = "1, 2, +, 3, 4, +, *";

   printf("%s\n",
      "---\n"
      "WARNING:\n"
      "   Some of the results are wrong.\n"
      "   See exercise 20 on page 488 of ABC 4/e.\n");
   for (i = 0; i < 3; ++i) {
      printf("%s%s\n\n",
         "---\n"
         "Polish expression: ", str[i]);
      fill(&polish, str[i]);             /* fill stack from the string */
      wrt_stack(&polish);               /* wrt the stack on the screen */
      printf("\n%s%d\n\n",
         "Polish evaluation: ", evaluate(&polish));
   }
   return 0;
}
