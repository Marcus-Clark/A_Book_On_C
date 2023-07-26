#include "pgm.h"

void prn_info(char *pgm_name)
{
   printf("%s\n",
      "Usage:  pgm\n"
      "\n"
      "This program illustrates how one can write\n"
      "a program in more than one file.  In this\n"
      "example, we have a single .h file that gets\n"
      "included at the top of our three .c files.\n"
      "Thus the .h file acts as the \"glue\"\n"
      "that binds the program together.\n"
      "\n"
      "Note that the functions fct1() and fct2()\n"
      "when called only say \"Hello.\"  When writing\n"
      "a serious program, the programmer sometimes\n"
      "does this in a first working version\n"
      "of the code.\n");
}
