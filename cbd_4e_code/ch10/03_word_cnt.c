//
// Count the number of words in a file.
//

#include <ctype.h>
#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>

const int   maxline     = 300;
const int   maxstring   = 100;

int   word_cnt(char *s);

int main()
{
   char       ifn[maxstring];    // infile name
   char       line[maxline];
   int        cnt = 0;
   ifstream   ifs;

   cout << "\n   Input the name of a file: ";
   cin >> ifn;
   ifs.open(ifn);
   if (!ifs) {
      cout << "\n   Cannont open " << ifn << " - bye!\n\n";
      exit(1);
   }
   while (ifs.getline(line, maxline))
      cnt += word_cnt(line);
   cout << "\n   Word count: " << cnt << "\n\n";
}

//
// Count the number of words in a string.
//

int word_cnt(char *s)
{
   int   cnt = 0;

   while (*s != '\0') {
      while (isspace(*s))           /* skip white space */
         ++s;
      if (*s != '\0') {                 /* found a word */
         ++cnt;
       while (!isspace(*s) && *s != '\0')  /* skip word */
          ++s;
      }
   }
   return cnt;
}
