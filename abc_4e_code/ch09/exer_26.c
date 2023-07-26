#include <stdio.h>

typedef struct a { unsigned a : 1, : 0, b : 1; } a;
typedef struct b { unsigned a : 1, b : 1; } b;

int main(void)
{
   printf("%.1f\n", (float) sizeof(a) / sizeof(b));
   return 0;
}
