#include "shift.h"

void shift(char& c1, char& c2, char& c3, char& c4, char& c5)
{
   char   tmp;

   tmp = c1;
   c1 = c2;
   c2 = c3;
   c3 = c4;
   c4 = c5;
   c5 = tmp;
}
