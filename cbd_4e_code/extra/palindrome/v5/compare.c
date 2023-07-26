#include "palindrome.h"

int compare(const void* vp, const void* vq)
{
   cchr*   p = *((cchr**) vp);
   cchr*   q = *((cchr**) vq);

   return strcmp(p, q);
}
