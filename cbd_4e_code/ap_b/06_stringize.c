#include <stdio.h>

#define   message_for(a, b)  \
          printf("\n   "#a " and " #b ": We love you!\n\n")

int main(void)
{
   message_for(Carole, Debra);
   return 0;
}
