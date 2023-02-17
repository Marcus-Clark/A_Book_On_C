#include <assert.h>
#include <ctype.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>

class action;
class data;
class options;

enum no_yes {no, yes};
enum off_on {off, on};

typedef   const char   cchr;
typedef   const int    cint;

cint   maxline = 700;
cint   maxword = 100;

extern options   o;                                 // options are global

class action {
public:
   action();
   void   get_palindromes(cchr* fname);
   void   wrt_palindromes(cchr* fname);

private:
   char**   a;
   int      sz;
   char     longest_word[maxword];
   char     longest_palindrome[maxword];
   int      palindrome_cnt;
   int      total_cnt;
   data*    hp;
};

class data {
public:
   char*   palindrome;
   data*   next;
};

class options {
public:
            options();
   int      get_fwai() { return fwai; }
   int      get_nwacl() { return nwacl; }
   void     get_options(int argc, char** argv);
   cchr*    local_pgm_name() { return local_pgm_nm; }
   cchr*    pgm_name() { return pgm_nm; }

   off_on   help_option() { return help_opt; }
   off_on   test_option() { return test_opt; }

private:
   char*    local_pgm_nm;
   cchr*    pgm_nm;
   int      o_cnt;
   int      fwai;                              // first working arg index
   int      nwacl;                      // # of working args on cmnd line
   off_on   help_opt;
   off_on   test_opt;

   void     get_local_pgm_nm();
};

// ---
// Function prototypes.
//

int      compare(const void* vp, const void* vq);
void     error_exit_cannot_open(cchr* fname);
void     error_exit_too_many_filenames();
no_yes   is_palindrome(cchr* word);
no_yes   is_valid(cchr* word);
cchr*    report(off_on val);
void     wrt_help(cchr* pgm_name);
