/*
// An implementation of type stack.
*/

#include "stack.h"

void reset(stack *stk)
{
   stk -> top = EMPTY;
}

void push(char c, stack *stk)
{
   stk -> top++;
   stk -> s[stk -> top] = c;
}

char pop(stack *stk)
{
   return (stk -> s[stk -> top--]);
}

char top(const stack *stk)
{
   return (stk -> s[stk -> top]);
}

boolean empty(const stack *stk)
{
   return ((boolean) (stk -> top == EMPTY));
}

boolean full(const stack *stk)
{
   return ((boolean) (stk -> top == FULL));
}
