#include <stdio.h>

#define   GREETINGS(a, b, c) \
          printf(#a ", " #b ", and " #c ": Hello!\n")

int main(void)
{
   GREETINGS(Alice, Bob, Carole);
   return 0;
}
