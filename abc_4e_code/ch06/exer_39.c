#include <stdio.h>

int main(int argc, char **argv)
{
   while (*argv != NULL)
      printf("%s  ", *argv++);
   putchar('\n');
   return 0;
}
