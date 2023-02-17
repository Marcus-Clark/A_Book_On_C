#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum no_yes {no, yes};
enum cdhs   {clubs, diamonds, hearts, spades};

typedef   enum cdhs     cdhs;
typedef   enum no_yes   no_yes;

struct card {
   int   pips;
   cdhs  suit;
};

typedef   struct card   card;

void   assign_values(card *c_ptr, int p, cdhs s);
void   choose_hand(card deck[], card hand[]);
void   create_deck(card deck[]);
void   extract_values(card *c_ptr, int *p_ptr, cdhs *s_ptr);
void   prn_card(card *c_ptr);
void   prn_deck(card deck[]);
void   prn_hand(card hand[]);
void   prn_hearts(card deck[]);
