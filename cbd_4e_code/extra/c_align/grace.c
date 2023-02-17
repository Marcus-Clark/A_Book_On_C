#include "c_align.h"

void gremove(cchr* fname)
{
   if (remove(fname) == -1) {
      cout << "ERROR: remove() failed - bye.\n\n";
      exit(1);
   }
}

void grewind(istream& is)
{
   is.clear();
   is.seekg(ios::beg);
   if (!is) {
      cout << "WHOOPS: grewind() failed - bye!\n\n";
      exit(1);
   }
}

void gstat(cchr* fname, struct stat* statbuf_ptr)
{
   if (stat(fname, statbuf_ptr) == -1) {
      perror("TROUBLE: stat()");
      cout << "---\n"
              "TROUBLE:\n"
              "\n"
              "   Trouble with " << fname << " in stat().\n"
              "\n"
              "Bye!\n"
              "\n";
      exit(1);
   }
}

void gsystem(cchr* cmnd)
{
   if (system(cmnd) == -1) {
      cout << "ERROR: Call to system() failed - bye!\n\n";
      exit(1);
   }
}

void gutimes(char* fname, struct timeval* tvp)
{
   if (utimes(fname, tvp) == -1) {
      perror("TROUBLE: utimes()");
      cout << "---\n"
              "TROUBLE:\n"
              "\n"
              "   Trouble with " << fname << " in utimes().\n"
              "\n"
              "Bye!\n"
              "\n";
      exit(1);
   }
}
