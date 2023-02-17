#include "cl_info.h"

void swap(struct student *p, struct student *q)
{
   struct student   tmp;

   tmp = *p;
   *p = *q;
   *q = tmp;
}
