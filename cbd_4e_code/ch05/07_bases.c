//
// This program uses different bases in integer output.
// Note the use of dec, oct, and hex.
//
// If you do not know about octal and hexadecimal numbers,
// do not bother with this program.  At this level, you
// do not need to know anything about such numbers.
//
// This program needs further work to get headings
// written over columns, etc.  To do the job right,
// however, we need more programming ideas.
//

#include  <iostream.h>
#include  <iomanip.h>

int main()
{
   int   n;

   cout << "\n"
           "Numbers written in\n"
           "\n"
           "   base  2     are called     binary numbers\n"
           "   base  8     are called     octal numbers\n"
           "   base 10     are called     decimal numbers\n"
           "   base 16     are called     hexadecimal numbers\n"
           "\n"
           "C++ provides mechanisms that allow the programmer to\n"
           "easily convert between decimal, octal, and\n"
           "hexadecimal numbers.\n"
           "\n"
           "Each number entered will be written as a decimal,\n"
           "octal, and hexadecimal number.  Note that octal\n"
           "and hexadecimal numbers are inherently nonegative\n"
           "in C/C++.\n"
           "\n"
           "Enter some decimal numbers: ";

   for ( ; ; ) {                  // use setw() to set the field width
      if (!(cin >> n))
         break;
      cout << setw(12) << dec << n;
      cout << setw(12) << oct << n;
      cout << setw(12) << hex << n;
      cout << "\n";
   }
}
