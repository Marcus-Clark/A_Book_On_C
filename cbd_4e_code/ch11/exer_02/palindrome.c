#include "palindrome.h"

no_yes is_palindrome(cchr* word)
{
   cchr*   p;
   cchr*   q;

   p = word;
   q = word + strlen(word) - 1;
   for ( ; p < q; ++p, --q)
      if (*p != *q)
         return no;
   return yes;
}
