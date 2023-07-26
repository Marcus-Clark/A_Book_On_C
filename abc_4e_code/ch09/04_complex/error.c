#include "complex.h"

void error_exit_not_a_complex_number(cchr *s)
{
   printf("%s%s%s",
      "\n"
      "---\n"
      "ERROR: Not a complex number:\n"
      "\n"
      "   Here is part of what you typed in:\n"
      "\n"
      "      ", s, "\n"
      "\n"
      "   This string cannot be interpreted as a complex number.\n"
      "   Here are some examples of acceptable complex numbers:\n"
      "\n"
      "      1.23+4.567i     -0.123     1+i     i\n"
      "\n"
      "   Only two such numbers can occur on your input line.\n"
      "\n"
      "Bye!\n"
      "\n");
   exit(1);
}

void error_exit_too_many_numbers(cchr *line)
{
   printf("%s%s%s",
      "\n"
      "---\n"
      "INPUT ERROR:\n"
      "\n"
      "   Too many numbers on the line or numbers in the wrong format:\n"
      "   Here is the line that you typed in:\n"
      "\n"
      "      ", line,
      "\n"
      "   Here are some examples of acceptable complex numbers:\n"
      "\n"
      "      1.23+4.567i     -0.123     1+i     i\n"
      "\n"
      "   Only two such numbers can occur on your input line.\n"
      "\n"
      "Bye!\n"
      "\n");
   exit(1);
}
