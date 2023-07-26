#include "prn_cards.h"

void prn_card(card *c_ptr)
{
   char   *s;
   int    pips;
   cdhs   suit;

   extract_values(c_ptr, &pips, &suit);
   switch (suit) {
   case clubs :
      s = "clubs";
      break;
   case diamonds :
      s = "diamonds";
      break;
   case hearts :
      s = "hearts";
      break;
   case spades :
      s = "spades";
      break;
   default:
      s = "error";
   }
   printf("   card:%3d of %s\n", pips, s);
}

void prn_deck(card deck[])
{
   int   i;

   for (i = 0; i < 52; ++i)
      prn_card(&deck[i]);
}

void prn_hand(card hand[])
{
   int   i;

   for (i = 0; i < 5; ++i)
      prn_card(&hand[i]);
}

void prn_hearts(card deck[])
{
   int   i;

   for (i = 0; i < 13; ++i)           /* print out the hearts */
      prn_card(deck + i + 26);
}
