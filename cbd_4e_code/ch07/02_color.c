//
// In C++, the tag name in an enumeration type is automatically
// typedefed to the enumeration type as a whole.  Thus "color"
// is a type in this program.
//
// What gets printed?
//

#include <iostream.h>

enum color {black, red, blue, green, white, other};

int main()
{
   color   val = blue;

   if (val == red)
      cout << "Value of red = " << red << "\n";
   else if (val == blue)
      cout << "Value of blue = " << blue << "\n";
   else
      cout << "The color is neither red nor blue.\n";
}
