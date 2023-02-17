#include "prn_hearts.h"

void prn_values(struct card *c_ptr)
{
   char   *suit_name;
   int    p;            /* pips value */
   char   s;            /* suit value */

   extract_values(c_ptr, &p, &s);
   switch (s) {
   case 'c' :
      suit_name = "clubs";
      break;
   case 'd' :
      suit_name = "diamonds";
      break;
   case 'h' :
      suit_name = "hearts";
      break;
   case 's' :
      suit_name = "spades";
      break;
   default:
      suit_name = "error";
   }
   printf("   card:%3d of %s\n", p, suit_name);
}
