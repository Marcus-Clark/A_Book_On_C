/*
// A linked list implementation of a stack.
*/

#include <stdio.h>
#include <stdlib.h>

#define   EMPTY      0
#define   FULL       10000

typedef   char                 data;
typedef   enum {false, true}   boolean;

struct elem {                   /* an element on the stack */
   data          d;
   struct elem   *next;
};

typedef   struct elem   elem;

struct stack {
   int    cnt;                  /* a count of the elements */
   elem   *top;                 /* ptr to the top element */
};

typedef   struct stack   stack;

boolean   empty(const stack *stk);
boolean   full(const stack *stk);
void      initialize(stack *stk);
void      push(data d, stack *stk);
data      pop(stack *stk);
data      top(stack *stk);
