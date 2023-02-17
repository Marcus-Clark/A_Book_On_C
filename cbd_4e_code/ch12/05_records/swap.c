#include "st_data.h"

void swap(student_data *p, student_data *q)
{
   student_data   tmp;

   tmp = *p;
   *p = *q;
   *q = tmp;
}
