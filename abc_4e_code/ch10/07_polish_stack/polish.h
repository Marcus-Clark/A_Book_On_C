/* A linked list implementation of a Polish stack. */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define   EMPTY      0
#define   FULL       10000

enum boolean  {false, true};
enum oper_val {operator, value};

union u_op_val {
   char   op;
   int    val;
};

typedef   const char       cchr;
typedef   enum boolean     boolean;
typedef   enum oper_val    oper_val;
typedef   union u_op_val   u_op_val;

struct data {
   oper_val   kind;
   u_op_val   u;
};

typedef   struct data   data;

struct elem {                   /* an element on the stack */
   data          d;
   struct elem   *next;
};

typedef   struct elem    elem;

struct stack {
   int    cnt;                  /* a count of the elements */
   elem   *top;                 /* ptr to the top element */
};

typedef   struct stack   stack;

/*
// Function prototypes.
*/

boolean   empty(const stack *stk);
int       evaluate(stack *polish);
void      fill(stack *stk, cchr *str);
boolean   full(const stack *stk);
void      initialize(stack *stk);
data      pop(stack *stk);
void      wrt_data(data *dp);
void      wrt_stack(stack *stk);
void      push(data d, stack *stk);
data      top(stack *stk);
