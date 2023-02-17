#include "cl_info.h"

int main(void)
{
   struct student   class[CLASS_SIZE];

   get_class_data(class);
   prn_class_data(class);
   return 0;
}
