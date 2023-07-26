#include "count.h"

int main(int argc, char **argv)
{
   char   answer[MAXWORD];
   char   word[MAXWORD];
   cchr   *cp;
   int    cnt;
   int    n;
   elem   *hp;
   elem   *p;
   FILE   *ifp;

   if (argc == 1 || strcmp(argv[1], "-h") == 0) {
      prn_info(argv[0]);
      exit(1);
   }
   if ((ifp = fopen(argv[1], "r")) == NULL) {
      printf("\nCannot open %s - bye!\n\n", argv[1]);
      exit(1);
   }
   cnt = 0;
   while (fscanf(ifp, "%s", word) == 1) {
      ++cnt;
      if (hp == NULL)
         hp = p = malloc(sizeof(elem));
      else
         p = p -> next = malloc(sizeof(elem));
      assert(p != NULL);
      n = strlen(word);
      p -> word = calloc(n + 1, sizeof(char));  /* need to store '\0' */
      assert(p -> word != NULL);
      strcpy(p -> word, word);
   }
   if (hp != NULL)
      p -> next = NULL;
   /*
   // Count the elements in the linked list and make sure that
   // the number agrees with the number of words read in.
   */
   assert (count(hp) == cnt);
   /*
   // Report the count to the user.
   */
   printf("\n%s%s%s%d%s",
      "   ---\n"
      "   The words in the file ", argv[1], " were counted as they\n"
      "   were being read in, and a linked list of\n"
      "   the words has been made.\n"
      "\n"
      "   As an independent check, the function count()\n"
      "   was used to count the words recursively\n"
      "   in the linked list.\n"
      "\n"
      "   The two counts agree.\n"
      "\n"
      "   Word count = ", cnt, "\n"
      "\n"
      "   ---\n"
      "   Would you like to see the list of words? ");
   /*
   // Pick up the answer from the user.
   */
   fgets(answer, MAXLINE, stdin);
   /*
   // Make the default answer, signaled by a
   // carriage return, to be "yes."
   */
   for (cp = answer; isspace(*cp); ++cp)
      ;
   if (*cp == 'n' || *cp == 'N')
      printf("\n   Bye!\n\n");
   else {
      putchar('\n');
      for (p = hp; p != NULL; p = p -> next)
         printf("%s\n", p -> word);
   }
   return 0;
}
