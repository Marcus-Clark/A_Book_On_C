#include "poker.h"

void wrt_card_values(card *c_ptr)
{
   int    pips = c_ptr -> pips;
   cdhs   suit = c_ptr -> suit;
   char   *suit_name;

   if (suit == clubs)
      suit_name = "clubs";
   else if (suit == diamonds)
      suit_name = "diamonds";
   else if (suit == hearts)
      suit_name = "hearts";
   else if (suit == spades)
      suit_name = "spades";
   printf("card: %2d of %s\n", pips, suit_name);
}
