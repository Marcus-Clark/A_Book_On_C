/*
// In ANSI C, you are not supposed to be able to
// overwrite string constants.  Even if you can,
// you should refrain from doing so.
*/

#include <stdio.h>

int main(void)
{
   char   *p, *q;

   printf("%s\n",
      "---\n"
      "Note: If you get a core dump, read the READ_ME\n"
      "      file in the directory exer_06.\n");

   p = q = " RICH";
   printf("C. B. DeMogul is%s%s%s!\n", p, p, p);
   *++q = 'p';
   *++q = 'o';
   *++q = 'o';
   *++q = 'r';
   printf("C. B. DeMogul is%s%s%s!\n", p, p, p);
   return 0;
}
