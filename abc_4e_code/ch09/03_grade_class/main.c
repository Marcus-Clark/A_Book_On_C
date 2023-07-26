#include "class_info.h"

int main(void)
{
   int              cnt;
   int              i;
   struct student   tmp;
   struct student   class[CLASS_SIZE];

   tmp.grade = 'A';
   tmp.last_name = "Casanova";
   tmp.student_id = 910017;
   class[0] = tmp;
   tmp.grade = 'F';
   tmp.last_name = "Superman";
   tmp.student_id = 910018;
   class[1] = tmp;
   tmp.grade = 'C';
   tmp.last_name = "Wonderwoman";
   tmp.student_id = 910019;
   class[2] = tmp;
   /*
   // Enter nothing for the remainder of the class.
   */
   for (i = 3; i < CLASS_SIZE; ++i) {
      class[i].grade = ' ';
      class[i].last_name = "";
      class[i].student_id = 0;
   }
   cnt = fail(class);
   printf("Number of failing grades: %d\n", cnt);
   return 0;
}
