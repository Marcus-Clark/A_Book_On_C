#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   CLASS_SIZE     17
#define   MAXLINE        300
#define   MAXMONTH       4
#define   MAXNAME        30
#define   MAXWORD        100
#define   NCOURSES       2             /* number of courses */

#define   BIRTHDAYS      "birthdays"
#define   GRADES         "grades"

typedef   const char    cchr;

enum no_yes {no, yes};

typedef   enum no_yes   no_yes;

struct date {
   short   day;
   char    month[MAXMONTH];
   short   year;
};

typedef   struct date   date;

struct personal {
   char   name[MAXNAME];
   date   birthday;
};

typedef   struct personal   personal;

struct student_data {
   personal   p;
   int        student_id;
   char       grade[NCOURSES];
};

typedef   struct student_data   student_data;

void     error_exit(cchr* msg);
void     get_student_data(student_data sd[]);
no_yes   is_blank(cchr *line);
no_yes   is_comment(cchr *line);
void     swap(student_data *p, student_data *q);
void     wrt_student_data(student_data sd[]);
