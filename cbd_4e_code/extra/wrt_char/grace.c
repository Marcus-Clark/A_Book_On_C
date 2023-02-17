#include "wrt_char.h"

void gremove(cchr* fname)
{
   if (remove(fname) == -1) {
      cout << "---\n"
              "ERROR:\n"
              "\n"
              "   ---\n"
              "   Call to remove(" << fname << ") failed - bye!\n"
              "\n";
      exit(1);
   }
}

void grewind(istream& is)
{
   is.clear();
   is.seekg(ios::beg);
   if (!is) {
      cout << "ERROR: Call to grewind() failed - bye!\n\n";
      exit(1);
   }
}

void grewind(ostream& os)
{
   os.clear();
   os.seekp(ios::beg);
   if (!os) {
      cout << "---\n"
              "ERROR: Call to grewind() failed - bye!\n"
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

int gtcgetattr(int fd, termios* termios_p)
{
   int   val;

   val = tcgetattr(fd, termios_p);
   if (val != 0) {
      cout << "---\n"
              "ERROR: Call to tcgetattr() failed - bye!\n"
              "\n";
      exit(1);
   }
   return val;
}

int gtcsetattr(int fd, int optional_actions, const termios* termios_p)
{
   int   val;

   val = tcsetattr(fd, optional_actions, termios_p);
   if (val != 0) {
      cout << "---\n"
              "ERROR: Call to tcsetattr() failed - bye!\n"
              "\n";
      exit(1);
   }
   return val;
}
