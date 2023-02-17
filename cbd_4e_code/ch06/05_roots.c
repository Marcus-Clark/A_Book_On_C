//
// Find real and complex roots of real quadratic equations.
//

#include <complex.h>
#include <iostream.h>
#include <stdlib.h>

int main()
{
   double    a, b, c;
   double    discriminant;
   double    r_root1, r_root2;               // real roots
   complex   c_root1, c_root2;            // complex roots

   cout << "\n"
           "Real and complex roots will be found\n"
           "for the real quadratic equation\n"
           "\n"
           "   Ax^2 + Bx + C = 0\n"
           "\n";

   cout.setf(ios::fixed);
   cout.precision(3);
   for ( ; ; ) {
      cout << "Enter A, B, and C: ";
      cin >> a >> b >> c;
      if (!cin)
         break;
      if (a == 0.0) {
         cout << "SORRY: A must be nonzero - bye!\n\n";
         exit(1);
      }
      discriminant = b * b - 4.0 * a * c;
      if (discriminant >= 0.0) {
         r_root1 = (-b + sqrt(discriminant)) / (2.0 * a);
         r_root2 = (-b - sqrt(discriminant)) / (2.0 * a);
         cout << "\n"
                 "The roots are real:\n"
                 "\n"
                 "       root1 = " << r_root1 << "\n"
                 "       root2 = " << r_root2 << "\n"
                 "discriminant = " << discriminant << "\n"
                 "\n";
      }
      else {
         c_root1 = (-b + sqrt((complex) discriminant)) / (2.0 * a);
         c_root2 = (-b - sqrt((complex) discriminant)) / (2.0 * a);
         cout << "\n"
                 "The roots are complex:\n"
                 "\n"
                 "       root1 = " << c_root1 << "\n"
                 "       root2 = " << c_root2 << "\n"
                 "discriminant = " << discriminant << "\n"
                 "\n";
      }
   }
   cout << "\nBye!\n\n";
}
