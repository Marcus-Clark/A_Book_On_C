// The distance to the moon converted to kilometers.

#include <iostream.h>

int main()
{
   const long int   moon = 238857;

   cout << "The moon's distance from Earth is " << moon;
   cout << " miles.\n";

   long int   moon_kilo;

   moon_kilo = (long int) (moon * 1.609);
   cout << "In kilometers this is " << moon_kilo;
   cout << " km.\n";
}
