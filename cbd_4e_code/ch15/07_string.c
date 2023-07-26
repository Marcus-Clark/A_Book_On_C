// Test of the class string.

#include <iostream.h>
#include <string.h>

typedef   const char   cchr;

const int   max_len = 300;

class string {
public:
   void   assign(cchr* t) { strcpy(s, t); len = strlen(t); }
   int    length() { return (len); }
   void   print() { cout << s << "\n"
                         << "Length: " << len << "\n"; }
private:
   char   s[max_len];
   int    len;
};

void   print(cchr* s);

int main()
{
   string   one, two;
   char     three[] = "My name is Charles Babbage.";

   one.assign("My name is Alan Turing.");
   two.assign(three);
   //
   // The function print() occurs as a top-level function
   // as well as a member function of the class string.
   //
   print(three);
   //
   // Print the shorter of the two strings.
   //
   if (one.length() <= two.length())
      one.print();
   else
      two.print();
}

void print(cchr* s)
{
   cout << s << "\nLength is " << strlen(s) << "\n";
}
