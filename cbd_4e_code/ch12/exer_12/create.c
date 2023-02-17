#include "list.h"

void create_array(data **a_ptr, int *n_ptr, FILE *ifp)
{
   char   name[MAXSTRING];
   char   line[MAXLINE];
   int    age;
   int    cnt = 0;
   int    i;
   int    n;            /* array size */
   int    weight;
   data   *a;

   /*
   // First count the lines in the file, excluding
   // any blank lines or comment lines.
   */
   while (fgets(line, MAXLINE, ifp) != NULL) {
      if (is_blank(line) == yes)
         continue;
      if (is_comment(line) == yes)
         continue;
      ++cnt;
   }
   n = cnt;
   assert(n > 0);
   /*
   // Create an array of n elements of type data.
   */
   a = calloc(n, sizeof(data));
   assert(a != NULL);
   /*
   // Start at the top of the file again, and read in one line
   // after another.  If a line is neither a blank line nor a
   // comment line, get the data from the line and place it
   // in the appropriate members in an element of the array.
   //
   // Remember:
   //    Each element of the array is a structure of type data.
   */
   rewind(ifp);
   i = -1;
   while (fgets(line, MAXLINE, ifp) != NULL) {
      if (is_blank(line) == yes)
         continue;
      if (is_comment(line) == yes)
         continue;
      ++i;
      cnt = sscanf(line, "%s%d%d", name, &age, &weight);
      /*
      // Make some checks.
      */
      assert(cnt == 3);
      assert(strlen(name) < MAXNAME);
      assert(age > 0 && age < 100);
      assert(weight > 0 && weight < 700);
      /*
      // Put the data into the ith element of the array.
      */
      strcpy(a[i].name, name);
      a[i].age = age;
      a[i].weight = weight;
   }
   /*
   // We need to get the array and its size
   // back to the calling environment.
   */
   *a_ptr = a;
   *n_ptr = n;
}

elem *create_list(data a[], int n)
{
   int    i;
   elem   *hp = NULL;
   elem   *p;

   for (i = 0; i < n; ++i) {
      if (hp == NULL)
         hp = p = malloc(sizeof(elem));
      else
         p = p -> next = malloc(sizeof(elem));
      assert(p != NULL);
      /*
      // Copy the data in a[i] into p -> d.
      */
      strcpy(p -> d.name, a[i].name);
      p -> d.age = a[i].age;
      p -> d.weight = a[i].weight;
   }
   /*
   // We check to see that we have at least one element in our list.
   // If we do, then we need to end the linked list by setting
   // the last link to NULL.
   */
   assert(hp != NULL);
   p -> next = NULL;
   return hp;
}
