/*
// This version allows white space to be
// typed between the initials on input.
*/

#include <stdio.h>

int main(void)
{
   char   first, middle, last;
   int    age;

   printf("Input your three initials and your age: ");
   scanf("%c %c %c%d", &first, &middle, &last, &age);
   printf("\nGreetings %c.%c.%c.  %s %d.\n", first,
      middle, last, "Next year your age will be", age + 1);
   return 0;
}
