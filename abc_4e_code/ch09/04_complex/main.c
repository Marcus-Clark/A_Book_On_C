#include "complex.h"

int main(void)
{
   complex   a, b, z, w;

   printf("%s",
      "---\n"
      "Complex arithemtic will be performed\n"
      "on a and b, two complex numbers.\n"
      "\n");
   for ( ; ; ) {
      printf("Input a and b: ");
      if (get_from_user(&a, &b) == no)
         break;
      putchar('\n');
      add(&z, &a, &b);          /* z = a + b */
      mult(&w, &a, &b);         /* w = a * b */
      wrt("a", a);
      wrt("b", b);
      putchar('\n');
      wrt("a + b", z);
      wrt("a * b", w);
      putchar('\n');
   }
   printf("\nBye!\n\n");
   return 0;
}
