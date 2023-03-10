/* Compute the size of some fundamental types. */

#include <stdio.h>

int main(void)
{
   printf("\n");
   printf("Here are the sizes of some fundamental types:\n\n");
   printf("       char:%3d byte \n", sizeof(char));
   printf("      short:%3d bytes\n", sizeof(short));
   printf("        int:%3d bytes\n", sizeof(int));
   printf("       long:%3d bytes\n", sizeof(long));
   printf("   unsigned:%3d bytes\n", sizeof(unsigned));
   printf("      float:%3d bytes\n", sizeof(float));
   printf("     double:%3d bytes\n", sizeof(double));
   printf("long double:%3d bytes\n", sizeof(long double));
   printf("\n");
   return 0;
}
