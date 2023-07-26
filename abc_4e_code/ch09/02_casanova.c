#include <stdio.h>

struct student {
   char   *last_name;
   int    student_id;
   char   grade;
};

int main(void)
{
   struct student   tmp, *p = &tmp;

   tmp.grade = 'A';
   tmp.last_name = "Casanova";
   tmp.student_id = 910017;
   printf("%s%12s%12s\n%s%12d%12d\n%s%12c%12c\n\n",
      "---\n"
      "The information will be listed twice:\n"
      "\n"
      "Last name:", p -> last_name,  (*p).last_name,
      "Sudent ID:", p -> student_id, (*p).student_id,
      "    Grade:", p -> grade,      (*p).grade);
   return 0;
}
