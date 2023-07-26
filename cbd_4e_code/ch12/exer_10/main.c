#include "spouse.h"

int main(void)
{
   char      answer[MAXSTRING];
   husband   john;
   wife      mary;
   choice    ans;

   assign_values(&john, &mary);
   printf("%s",
      "\n"
      "   Information is available about John and Mary.\n"
      "\n"
      "   Make a choice: ");
   gets(answer);
   putchar('\n');
   ans = select_choice(answer);
   switch(ans) {
   case man:
      prn_husband(&john);
      break;
   case woman:
      prn_wife(&mary);
      break;
   case both:
      prn_husband(&john);
      prn_wife(&mary);
      break;
   case neither:
      printf("   Bye!\n\n");
      break;
   case error:
      printf("   Sorry, your answer was unintelligible - bye!\n\n");
      exit(1);
   default:
      printf("PROGRAMMER ERROR: Cannot get to here - bye!\n\n");
      exit(1);
   }
   return 0;
}
