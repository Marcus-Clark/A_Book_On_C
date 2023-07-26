#include "cl_info.h"

void get_class_data(struct student class[])
{
   char   last_name[MAXWORD];
   char   line[MAXLINE];
   int    cnt;
   int    i;
   int    n;
   FILE   *ifp;

   ifp = fopen(CLASS, "r");
   if (ifp == NULL) {
      printf("\nCannot open %s - bye!\n\n", CLASS);
      exit(1);
   }
   for (i = 0; fgets(line, MAXLINE, ifp) != NULL; ++i) {
      cnt = sscanf(line, "%s%d %c",
               last_name, &class[i].student_id, &class[i].grade);
      assert(cnt == 3);
      n = strlen(last_name);
      class[i].last_name = calloc(n + 1, sizeof(char));
      assert(class[i].last_name != NULL);
      strcpy(class[i].last_name, last_name);
   }
   if (i != CLASS_SIZE) {
      printf("\n%s\n\n",
         "ERROR: Unexpected class size in get_class_data() - bye!\n\n");
      exit(1);
   }
}
