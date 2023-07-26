//
// Miles are converted to kilometers.
//
// To stop this program, type "bye."
//

#include <iostream.h>

const double    mi_to_km = 1.609;

inline double   convert(double mi) { return (mi * mi_to_km); }

int main()
{
   double   miles;

   cout << "\nInput distance in miles: ";
   while (cin >> miles) {
      cout << "\nDistance in kilometers: " << convert(miles) << " km\n\n";
      cout << "Input distance in miles: ";
   }
   cout << "\nBye!\n\n";
}
