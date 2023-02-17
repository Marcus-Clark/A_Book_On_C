/* Count the failing grades. */

#include "cl_info.h"

int fail(struct student class[])
{
   int   i, cnt = 0;

   for (i = 0; i < CLASS_SIZE; ++i)
      cnt += class[i].grade == 'F';
   return cnt;
}
