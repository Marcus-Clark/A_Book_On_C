#include "prn_cards.h"

int main(void)
{
   card   deck[52];
   card   hand[5];

   srand(time(NULL));     /* seed the random number generator */
   create_deck(deck);
   printf("\n%s\n%s\n\n",
      "---",
      "Here is a 5-card hand that was dealt by the machine:");
   choose_hand(deck, hand);
   prn_hand(hand);
   printf("\n%s\n%s\n\n",
      "---",
      "Here are all the hearts in the deck:");
   prn_hearts(deck);
   putchar('\n');
   return 0;
}
