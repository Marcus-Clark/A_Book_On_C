#include "poker.h"

card assign_values(int pips, cdhs suit)
{
   card   c;

   c.pips = pips;
   c.suit = suit;
   return c;
}

void deal_the_cards(card deck[52], card hand[NPLAYERS][5])
{
   int   card_cnt = 0, i, j;

   for (j = 0; j < 5; ++j)
      for (i = 0; i < NPLAYERS; ++i)
         hand[i][j] = deck[card_cnt++];
}

no_yes is_flush(card h[5])
{
   int   i;

   for (i = 1; i < 5; ++i) {
      if (h[i].suit != h[0].suit)
         return no;
   }
   return yes;
}

void play_poker(card deck[52])
{
   int    flush_cnt = 0, hand_cnt = 0;
   int    i, j;
   card   hand[NPLAYERS][5];   /* each player dealt 5 cards */

   srand(time(NULL));      /* seed random-number generator */
   for (i = 0; i < NDEALS; ++i) {
      shuffle(deck);
      deal_the_cards(deck, hand);
      for (j = 0; j < NPLAYERS; ++j) {
         ++hand_cnt;
         if (is_flush(hand[j])) {
            ++flush_cnt;
            printf("%s%d\n%s%d\n%s%f\n\n",
               "      Hand number:  ", hand_cnt,
               "     Flush number:  ", flush_cnt,
               "Flush probability:  ", 
               (double) flush_cnt / hand_cnt);
         }
      }
   }
}

void shuffle(card deck[52])
{
   int   i, j;

   for (i = 0; i < 52; ++i) {
      j = rand() % 52;
      swap(&deck[i], &deck[j]);
   }
}
