//
// A program that uses constructors.
//

#include <iostream.h>
#include <stdlib.h>
#include <string.h>

typedef   const char   cchr;

const int   max_sz = 300;

class string {
public:
   //
   // Three constructors.
   //
   string() { s = new char [max_sz]; len = -1; }
   string(int n) { s = new char [n]; len = -1; }
   string(cchr* t) { len = strlen(t);
                     s = new char [len + 1]; strcpy(s, t); }
   //
   // One destructor.
   //
   ~string() { delete [] s; }
   //
   // Four member functions.
   //
   void    assign(cchr* t) { strcpy(s, t); len = strlen(s); }
   cchr*   get_string() { return s; }
   int     length() { return (len); }
   void    print() { cout << s << "\nLength: " << len << "\n"; }

private:
   char*   s;
   int     len;
};

string&   operator+(string& a, string& b);
void      print(cchr* str);

int main()
{
   char*    str = "I came by bus.";
   string   a(str);
   string   b("I came by car.");
   string   c("I came on foot.");
   string   d("I came by horse.");
   string   e(100);
   string   abc;

   e.assign("I came quickly.");
   abc = a + b + c + d + e;
   abc.print();
}

// ---
// Try this program with and without the keyword static
// in the function definition of operator+() below.  If
// the string is not static, then the destructor deletes
// the string on function exit.  This can cause the
// program to misbehave.  Your compiler
// should issue a warning.
//

string& operator+(string& a, string& b)
{
   char            wrk[max_sz];
   static string   tmp;

   if (a.length() + b.length() < max_sz) {
      strcpy(wrk, a.get_string());
      strcat(wrk, b.get_string());
      tmp.assign(wrk);
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
