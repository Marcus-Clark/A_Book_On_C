#include "spouse.h"

void prn_husband(husband *p)
{
   printf("%s%s\n%s%2d\n%s%s\n\n",
      "     Name: ", p -> name,
      "      Age: ", p -> age,
      "   Spouse: ", p -> spouse -> name);
}

void prn_wife(wife *p)
{
   printf("%s%s\n%s%2d\n%s%s\n\n",
      "     Name: ", p -> name,
      "      Age: ", p -> age,
      "   Spouse: ", p -> spouse -> name);
}
