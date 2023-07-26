/*
// Test the stack implementation by reversing a string.
*/

#include "stack.h"

int main(void)
{
   char    str[] = "My name is Joanna Kelley!";
   int     i;
   stack   s;

   initialize(&s);                             /* initialize the stack */
   printf(" In the string: %s\n", str);
   for (i = 0; str[i] != '\0'; ++i) {
      if (!full(&s))
         push(str[i], &s);                 /* push a char on the stack */
   }
   printf("From the stack: ");
   while (!empty(&s))
      putchar(pop(&s));                    /* pop a char off the stack */
   putchar('\n');
   return 0;
}
