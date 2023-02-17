#include "palindrome.h"

const char*   infile         = "/usr/dict/words";
const int     maxword        = 100;
const int     no_of_cols     = 7;
const int     screen_width   = 75;

int main()
{
   char       max_palindrome[maxword];
   char       max_word[maxword];
   char       word[maxword];
   int        fw;                                                // field width
   int        n;
   int        max_palindrome_len   = 0;
   int        max_word_len         = 0;
   int        palindrome_cnt       = 0;
   int        word_cnt             = 0;
   ifstream   ifs;

   fw = screen_width / no_of_cols;

   ifs.open(infile);
   if (!ifs) {
      cout << "\nCannot open " << infile << "\n\n";
      exit(1);
   }
   cout << "\n"
           "---\n"
           "Palindromes in the file " << infile << ":\n\n";
   while (ifs >> word) {
      ++word_cnt;
      n = strlen(word);
      if (n > max_word_len) {
         max_word_len = n;
         strcpy(max_word, word);
      }
      if (is_palindrome(word) == yes) {
         cout << setw(fw) << word;
         ++palindrome_cnt;
         if (palindrome_cnt % no_of_cols == 0)
            cout << "\n";
         if (n > max_palindrome_len) {
            max_palindrome_len = n;
            strcpy(max_palindrome, word);
         }
      }
   }
   if (palindrome_cnt % no_of_cols != 0)
      cout << "\n";
   cout << "\n"
           "      Longest palindrome: " << max_palindrome << "\n"
           "   Number of palindromes: " << palindrome_cnt << "\n"
           "            Longest word: " << max_word << "\n"
           "         Number of words: " << word_cnt << "\n"
           "\n";
   ifs.close();
}
