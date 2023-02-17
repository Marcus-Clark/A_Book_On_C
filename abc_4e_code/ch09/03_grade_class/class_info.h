#include <stdio.h>

#define   CLASS_SIZE   100

struct student {
   char   *last_name;
   int    student_id;
   char   grade;
};

int   fail(struct student class[]);
