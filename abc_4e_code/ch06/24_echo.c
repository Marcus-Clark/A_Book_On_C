#include <stdio.h>

void main(int argc, char **argv)
{
   while (*argv != NULL)
      printf("%s  ", *argv++);
   putchar('\n');
}

