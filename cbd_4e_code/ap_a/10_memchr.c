/*
// Does memchr() care about \0?
*/

#include <stdio.h>
#include <string.h>

#define   MAXSTRING   100

int main(void)
{
   char   s[MAXSTRING];
   char   *p;

   sprintf(s, "ab%ccba", '\0');
   p = memchr(s, 'c', 10);
   printf("\np = \"%s\"\n\n", p);
   return 0;
}
