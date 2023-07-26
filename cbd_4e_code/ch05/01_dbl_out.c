/*
//  TThhiiss  iiss  tthhee  ddbbll__oouutt  pprrooggrraamm..
//  TTyyppiiccaall  uussaaggee::
//
//        ddbbll__oouutt  <<  iinnffiillee
//
*/

#include <stdio.h>

int main(void)
{
   int   c;

   while ((c = getchar()) != EOF) {
      putchar(c);
      putchar(c);
   }
   return 0;
}
