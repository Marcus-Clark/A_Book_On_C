#include "st_data.h"

void error_exit(cchr* msg)
{
   printf("\n%s%s%s\n\n", "ERROR: ", msg, " - bye!\n\n");
   exit(1);
}

no_yes is_blank(cchr *line)
{
   cchr   *p;

   for (p = line; isspace(*p); ++p)
      ;
   if (*p == '\0')
      return yes;
   return no;
}

no_yes is_comment(cchr *line)
{
   cchr   *p;

   for (p = line; isspace(*p); ++p)
      ;
   if (strncmp(p, "//", 2) == 0)
      return yes;
   return no;
}
