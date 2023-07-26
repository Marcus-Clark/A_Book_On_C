#include "complex.h"

no_yes get_complex_number(complex *z, cchr *s)
{
   cchr*   p;
   dbl     x;
   dbl     y;

   assert(strlen(s) > 0);
   assert(!isspace(*s));
   assert(!isspace(*(s + strlen(s) - 1)));
   /*
   // Try to pick up the first number.
   */
   if (sscanf(s, "%lf", &x) != 1) {
      /*
      // There is no first number; look for +i, -i, or i.
      */
      if (strcmp(s, "+i") == 0 || strcmp(s, "i") == 0) {
         z -> re = 0.0;
         z -> im = 1.0;
         return yes;
      }
      if (strcmp(s, "-i") == 0) {
         z -> re = 0.0;
         z -> im = -1.0;
         return yes;
      }
   }
   /*
   // We have a number; is it by itself?
   */
   p = skip_number(s);
   if (*p == '\0') {
      z -> re = x;
      z -> im = 0.0;
      return yes;
   }
   if (strcmp(p, "i") == 0) {
      z -> re = 0.0;
      z -> im = x;
      return yes;
   }
   /*
   // Try to pick up the second number.
   */
   if (sscanf(p, "%lf", &y) != 1) {
      /*
      // There is no second number; look for +i or -i.
      */
      if (strcmp(p, "+i") == 0) {
         z -> re = x;
         z -> im = 1.0;
         return yes;
      }
      if (strcmp(p, "-i") == 0) {
         z -> re = x;
         z -> im = -1.0;
         return yes;
      }
   }
   /*
   // We have the second number; it should be followed by i.
   */
   p = skip_number(p);
   if (strcmp(p, "i") == 0) {
      z -> re = x;
      z -> im = y;
      return yes;
   }
   /*
   // If we get this far, there is trouble.
   */
   error_exit_not_a_complex_number(s);
   return no;
}

no_yes get_from_user(complex *a, complex *b)
{
   char     line[MAXLINE];
   char     s1[MAXSTRING];
   char     s2[MAXSTRING];
   cchr     *p;
   char     *val;

   val = fgets(line, MAXLINE, stdin);
   assert(val != NULL);
   /*
   // Skip white space.
   */
   for (p = line; isspace(*p); ++p)
      ;
   /*
   // Check for "bye", "exit", of "quit".
   */
   if (*p == 'b' || *p == 'e' || *p == 'q')
      return no;
   /*
   // Get the first string from the line.
   */
   if (sscanf(p, "%s", s1) != 1)
      return no;
   /*
   // Skip over the first string.
   */
   p += strlen(s1);
   /*
   // Skip white space.
   */
   for ( ; isspace(*p); ++p)
      ;
   /*
   // Get the second string from the line.
   */
   if (sscanf(p, "%s", s2) != 1)
      return no;
   /*
   // Skip over the second string.
   */
   p += strlen(s2);
   /*
   // Skip white space.
   */
   for ( ; isspace(*p); ++p)
      ;
   /*
   // Check for anything else on the line.
   */
   if (*p != '\0')
      error_exit_too_many_numbers(line);
   /*
   // Get the complex numbers a and b.
   */
   if (get_complex_number(a, s1) == no)
      return no;
   if (get_complex_number(b, s2) == no)
      return no;
   return yes;
}
