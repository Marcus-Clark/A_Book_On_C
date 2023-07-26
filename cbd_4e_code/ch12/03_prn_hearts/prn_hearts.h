#include <stdio.h>

struct card {
   int    pips;
   char   suit;
};

void   assign_values(struct card *c_ptr, int p, char s);
void   extract_values(struct card *c_ptr, int *p_ptr, char *s_ptr);
void   prn_values(struct card *c_ptr);
