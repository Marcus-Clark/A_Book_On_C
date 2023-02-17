//
// Overloading the function print() and the operator + .
// In this program, operator+() is a friend function.
//

#include <iostream.h>
#include <stdlib.h>
#include <string.h>

typedef   const char   cchr;

const int   max_len = 300;

class string {
public:
   void   assign(cchr* t) { strcpy(s, t); len = strlen(s); }
   int    length() { return (len); }
   void   print() { cout << s << "\nLength: " << len << "\n"; }

   friend string   operator+(const string& a, const string& b);

private:
   char   s[max_len];
   int    len;
};

void   print(cchr* str);

int main()
{
   char     str[] = "My name is Charles Babbage.";
   string   one;
   string   two;
   string   both;

   one.assign("My name is Alan Turing.");
   two.assign(str);
   //
   // Next, we make a call to the
   // top level print() function.
   //
   print(str);
   //
   // Next, we call the member function length() of the class string
   // to compare string lengths.  The variable having the shorter
   // length gets printed via a call to the member function
   // print() of the class string.
   //
   if (one.length() <= two.length())
      one.print();
   else
      two.print();
   //
   // Call the overloaded + operator.
   //
   both = one + two;
   both.print();
}

//
// This is the function definition
// of the overloaded + operator.
//

string operator+(const string& a, const string& b)
{
   string   tmp;

   if (a.len + b.len < max_len) {
      strcpy(tmp.s, a.s);
      strcat(tmp.s, b.s);
      tmp.len = a.len + b.len;
   }
   else {
      cerr << "\nERROR: Max length exceeded in "
              "concatenation in operator+() - bye!\n\n";
      exit(1);
   }
   return tmp;
}

void print(cchr* s)
{
   cout << s << "\nLength: " << strlen(s) << "\n";
}
