//The circumference and area of a circle.
//            by
//        Cottage Consultants - LMP & DJD
//           V 2.3

#include <iostream.h> //standard C++ IO library

int main(void)
{
   while(1) { //infinite loop - exit with control-C
      cout << "\nENTER radius: ";  //prompt
      double r; //C++ allows declarations inside block
      cin >> r;                    //input
      double diam = 2 * r; //declare and initialize
      cout << "\nDiameter = " << diam;
      cout << "\nArea = " << pi * r * r;
      cout << "\nCircumference = " << pi * diam<< endl;
   }
   return 0;
}
