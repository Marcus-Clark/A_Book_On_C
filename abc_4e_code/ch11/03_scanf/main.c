#include <assert.h>
#include <stdio.h>
#include <string.h>

#define   MAXSTRING   100

int main(void)
{
   char   input[MAXSTRING];
   char   string[15];
   char   *val;
   char   c;
   int    cnt;
   int    i;
   int    n;
   FILE   *ifp;

   ifp = fopen("input", "r");
   assert(ifp != NULL);
   val = fgets(input, MAXSTRING, ifp);
   assert(val != NULL);
   fclose(ifp);
   /*
   // Delete the newline at the end of the input string.
   */
   n = strlen(input);
   *(input + n - 1) = '\0';
   cnt = sscanf(input, "%d , %*s %% %c %5s %s", &i, &c, string, &string[5]);
   printf("%s%s%s%c%s%d%s%s%s%s%s%d%s\n",
      "---\n"
      "Control string: \"%d , %*s %% %c %5s %s\"\n" 
      "\n"
      "  Input string: \"", input, "\"\n"
      "\n"
      "Here are the values obtained from the input string:\n"
      "\n"
      "            c = ", c, "\n"
      "            i = ", i, "\n"
      "       string = ", string, "\n"
      "   string + 5 = ", string + 5, "\n"
      "\n"
      "   number of successful conversions = ", cnt, "\n");
   return 0;
}
