#include "list.h"

void get_max_age_weight(int *max_age_ptr, int *max_weight_ptr)
{
   int   max_age;
   int   max_weight;

   printf("%s",
      "\n"
      "   ---\n"
      "   This program prints out a list of people whose age\n"
      "   is less than or equal to a maximum age and whose\n"
      "   weight is less than or equal to a maximum weight.\n"
      "\n"
      "   Input your desired max age and max weight: ");
   if (scanf("%d%d", &max_age, &max_weight) != 2) {
      printf("\nERROR: Maximum age and weight not found - bye!\n\n");
      exit(1);
   }
   /*
   // We need to get the values max_age and max_weight
   // back to the calling environment.
   */
   *max_age_ptr = max_age;
   *max_weight_ptr = max_weight;
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
