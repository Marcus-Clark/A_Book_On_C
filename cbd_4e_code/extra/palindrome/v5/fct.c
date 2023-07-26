#include "palindrome.h"

no_yes is_palindrome(cchr* word)
{
   cchr*   p;
   cchr*   q;
   int     n;

   n = strlen(word);
   for (p = word, q = word + n - 1; p < q; ++p, --q) {
      if (tolower(*p) != tolower(*q))
         return no;
   }
   return yes;
}

no_yes is_valid(cchr* word)
{
   cchr*   p;

   for (p = word; *p != '\0'; ++p) {
      if (isalpha(*p))
         return yes;
   }
   return no;
}

cchr* report(off_on val)
{
   return ((val == off) ? "off" : "on");
}
