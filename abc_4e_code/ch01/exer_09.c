#include <stdio.h>

#define   BOTTOM_SPACE   "\n\n\n\n\n"
#define   HEIGHT         17
#define   OFFSET         "                 "     /* 17 blanks */
#define   TOP_SPACE      "\n\n\n\n\n"

int main(void)
{
   int   i;

   printf(TOP_SPACE);
   printf(OFFSET "IIIIIII\n");
   for (i = 0; i < HEIGHT; ++i)
      printf(OFFSET "  III\n");
   printf(OFFSET "IIIIIII\n");
   printf(BOTTOM_SPACE);
   return 0;
}
