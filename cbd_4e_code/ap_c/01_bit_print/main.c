#include "bit_print.h"

int main(int argc, char** argv)
{
   int   a;
   int   i;

   putchar('\n');
   if (argc > 1 && strcmp(argv[1], "-h") == 0) {
      prn_info(argv[0]);
      exit(1);
   }
   if (argc > 1) {
      for (i = 1; i < argc; ++i) {
         if (sscanf(argv[i], "%d", &a) != 1) {
            printf("\nERROR: Integer not found - bye!\n\n");
            exit(1);
         }
         printf("%12d = ", a);
         bit_print(a);
         printf("\n\n");
      }
   }
   else {
      for ( ; ; ) {
         printf("Input an integer: ");
         if (scanf("%d", &a) != 1) {
            printf("\nBye!\n\n");
            break;
         }
         printf("\n%d = ", a);
         bit_print(a);
         printf("\n\n");
      }
   }
   return 0;
}
