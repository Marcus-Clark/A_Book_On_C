#include "wrt_bkwds.h"

const int   max_line_len   = 67;
const int   maxword        = 100;

int main(int argc, char** argv)
{
   ifstream   ifs;

   if (argc == 1 || *argv[1] == '-') {
      prn_info(argv[0]);
      exit(1);
   }
   ifs.open(argv[1]);
   if (!ifs) {
      cout << "\nCannot open " << argv[1] << " - bye!\n\n";
      exit(1);
   }
   wrt_bkwds_by_word(ifs);
   cout << "\n\n";
}
