#include <iostream.h>
#include <string.h>

int main()
{
   char    s1[] = " this is,an   example ; ";
   char    s2[] = ",; ";                        // token separators
   char*   p;

   //
   // The first call to strtok() is special.
   //
   cout << "\n"
           "   ---\n"
           "   strtok(s1, s2) = \"" << strtok(s1, s2) << "\"\n"
           "\n";
   //
   // Now we call strtok() repeatedly
   // with NULL as its first argument.
   //
   while ((p = strtok(NULL, s2)) != NULL)
      cout << "   p = \"" << p << "\"\n";
   cout << "\n";
}
