#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *env[])
{
   printf("%s%s\n%s%s\n%s%s\n%s%s\n",
      "          Name: ", getenv("NAME"),
      "          User: ", getenv("USER"),
      "         Shell: ", getenv("SHELL"),
      "Home directory: ", getenv("HOME"));
   return 0;
}
