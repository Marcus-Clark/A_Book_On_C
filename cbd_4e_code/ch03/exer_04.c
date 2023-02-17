#include <stdio.h>

int main(void)
{
   int     a = 1, b = 2, c = 3;
   float   x = 3.3, y = 5.5;

   printf("%d %d\n", !  a+b/c, !a + b / c);
   printf("%d %d\n", a == -b + c, a * b > c == a);
   printf("%d %d\n", !!x < a + b + c, !!x + !!!y);
   printf("%d %d\n", a || b == x && y, !(x || !y));
   printf("\n%s\n\n",
      "What happens if all the blanks are removed\n"
      "from everywhere within this program?\n"
      "\n"
      "If the program will not compile when all the\n"
      "blanks are removed, what is the minimum\n"
      "number of blanks needed?\n"
      "\n"
      "Do the blanks, or lack of them, effect the\n"
      "values of the logical expressions?");
   return 0;
}
