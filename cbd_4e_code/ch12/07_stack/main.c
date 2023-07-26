/*
// Test the stack implementation by reversing a string.
*/

#include "stack.h"

int main(void)
{
   char    line[MAXLINE];
   int     i;
   stack   stk;

   printf("%s",
      "\n"
      "   This program uses stack operations to reverse the\n"
      "   characters in a line entered at the keyboard.\n"
      "\n"
      "     Input a line: ");
   gets(line);                                           /* pick up the line */
   reset(&stk);
   for (i = 0; line[i] != '\0'; ++i) {
      if (is_full(&stk) == yes) {
         printf("\n   OVERFLOW: The stack is full - bye!\n\n");
         exit(1);
      }
      push(line[i], &stk);                         /* push data on the stack */
   }
   printf("   From the stack: ");
   while (is_empty(&stk) == no)
      putchar(pop(&stk));                          /* pop data off the stack */
   printf("\n\n");
   return 0;
}
