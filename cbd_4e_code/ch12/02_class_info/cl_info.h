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

void   get_class_data(struct student class[]);
void   swap(struct student *p, struct student *q);
void   prn_class_data(struct student class[]);
