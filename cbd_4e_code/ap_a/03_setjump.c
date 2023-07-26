#include <iostream.h>
#include <setjmp.h>

void   f(jmp_buf env);

int main()
{
   int       value;
   jmp_buf   env;

   cout << "\n"
           "---\n"
           "Hello from main()\n"
           "\n";

   if ((value = setjmp(env)) <= 3) {
      cout << "value = " << value << "\n";
      f(env);
   }
}

void f(jmp_buf env)
{
   static int    cnt = 0;

   cout << "Hello from f(): cnt = " << cnt << "\n";
   longjmp(env, ++cnt);
}
