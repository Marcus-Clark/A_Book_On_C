#include "palindrome.h"

action::action()
{
   a = NULL;
   sz = 0;
   *longest_word = '\0';
   *longest_palindrome = '\0';
   palindrome_cnt = 0;
   total_cnt = 0;
   hp = NULL;
}

void action::get_palindromes(cchr* fname)
{
   char       word[maxword];
   char*      w;
   int        i;
   data*      p;
   int        n;
   int        nn;
   ifstream   ifs;

   ifs.open(fname);
   if (!ifs)
      error_exit_cannot_open(fname);
   //
   // Create a linked list of palindromes.
   //
   assert(palindrome_cnt == 0);
   assert(total_cnt == 0);
   assert(*longest_word == '\0');
   assert(*longest_palindrome == '\0');
   assert(hp == NULL);
   while (ifs >> word) {
      ++total_cnt;
      //
      // We get a word by deleting all beginning and ending
      // punctuation, which is, perhaps, a questionable
      // algorithm.
      //
      w = word;
      n = strlen(w);
      while (n > 0 && ispunct(*w)) {
         ++w;
         --n;
      }
      if (n == 0)
         continue;
      strcpy(word, w);
      assert((int) strlen(word) == n);
      //
      // Kill all ending punctuation.
      //
      w = word;
      while (n > 0 && ispunct(*(w + n - 1))) {
         *(w + n - 1) = '\0';
         --n;
      }
      if (n == 0)
         continue;
      assert((int) strlen(word) == n && n > 0);
      if (!isalpha(*word) || !isalpha(*(word + n - 1)))
         continue;
      //
      // If we get this far, then we have a word.
      //
      nn = strlen(longest_word);
      if (n > nn)
         strcpy(longest_word, word);
      if (is_palindrome(word) == yes) {
         ++palindrome_cnt;
         nn = strlen(longest_palindrome);
         if (n > nn)
            strcpy(longest_palindrome, word);
         if (hp == NULL)
            hp = p = new data;
         else
            p = p -> next = new data;
         p -> palindrome = new char [n + 1];
         istrstream   iss(word);
         iss >> p -> palindrome;
         assert(iss);
      }
   }
   if (hp != NULL)
      p -> next = NULL;
   //
   // Create an array of palindromes and sort them.
   //
   if (palindrome_cnt > 0) {
      sz = palindrome_cnt;
      a = new char* [sz];
      for (i = 0, p = hp; p != NULL; ++i, p = p -> next)
         a[i] = p -> palindrome;
      assert(i == sz);
      qsort(a, sz, sizeof(cchr*), compare);
      //
      // Use the sorted array a[] to create a
      // linked list of unique palindromes.
      //
      hp = p = new data;
      p -> palindrome = a[0];
      palindrome_cnt = 1;
      for (i = 1; i < sz; ++i) {
         if (strcmp(a[i], a[i - 1]) != 0) {
            ++palindrome_cnt;
            p = p -> next = new data;
            p -> palindrome = a[i];
         }
      }
      p -> next = NULL;
   }
}

void action::wrt_palindromes(cchr* fname)
{
   int     cnt;
   int     fw;                                             // field width
   int     k;
   int     len;
   int     maxlen;
   int     ncols;                                    // number of columns
   data*   p;

   cout.setf(ios::left);
   maxlen = 0;
   for (p = hp; p != NULL; p = p -> next) {
      len = strlen(p -> palindrome);
      if (len > maxlen)
         maxlen = len;
   }
   fw = maxlen + 5;
   //
   // Write at most 70 characters per line,
   // including an indent of three blanks
   // at the beginning of each line.
   //
   ncols = (70 - 3) / fw;
   cout << "---\n"
           "Palindromes from the file " << fname << ":\n";
   //
   // Do not print blanks at the end of a line.
   //
   cnt = 0;
   for (p = hp; p != NULL; p = p -> next) {
      k = cnt % ncols;
      if (k == 0)
         cout << "\n   ";
      if (k < ncols - 1 && p -> next != NULL)
         cout << setw(fw) << p -> palindrome;
      else
         cout << p -> palindrome;
      ++cnt;
   }
   assert(cnt == palindrome_cnt);
   cout << ((cnt == 0) ? "\n" : "\n\n");
   cout << "---\n"
           "Number of palindromes: " <<  palindrome_cnt     << "\n"
           "   Longest palindrome: " <<  longest_palindrome << "\n"
           "      Number of words: " <<  total_cnt          << "\n"
           "         Longest word: " <<  longest_word       << "\n"
           "\n";
   cout.unsetf(ios::left);
}
