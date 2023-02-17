#include "spouse.h"

void assign_values(husband *p, wife *q)
{
   strcpy(p -> name, "John");
   p -> age = 29;
   p -> spouse = q;
   strcpy(q -> name, "Mary");
   q -> age = 23;
   q -> spouse = p;
}

choice select_choice(cchr* answer)
{
   char   c;
   cchr   *p;

   for (p = answer; isspace(*p); ++p)
      ;
   if (*p == '\0')
      return error;
   c = *p;
   if (strcasecmp(answer, "J") == 0)
      return man;
   if (strcasecmp(answer, "M") == 0)
      return woman;
   if (strcasecmp(answer, "John") == 0)
      return man;
   if (strcasecmp(answer, "Mary") == 0)
      return woman;
   if (strcasecmp(answer, "all") == 0)
      return both;
   if (strcasecmp(answer, "both") == 0)
      return both;
   if (strcasecmp(answer, "neither") == 0)
      return neither;
   if (strcasecmp(answer, "none") == 0)
      return neither;
   return error;
}
