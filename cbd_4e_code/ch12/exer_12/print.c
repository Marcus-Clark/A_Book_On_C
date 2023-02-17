#include "list.h"

void prn_data(data *p)
{
   printf("   %-13s%3d%10d\n",
      p -> name, p -> age, p -> weight);
}

void prn_heading(void)
{
   printf("\n   %-13s%3s%10s\n\n",
      "Name", "Age", "Weight");
}
