// ---
// EXERCISE 24 on page 499:
//
// Most of the code for this exercise is here,
// but some minor modifications are needed.
//
// To get started, compile and execute the program
// as written so that you understand its effects.
// Then change the code to your taste.
//

#include <fstream.h>
#include <iomanip.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>

typedef   const char   cchr;

const int   maxline     = 700;
const int   maxstring   = 100;

void   prn_info(cchr* pgm_name);

int main(int argc, char** argv)
{
   char       shout[maxstring];
   char       line[maxline];
   int        cnt;
   ifstream   ifs;

   if (argc == 1 || strcmp(argv[1], "-h") == 0) {
      prn_info(argv[0]);
      exit(1);
   }
   ifs.open(argv[1]);
   if (!ifs) {
      cout << "\nCannot open " << argv[1] << " - bye!\n\n";
      exit(1);
   }
   cnt = 0;
   while (ifs.getline(line, maxline)) {
      ++cnt;
      cout << setw(5) << cnt << ": " << line << "\n";
      if (cnt % 20 == 0) {
         cout << "\nFor more, just shout: ";
         cin.getline(line, maxline);
         istrstream   iss(line);
         iss >> shout;
         if (strcmp(shout, "shout") == 0)
            continue;
         else {
            cout << "\nI could not hear you - bye!\n\n";
            exit(1);
         }
      }
   }
}

void prn_info(cchr* pgm_name)
{
   cout << "\n"
           "---\n"
           "Usage: " << pgm_name << " ???\n"
           "\n"
           "((What is this program supposed to do?))\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -h   help option, print this message\n"
           "\n";
}
