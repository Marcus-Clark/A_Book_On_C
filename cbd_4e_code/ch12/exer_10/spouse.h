#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   MAXSTRING   100

enum choice {man, woman, both, neither, error};

struct husband;
struct wife;

typedef   enum choice      choice;
typedef   const char       cchr;
typedef   struct husband   husband;
typedef   struct wife      wife;

struct husband {
   char   name[10];
   int    age;
   wife   *spouse;
};

struct wife {
   char      name[10];
   int       age;
   husband   *spouse;
};

void     assign_values(husband *p, wife *q);
choice   select_choice(cchr* answer);
void     prn_husband(husband *p);
void     prn_wife(wife *p);
