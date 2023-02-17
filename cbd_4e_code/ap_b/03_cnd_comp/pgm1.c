#include <iostream.h>

int main()
{
   cout << "\nHello from main()\n\n";

   #if 0
      
      When developing a program, it is often convenient
      to temporarily block out large sections of the
      code for testing purposes or some other
      purpose.

      This is how it can be done.

      /*
      // Note that you cannot replace
      //
      //    #if 0      with     /***
      //
      // and
      //
      //    #endif     with     ***/
      //
      // to achieve the same effect.
      */
   
   #endif
}
