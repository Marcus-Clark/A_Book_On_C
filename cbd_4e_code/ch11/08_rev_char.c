/*
// Reverse the characters between s[j] and s[k] recursively.
*/

void   reverse(char *s, int j, int k);
void   swap(char *p, char *q);

#include <stdio.h>

int main(void)
{
   char   phrase[] = "by the sea, by the beautiful sea";

   reverse(phrase, 3, 17);
   printf("%s\n", phrase);
   return 0;
}

void reverse(char *s, int j, int k)
{
   if (j < k) {
      swap(&s[j], &s[k]);
      reverse(s, ++j, --k);
   }
}

void swap(char *p, char *q)
{
   char   tmp;

   tmp = *p;
   *p = *q;
   *q = tmp;
}
