#include <iostream.h>
#include <signal.h>

void   sig_chk(int sig);

int main()
{
   cout << "\n"
           "---\n"
           "           First call: " << signal(SIGINT, sig_chk) << "\n"
           "          Second call: " << signal(SIGINT, SIG_IGN) << "\n"
           "           Third call: " << signal(SIGINT, sig_chk) << "\n"
           "   Address of sig_chk: " << (int) sig_chk << "\n"
           "\n";
   
   signal(999, SIG_ERR);
   cout << "\nHello from main()\n";
   raise(SIGINT);
   raise(999);                 // Turbo c does not recognize this signal
   cout << "\nGoodbye!\n\n";
}

void sig_chk(int sig)
{
   cout << "Hello from sig_chk(): sig = " << sig << "\n";
}
