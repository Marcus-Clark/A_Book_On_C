#include <stdio.h>

#define   MAX_LEN    1000
#define   EMPTY      -1
#define   FULL       (MAX_LEN - 1)

typedef   enum boolean {false, true}   boolean;

typedef struct stack {
   char   s[MAX_LEN];
   int    top;
} stack;

void      reset(stack *stk);
void      push(char c, stack *stk);
char      pop(stack *stk);
char      top(const stack *stk);
boolean   empty(const stack *stk);
boolean   full(const stack *stk);
