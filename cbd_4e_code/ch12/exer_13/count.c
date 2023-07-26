#include "count.h"

int count(elem *hp)
{
   if (hp == NULL)
      return 0;
   else
      return (1 + count(hp -> next));
}
