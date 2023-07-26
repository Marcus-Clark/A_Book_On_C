#include "stack.h"

data get_top(const stack *p)
{ 
   return (p -> s[p -> top]);
}

no_yes is_empty(const stack *p)
{ 
   return ((no_yes) (p -> top == EMPTY));
}

no_yes is_full(const stack *p)
{ 
   return ((no_yes) (p -> top == FULL));
}

data pop(stack *p)
{ 
   return (p -> s[p -> top--]);
}

void push(data d, stack *p)
{ 
   p -> s[++(p -> top)] = d;
}

void reset(stack *p)
{
   p -> top = EMPTY;
}
