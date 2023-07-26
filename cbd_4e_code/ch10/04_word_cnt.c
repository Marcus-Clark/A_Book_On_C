//
// Count the number of words in a file.
//

#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>

const int   maxstring   = 100;

int main()
{
   char       ifn[maxstring];    // infile name
   char       word[maxstring];
   int        cnt = 0;
   ifstream   ifs;

   cout << "\n   Input the name of a file: ";
   cin >> ifn;
   ifs.open(ifn);
   if (!ifs) {
      cout << "\n   Cannont open " << ifn << " - bye!\n\n";
      exit(1);
   }
   while (ifs >> word)
      ++cnt;
   cout << "\n   Word count: " << cnt << "\n\n";
}
