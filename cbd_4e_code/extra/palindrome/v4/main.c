#include "palindrome.h"

int main()
{
   char       longest_palindrome[maxword];
   char       longest_word[maxword];
   char       word[maxword];
   int        n;
   ifstream   ifs;

   cchr*      fname          = "/usr/dict/words";
   int        palindrome_cnt = 0;
   int        total_cnt      = 0;

   cout << "---\n"
           "Palindromes from the file " << fname << ":\n"
           "\n";
   strcpy(longest_word, "");
   strcpy(longest_palindrome, "");
   ifs.open(fname);
   assert(ifs);
   while (ifs >> word) {
      ++total_cnt;
      if (strlen(word) > strlen(longest_word))
         strcpy(longest_word, word);
      n = strlen(word);
      if (is_palindrome(word, word + n - 1) == yes) {
         ++palindrome_cnt;
         cout << setw(14) << word;
         if (palindrome_cnt % 5 == 0)
            cout << "\n";
         if (strlen(word) > strlen(longest_palindrome))
            strcpy(longest_palindrome, word);
      }
   }
   ifs.close();
   cout << ((palindrome_cnt % 5 == 0) ? "\n" : "\n\n");
   cout << "---\n"
           "Number of palindromes: " <<  palindrome_cnt     << "\n"
           "   Longest palindrome: " <<  longest_palindrome << "\n"
           "      Number of words: " <<  total_cnt          << "\n"
           "         Longest word: " <<  longest_word       << "\n"
           "\n";
}
