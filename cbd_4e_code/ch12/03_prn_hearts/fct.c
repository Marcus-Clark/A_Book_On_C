#include "prn_hearts.h"

void assign_values(struct card *c_ptr, int p, char s)
{
   c_ptr -> pips = p;
   c_ptr -> suit = s;
}

void extract_values(struct card *c_ptr, int *p_ptr, char *s_ptr)
{
   *p_ptr = c_ptr -> pips;
   *s_ptr = c_ptr -> suit;
}
