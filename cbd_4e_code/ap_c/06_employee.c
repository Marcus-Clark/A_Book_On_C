//
// ---
// This program tests the create_employee_data() function.
//
// The employee data consists of the following:
//
//    9 bits to store the ID number
//    6 bits to store the job type
//    1 bit  to store the gender
//
// These 16 bits are stored in a short int in the following way:
//
//    bbbbbbbbb bbbbbb b
//

#include <iostream.h>
#include <limits.h>
#include <strstream.h>

typedef   const char   cchr;

cchr*   bit_print(short employee);
short   create_employee_data(int id_no, int job_type, char gender);

int main()
{
   short   carole    = create_employee_data(101, 37, 'F');
   short   barbara   = create_employee_data(102, 23, 'F');
   short   debra     = create_employee_data(103, 29, 'F');
   short   erwin     = create_employee_data(104, 11, 'M');

   cout << "\n"
           "---\n"
           "Data for the employees:\n"
           "\n"
           "    Carole:  101   37   F\n"
           "   Barbara:  102   23   F\n"
           "     Debra:  103   29   F\n"
           "     Erwin:  104   11   M\n"
           "\n"
           "---\n"
           "After storing the data:\n"
           "\n"
           "    carole = " << bit_print(carole)  << "\n"
           "   barbara = " << bit_print(barbara) << "\n"
           "     debra = " << bit_print(debra)   << "\n"
           "     erwin = " << bit_print(erwin)   << "\n"
           "\n";
}

//
// Bit print employee data.
//

cchr* bit_print(short employee)
{
   int          i;
   int          n = sizeof(short) * CHAR_BIT;                    // in limits.h
   short        mask = 1 << (n - 1);                          // mask = 100...0
   ostrstream   oss;

   for (i = 1; i <= n; ++i) {
      oss << (((employee & mask) == 0) ? '0' : '1');
      employee <<= 1;
      if (i == 9 || i == 15)
         oss << ' ';
   }
   oss << ends;
   return oss.str();
}

//
// Create employee data in a short int.
//

short create_employee_data(int id_no, int job_type, char gender)
{
   short   employee = 0;                             // start with all bits off

   employee |= (gender == 'm' || gender == 'M') ? 0 : 1;
   employee |= job_type << 1;
   employee |= id_no << 7;
   return employee;
}
