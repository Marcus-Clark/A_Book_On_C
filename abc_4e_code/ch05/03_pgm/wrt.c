#include "pgm.h"

void wrt_info(char *pgm_name)
{
   printf("Usage:  %s\n\n", pgm_name);
   printf("%s\n",
      "This program illustrates how one can write a program\n"
      "in more than one file.  In this example, we have a\n"
      "single .h file that gets included at the top of our\n"
      "three .c files.  Thus the .h file acts as the \"glue\"\n"
      "that binds the program together.\n"
      "\n"
      "Note that the functions fct1() and fct2() when called\n"
      "only say \"hello.\"  When writing a serious program, the\n"
      "programmer sometimes does this in a first working\n"
      "version of the code.\n");
}
