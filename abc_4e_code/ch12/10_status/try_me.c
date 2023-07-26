#include <stdio.h>

#define   MARKER   ">> "

int main(int argc, char **argv)
{
   int   val;

   printf("\n");
   printf(MARKER "    Input an integer: ");
   scanf("%d", &val);
   printf(MARKER "Value being returned: %d\n\n", val);
   return val;
}
