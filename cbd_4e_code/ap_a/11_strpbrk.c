#include <iostream.h>
#include <string.h>

typedef   const char   cchr;

int main()
{
   cchr*   p;
   cchr*   s = "strpbrk(\"April is the cruelest month\", \"abc\")";

   p = strpbrk("April is the cruelest month", "abc");

   cout << "\n"
           "   " << s << " = " << p << "\n"
           "\n";
}
