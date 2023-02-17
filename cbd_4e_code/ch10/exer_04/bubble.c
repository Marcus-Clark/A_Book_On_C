#include "bubble.h"

void bubble_str(char* s)
{
   char*     p;
   int       i;
   int       j;
   int       n;
   no_yes*   a;

   n = strlen(s);
   a = new no_yes [n];
   for (i = 0; i < n; ++i) {
      if (isupper(s[i]))
         a[i] = yes;
      else
         a[i] = no;
   }
   for (p = s; *p != '\0'; ++p)
      *p = tolower(*p);
   for (i = 0; i < n - 1; ++i) {
      for (j = n - 1; i < j; --j) {
         if (s[j-1] > s[j]) {
            swap(s[j-1], s[j]);
            swap(a[j-1], a[j]);
         }
      }
   }
   for (i = 0; i < n; ++i)
      if (a[i] == yes)
         s[i] = toupper(s[i]);
}
