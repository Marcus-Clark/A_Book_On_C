// ---
// In ANSI C, the address operator & can be applied
// to an array.  In traditional C, many compilers
// will not allow this to be done.
//
// This program illustrates taking the address of
// an array of arrays.  This C++ program is a
// variation on what we did in 01_array_ptr.c.
//

#include <assert.h>
#include <iomanip.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef   const char   cchr;
typedef   int          (*paai)[][5];           // ptr to array of array of ints

class matrix {
public:
   //
   // In the constructor we will take the address of el,
   // which is an array of arrays of ints.
   //
           matrix() { row_sz = 3; col_sz = 5; el_ptr = &el; }    // constructor
   cchr*   name() { return nm; }
   paai    elem_ptr() { return el_ptr; }
   int     row_size() { return row_sz; }
   int     col_size() { return col_sz; }
   int*    operator[](int i) { return el[i]; }
   void    fill();
   void    set_name(cchr* s);

private:
   char*   nm;
   int     row_sz;
   int     col_sz;
   int     el[3][5];                     // row and column sizes are hard-wired
   paai    el_ptr;

};

ostream&   operator<<(ostream& os, matrix a);
void       prn_array(cchr* s, int a[][5], int m, int n);

int main()
{
   int      (*p)[][5];                   // a ptr to an array of arrays of ints
   matrix   a;                                   // the constructor gets called

   a.set_name("a");                               // set the name of the matrix
   a.fill();                                                 // fill the matrix
   cout << "\n" << a << "\n";                               // print the matrix
   p = a.elem_ptr();                                     // p = address of a.el
   prn_array("*p", *p, 3, 5);                    // print what p is pointing to
}

void matrix::fill()
{
   int   i;
   int   j;
   int   m = row_sz;
   int   n = col_sz;

   srand(time(NULL));
   for (i = 0; i < m; ++i)
      for (j = 0; j < n; ++j)
         el[i][j] = rand() % 1000;
}

void matrix::set_name(cchr* s)
{
   int   len;

   len = strlen(s);
   nm = new char [len + 1];
   strcpy(nm, s);
}

ostream& operator<<(ostream& os, matrix a)
{
   int   i;
   int   j;
   int   m = a.row_size();
   int   n = a.col_size();

   os << a.name() << " =\n";
   for (i = 0; i < m; ++i) {
      os << "   ";
      for (j = 0; j < n; ++j)
         os << setw(7) << a[i][j];
      os << "\n";
   }
   return os;
}

void prn_array(cchr* s, int a[][5], int m, int n)
{
   int   i;
   int   j;

   /*
   // Because the size of the 2nd dimension of the array must
   // be hard-wired, m can only take on the value 3.  Thus there
   // is no need to design the function definition as having two
   // arguments.  However, the call to the function looks more
   // natural if we do so.
   */
   assert(n == 5);
   cout << s << " =\n";
   for (i = 0; i < m; ++i) {
      cout << "   ";
      for (j = 0; j < n; ++j)
         cout << setw(7) << a[i][j];
      cout << "\n";
   }
   cout << "\n";
}
