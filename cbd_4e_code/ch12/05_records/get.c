#include "st_data.h"

void get_student_data(student_data sd[])
{
   char   line[MAXLINE];
   char   name[MAXWORD];
   cchr   *msg;
   int    cnt;
   int    i;
   int    n;
   int    student_id;
   FILE   *ifp;

   /*
   // Get the student names, id_nos, and grades.
   */
   ifp = fopen(GRADES, "r");
   if (ifp == NULL) {
      printf("\nCannot open %s - bye!\n\n", GRADES);
      exit(1);
   }
   i = -1;
   while (fgets(line, MAXLINE, ifp) != NULL) {
      if (is_comment(line) == yes)
         continue;
      if (is_blank(line) == yes)
         continue;
      ++i;
      cnt = sscanf(line, "%s%d %c %c",
               name, &sd[i].student_id, &sd[i].grade[0], &sd[i].grade[1]);
      assert(cnt == 4);
      n = strlen(name);
      assert(n < MAXNAME);
      strcpy(sd[i].p.name, name);
   }
   if (i != CLASS_SIZE - 1) {
      msg = "Unexpected class size in " GRADES;
      error_exit(msg);
   }
   fclose(ifp);
   /*
   // Get the birthdays.
   */
   ifp = fopen(BIRTHDAYS, "r");
   if (ifp == NULL) {
      printf("\nCannot open %s - bye!\n\n", BIRTHDAYS);
      exit(1);
   }
   i = -1;
   while (fgets(line, MAXLINE, ifp) != NULL) {
      if (is_comment(line) == yes)
         continue;
      if (is_blank(line) == yes)
         continue;
      ++i;
      cnt = sscanf(line, "%s%d%hd%s%hd",
               name, &student_id, &sd[i].p.birthday.day,
                                   sd[i].p.birthday.month,
                                  &sd[i].p.birthday.year);
      assert(cnt == 5);
      assert(strcmp(name, sd[i].p.name) == 0);
      assert(student_id == sd[i].student_id);
      assert(sd[i].p.birthday.day >= 1);
      assert(sd[i].p.birthday.day <= 31);
      assert(strlen(sd[i].p.birthday.month) == 3);
      assert(sd[i].p.birthday.year >= 0);
      assert(sd[i].p.birthday.year <= 99);
   }
   if (i != CLASS_SIZE - 1) {
      msg = "Unexpected class size in " BIRTHDAYS;
      error_exit(msg);
   }
   fclose(ifp);
}
