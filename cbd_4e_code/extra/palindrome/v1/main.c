#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef   const char       cchr;
typedef   const int        cint;
typedef   enum {no, yes}   no_yes;

cchr*   words   = "/usr/dict/words";
cint    maxword = 100;

no_yes   is_palindrome(char w[]);

int main(void)
{
   char   longest_palindrome[maxword];
   char   longest_word[maxword];
   char   word[maxword];
   int    palindrome_cnt = 0;
   int    total_cnt = 0;
   FILE   *ifp;

   printf("\nPalindromes from the file %s:\n\n", words);
   strcpy(longest_word, "");
   strcpy(longest_palindrome, "");
   ifp = fopen(words, "r");
   assert(ifp != NULL);
   while (fscanf(ifp, "%s", word) == 1) {
      ++total_cnt;
      if (strlen(word) > strlen(longest_word))
         strcpy(longest_word, word);
      if (is_palindrome(word) == yes) {
         ++palindrome_cnt;
         printf("%14s%s", word, (palindrome_cnt % 5 == 0) ? "\n" : "");
         if (strlen(word) > strlen(longest_palindrome))
            strcpy(longest_palindrome, word);
      }
   }
   printf("\n\n%s%d\n%s%s\n%s%d\n%s%s\n",
      "Number of palindromes: ", palindrome_cnt,
      "   Longest palindrome: ", longest_palindrome,
      "      Number of words: ", total_cnt,
      "         Longest word: ", longest_word);
   return 0;
}

no_yes is_palindrome(char w[])
{
   int   i, j;

   i = 0;
   j = strlen(w) - 1;
   while (i < j && w[i] == w[j]) {
      ++i;
      --j;
   }
   if (i >= j)
      return yes;
   return no;
}
