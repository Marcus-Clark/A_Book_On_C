#include "complex.h"

cchr *skip_number(cchr *p)
{
   no_yes   found_decimal_point = no;

   assert(!isspace(*p));
   if (*p == '+' || *p == '-')
      ++p;
   if (*p == '.') {
      found_decimal_point = yes;
      ++p;
   }
   while (isdigit(*p))
      ++p;
   if (found_decimal_point == no && *p == '.') {
      ++p;
      while (isdigit(*p))
         ++p;
   }
   if (*p == 'e' || *p == 'E') {
      ++p;
      if (*p == '+' || *p == '-')
         ++p;
      while (isdigit(*p))
         ++p;
   }
   return p;
}
