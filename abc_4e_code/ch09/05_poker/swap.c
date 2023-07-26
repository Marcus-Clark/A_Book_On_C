#include "poker.h"

void swap(card *p, card *q)
{
   card   tmp;

   tmp = *p;
   *p = *q;
   *q = tmp;
}
