#include "try_me.h"

int greater(char& a, char& b)
{
   if (a > b) {        // exchange
      char  tmp = a;
      a = b;
      b = tmp;
      return 1;
   }
   else
      return 0;
}
