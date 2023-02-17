#include <stdio.h>

#define   PI   3.141592653589793

int main(void)
{
   double   radius;

   printf("\n%s\n\n%s",
      "This program computes the area of a circle.",
      "Input the radius:  ");
   scanf("%lf", &radius);
   printf("\n%s\n%s%.2f%s%.2f%s%.2f\n%s%.5f\n\n",
      "Area = PI * radius * radius",
      "     = ", PI, " * ", radius, " * ", radius,
      "     = ", PI * radius * radius);
   return 0;
}
