#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   printf("%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n",
      "   User's name: ", getenv("NAME"),
      "    Login name: ", getenv("LOGNAME"),
      "         Shell: ", getenv("SHELL"),
      "          Base: ", getenv("BASE"),
      "Home directory: ", getenv("HOME"));
   return 0;
}
