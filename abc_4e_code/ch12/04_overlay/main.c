#include <stdio.h>
#include <unistd.h>                                     /* for execl() */

int main(void)
{
   int   choice = 0;

   printf("%s\n%s\n%s\n\n%s",
      "---",
      "The parent process will be overlaid.",
      "You have a choice.",
      "Input 1 or 2: ");
   scanf("%d", &choice);
   putchar('\n');
   if (choice == 1)
      execl("pgm1", "pgm1", "a", "b", "c", 0);
   if (choice == 2)
      execl("pgm2", "pgm2", "1", "2", "3", "go", 0);
   printf("ERROR: You did not input 1 or 2.\n\n");
   return 0;
}
