#include <stdio.h>

int main(void)
{
   int   i = 7, j = 7;

   if (i == 1)
      if (j == 2)
         printf("\n%d\n", i = i + j);
   else
      printf("\n%d\n", i = i - j);
   printf("\n%d\n", i);
   printf("\n%s\n",
          "This code is not very easy to read.\n"
          "After you understand what is happening,\n"
          "you should rewrite the code.\n");
   return 0;
}
