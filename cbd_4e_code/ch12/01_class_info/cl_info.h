#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define   CLASS        "chem_class"
#define   CLASS_SIZE   17
#define   MAXLINE      300
#define   MAXWORD      100

struct student {
   char   *last_name;
   int    student_id;
   char   grade;
};

int    fail(struct student class[]);
void   get_class_data(struct student class[]);
