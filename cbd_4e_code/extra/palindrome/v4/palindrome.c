#include "palindrome.h"

no_yes is_palindrome(cchr* p, cchr* q)
{
   if (p >= q)
      return yes;
   if (*p == *q)
      return is_palindrome(++p, --q);
   return no;
}
