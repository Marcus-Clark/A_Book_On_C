#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   NDEALS     3000   /* number of deals */
#define   NPLAYERS   6      /* number of players */

typedef   enum {clubs, diamonds, hearts, spades}   cdhs;
typedef   enum {no, yes}                           no_yes;

struct card {
   int    pips;
   cdhs   suit;
};

typedef   struct card   card;

card     assign_values(int pips, cdhs suit);
void     play_poker(card deck[52]);
void     shuffle(card deck[52]);
void     swap(card *p, card *q);
void     deal_the_cards(card deck[52], card hand[NPLAYERS][5]);
no_yes   is_flush(card h[5]);
void     wrt_card_values(card *c_ptr);
