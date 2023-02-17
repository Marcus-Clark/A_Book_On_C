#include "st_data.h"

void wrt_student_data(student_data sd[])
{
   int   i;
   int   j;
   int   n = CLASS_SIZE;

   for (i = 0; i < n; ++i)
      for (j = i + 1; j < n; ++j)
         if (sd[i].student_id > sd[j].student_id)
            swap(&sd[i], &sd[j]);

   for (i = 0; i < n; ++i)
      printf("%11s:%7d%5hd%4s%3hd%5c%5c\n",
         sd[i].p.name, sd[i].student_id,
         sd[i].p.birthday.day, sd[i].p.birthday.month, sd[i].p.birthday.year,
         sd[i].grade[0], sd[i].grade[1]);
}
