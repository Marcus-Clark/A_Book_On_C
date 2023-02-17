#include "prn_hearts.h"

int main(void)
{
   int           i;
   struct card   deck[52];

   for (i = 0; i < 13; ++i) {
      assign_values(deck + i, i + 1, 'c');
      assign_values(deck + i + 13, i + 1, 'd');
      assign_values(deck + i + 26, i + 1, 'h');
      assign_values(deck + i + 39, i + 1, 's');
   }
   for (i = 0; i < 13; ++i)           /* print out the hearts */
      prn_values(deck + i + 26);
   return 0;
}
