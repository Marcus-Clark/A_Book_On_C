#include "majority.h"

int main()
{
   short   carole;
   short   barbara;
   short   debra;
   short   m;

   // ---
   // Seed the random number generator.
   //
   srand(time(NULL));
   //
   // Simulate the vote on 16 referendums.
   //
   carole = vote();
   barbara = vote();
   debra = vote();
   //
   // Find the majority on each referendum
   // and print the results, both bitwise
   // and by referendum.
   //
   m = majority(carole, barbara, debra);
   prn_results(carole, barbara, debra, m);
   chk(carole, barbara, debra, m);
}
