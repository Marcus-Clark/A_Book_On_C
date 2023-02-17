/* Create employee data in a short int. */

short create_employee_data(int id_no, int job_type, char gender)
{
   short   employee = 0;     /* start with all bits off */

   employee |= (gender == 'm' || gender == 'M') ? 0 : 1;
   employee |= job_type << 1;
   employee |= id_no << 7;
   return employee;
}
