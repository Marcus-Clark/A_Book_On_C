//
// The basic stack routines.
//

#include "stack.h"

stack::stack()                                                   // constructor
{
   s = new data [maxdata];                          // allocate space in memory
   top = empty;
}

no_yes stack::is_empty()
{ 
   return ((top == empty) ? yes : no);
}

no_yes stack::is_full()
{ 
   return ((top == full) ? yes : no);
}

data stack::get_top()
{ 
   return s[top];
}

data stack::pop()
{ 
   return s[top--];
}

void stack::push(data d)
{ 
   assert(is_full() == no);
   s[++top] = d;
}
