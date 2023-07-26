#include "st_data.h"

int main(void)
{
   student_data   sd[CLASS_SIZE];

   get_student_data(sd);
   wrt_student_data(sd);
   return 0;
}
