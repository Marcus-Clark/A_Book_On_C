#include "bubble.h"

void swap(char& c1, char& c2)
{
   char   tmp;

   tmp = c1;
   c1 = c2;
   c2 = tmp;
}

void swap(no_yes& a1, no_yes& a2)
{
   no_yes   tmp;

   tmp = a1;
   a1 = a2;
   a2 = tmp;
}
