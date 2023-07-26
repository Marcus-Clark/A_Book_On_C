//
// Use of the operator new to dynamically
// allocate space for an array named data.
//

#include  <iomanip.h>
#include  <iostream.h>

int main()
{
   int*  data;
   int   i;
   int   size;

   cout << "\nEnter array size: ";
   cin >> size;
   cout << "\n";

   data = new int [size];            // allocate an array of ints
   for (i = 0; i < size; ++i)
      cout << setw(5) << (data[i] = i);
   cout << "\n\n";
   delete [] data;                   // deallocate the array

   data = new int [size];            // will we get the same space again?
   for (i = 0; i < size; ++i)
      cout << setw(5) << data[i];
   cout << "\n\n";
}
