/*
// Use recursion to draw patterns on
// the standard input file (screen).
*/

#include <stdio.h>

#define   SYMBOL   '*'
#define   OFFSET   0
#define   LENGTH   19

void   display(char c, int m, int n);
void   draw(char c, int k);

int main(void)
{
   display(SYMBOL, OFFSET, LENGTH);
   return 0;
}

void display(char c, int m, int n)
{
   if (n > 0) {
      draw(' ', m);
      draw(c, n);
      putchar('\n');
      display(c, m + 2, n - 4);
   }
}

void draw(char c, int k)
{
   if (k > 0) {
      putchar(c);
      draw(c, k - 1);
   }
}
