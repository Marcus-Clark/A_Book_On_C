#include <stdio.h>

#undef    PIE
#define   PIE   "I like apple."

int main(void)
{
   printf("PIE: " PIE "\n");
   return 0;
}
