// The distance to the moon converted to kilometers.
//
// Title: moon

#include <iostream.h>

int main()
{
   const int   moon = 238857;

   cout << "The moon's distance from Earth is " << moon;
   cout << " miles." << endl;
   int moon_kilo = moon * 1.609;
   cout << "In kilometers this is " << moon_kilo;
   cout << " km." << endl;
}
