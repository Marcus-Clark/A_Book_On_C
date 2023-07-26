#include <stdio.h>

int main(void)
{
   double   x = 1e+33, y = 0.001;

   if (x + y > x - y)
      printf("\n"
             "According to your machine, the expression\n"
             "\n"
             "   x + y > x - y\n"
             "\n"
             "is true.\n"
             "\n");
   else
      printf("\n"
             "According to your machine, the expression\n"
             "\n"
             "   x + y > x - y\n"
             "\n"
             "is false.\n"
             "\n");

   printf("%s\n",
          "What happens if you run this code\n"
          "on another machine?\n"
          "\n");
   return 0;
}
