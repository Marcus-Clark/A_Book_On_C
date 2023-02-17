#include <iomanip.h>
#include <iostream.h>
#include <unistd.h>

void   report(int value);

int main()
{ 
   int   val;

   cout << "\n";
   val = fork();
   report(val);
}

void report(int val)
{
   char*   s;

   if (val == 0)
      s = "Child:  ";
   else
      s = "Parent: ";
   cout << "---\n"
        << setw(8) <<  s << " parent process id: " << getppid() << "\n"
        << setw(8) << "" << "current process id: " << getpid()  << "\n"
        << setw(8) << "" << " value from fork(): " << val       << "\n"
        "\n";
}
