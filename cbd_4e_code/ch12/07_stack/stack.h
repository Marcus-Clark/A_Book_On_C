#include <stdio.h>
#include <stdlib.h>

#define   MAXDATA   1000
#define   MAXLINE   300

#define   EMPTY     -1
#define   FULL      (MAXDATA - 1)

typedef   char                    data;              /* keep the data simple */
typedef   const char              cchr;
typedef   enum no_yes {no, yes}   no_yes;

typedef struct stack {
   data   s[MAXDATA];
   int    top;
} stack;

data     get_top(const stack *p);
no_yes   is_empty(const stack *p);
no_yes   is_full(const stack *p);
data     pop(stack *p);
void     push(data d, stack *p);
void     reset(stack *p);
