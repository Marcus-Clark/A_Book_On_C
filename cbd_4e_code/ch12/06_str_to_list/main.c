#include "str_to_l.h"

int main(void)
{
   char   line[MAXLINE];
   int    cnt;
   elem   *hp;

   printf("%s",
      "\n"
      "This program creates a linked list of elements, where\n"
      "each element contains one of the characters obtained\n"
      "from a line typed in by the user.  A search for\n"
      "vowels is then made by running down the\n"
      "linked list.\n"
      "\n"
      "Input a line: ");
   
   fgets(line, MAXLINE, stdin);                          /* pick up the line */
   hp = string_to_list(line);                        /* create a linked list */
   cnt = count(hp);                             /* count elements in the list*/
   printf("\nNumber of elements: %d\n\n", cnt);
   find_vowels(hp);                               /* find vowels in the list */
   putchar('\n');
   return 0;
}
