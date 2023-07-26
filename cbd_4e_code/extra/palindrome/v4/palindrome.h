#include <assert.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>

typedef   const char   cchr;
typedef   const int    cint;

enum no_yes {no, yes};

cint   maxword = 100;

no_yes   is_palindrome(cchr* p, cchr* q);
