#include "bubble.h"

const int   maxline     = 700;
const int   maxstring   = 100;

int main(int argc, char** argv)
{
   char       line[maxline];
   char       word[maxstring];
   char*      p;
   cchr*      q;
   int        cnt = 0;
   ifstream   ifs;

   if (argc == 1 || strncmp(argv[1], "-h", 2) == 0) {
      prn_info(argv[0]);
      exit(1);
   }
   ifs.open(argv[1]);
   if (!ifs) {
      cout << "\nCannot open " << argv[1] << " - bye!\n\n";
      exit(1);
   }
   while (ifs.getline(line, maxline)) {                       // get a line
      for (p = line; *p != '\0'; ++p) {
         if (isalpha(*p)) {             // for example, leave numbers alone
            istrstream   iss(p);
            iss >> word;                                // capture the word
            bubble_str(word);                       // bubble sort the word
            ++cnt;
            q = word;
            while (*q != '\0')                   // put word back into line
               *p++ = *q++;
            assert(isspace(*p) || *p == '\0');
            //
            // Back up p so that when p gets incremented at
            // the end of the for loop it will be right
            // where we want it.
            // 
            --p;
         }
      }
      cout << line << "\n";
   }
   cout << "\nBubbled word count: " << cnt << "\n\n";
}
