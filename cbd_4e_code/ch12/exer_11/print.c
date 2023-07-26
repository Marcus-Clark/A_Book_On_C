#include "list.h"

void prn_data(data *p)
{
   printf("%13s:%7d%9d\n",
      p -> name, p -> age, p -> weight);
}

void prn_heading(void)
{
   printf("\n%13s:%7s%9s\n\n",
      "Name", "Age", "Weight");
}
