#include "poker.h"

int main(void)
{
   cdhs   suit;
   int    i, pips;
   card   deck[52];

   for (i = 0; i < 52; ++i) {
      pips = i % 13 + 1;
      if (i < 13)
       suit = clubs;
      else if (i < 26)
       suit = diamonds;
      else if (i < 39)
       suit = hearts;
      else
       suit = spades;
      deck[i] = assign_values(pips, suit);
   }
   for (i = 26; i < 39; ++i)       /* print out the hearts */
      wrt_card_values(&deck[i]);
   play_poker(deck);
   return 0;
}
