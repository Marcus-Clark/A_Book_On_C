#include "fortune.h"

cchr* ggetenv(cchr* name)
{
   cchr*   p;

   if ((p = getenv(name)) == NULL) {
      cout << "\nERROR: Environment variable "
           << name << " not set - bye!\n\n";
      exit(1);
   }
   return p;
}

pid_t ggetpid()
{
   pid_t   pid;

   if ((pid = getpid()) == (pid_t) -1) {
      cout << "\nERROR: Call to getpid() failed - bye.\n\n";
      exit(1);
   }
   return pid;
}

void gremove(cchr* fname)
{
   if (remove(fname) == -1) {
      cout << "\nERROR: Call to remove() failed - bye.\n\n";
      exit(1);
   }
}

//
// The function grewind() mimics
// the function rewind() in C.
//

void grewind(ifstream& ifs)
{
   ifs.clear();
   ifs.seekg(ios::beg);
   if (!ifs) {
      cout << "\nERROR: Call to grewind() failed - bye!\n\n";
      exit(1);
   }
}

void gsystem(cchr* cmnd)
{
   if (system(cmnd) == -1) {
      cout << "\nERROR: Call to system() failed - bye.\n\n";
      exit(1);
   }
}
