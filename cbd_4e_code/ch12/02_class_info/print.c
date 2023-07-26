#include "cl_info.h"

void prn_class_data(struct student class[])
{
   int   i;
   int   j;
   int   n = CLASS_SIZE;

   for (i = 0; i < n; ++i)
      for (j = i + 1; j < n; ++j)
         if (class[i].grade > class[j].grade)
            swap(&class[i], &class[j]);

   for (i = 0; i < n; ++i)
      printf("%11s:%3c\n",
         class[i].last_name, class[i].grade);
}
