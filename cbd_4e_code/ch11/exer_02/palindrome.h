#include <fstream.h>
#include <iostream.h>
#include <iomanip.h>

enum no_yes {no, yes};

typedef   const char   cchr;

extern const char*   infile;
extern const int     maxword;
extern const int     no_of_cols;
extern const int     screen_width;

no_yes   is_palindrome(cchr* word);
