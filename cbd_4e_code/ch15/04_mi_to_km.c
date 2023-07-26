//
// Miles are converted to kilometers.
//
// To stop this program, input a nonpositive number.
//

#include <iostream.h>

const double    mi_to_km = 1.609;

inline double   convert(double mi) { return (mi * mi_to_km); }

int main()
{
   double   miles;

   do {
      cout << "Input distance in miles: ";
      cin >> miles;
      cout << "\nDistance is " << convert(miles) 
           << " km.\n\n";
   } while (miles > 0);
}
