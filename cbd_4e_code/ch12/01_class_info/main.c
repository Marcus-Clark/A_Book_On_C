#include "cl_info.h"

int main(void)
{
   int              cnt;
   struct student   class[CLASS_SIZE];

   get_class_data(class);
   cnt = fail(class);
   printf("\n%s%d\n\n",
      "CHEMISTRY CLASS: Number of failing grades: ", cnt);
   return 0;
}
