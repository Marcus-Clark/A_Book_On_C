#include "prn_cards.h"

void assign_values(card *c_ptr, int p, cdhs s)
{
   c_ptr -> pips = p;
   c_ptr -> suit = s;
}

void choose_hand(card deck[], card hand[])
{
   int      i;
   int      val;
   no_yes   used[52];

   for (i = 0; i < 52; ++i)
      used[i] = no;
   for (i = 0; i < 5; ++i) {
      do {
         val = rand() % 52;
      } while (used[val] == yes);
      hand[i] = deck[val];
      used[val] = yes;
   }
}

void create_deck(card deck[])
{
   int    i;

   for (i = 0; i < 13; ++i) {
      assign_values(deck + i,      i + 1, clubs);
      assign_values(deck + i + 13, i + 1, diamonds);
      assign_values(deck + i + 26, i + 1, hearts);
      assign_values(deck + i + 39, i + 1, spades);
   }
}

void extract_values(struct card *c_ptr, int *p_ptr, cdhs *s_ptr)
{
   *p_ptr = c_ptr -> pips;
   *s_ptr = c_ptr -> suit;
}
