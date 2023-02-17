#ifndef   MK_COLS_H
#define   MK_COLS_H

#include <assert.h>
#include <ctype.h>
#include <fstream.h>
#include <iomanip.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>

class matrix;
class options;

enum off_on {off, on};

typedef   const char   cchr;
typedef   const int    cint;

cint   default_screen_width  = 80;
cint   maxword               = 700;

// ---
// mnbsbc = minimum number of blank spaces between columns
//
cint   default_mnbsbc = 3;

extern options   o;                                 // options are global

// ---
// When the words are alphabetized,
// we create a matrix of words.
//

class matrix {
public:
            matrix();
   void     fill(char** w, int n);
   void     get_space(int m, int n);
   int      row_size() { return row_sz; }
   int      col_size() { return col_sz; }
   void     release_space();
   cchr**   operator[](int i) { return el[i]; }

private:
   int       row_sz;
   int       col_sz;
   cchr**    base;
   cchr***   el;
};

class options {
public:
            options();
   int      get_fwai() { return fwai; }
   int      get_nwacl() { return nwacl; }
   int      get_indent() { return indent; }
   int      get_ncols() { return ncols; }
   void     get_options(int argc, char** argv);
   int      get_space() { return space; }
   int      get_width() { return width; }
   cchr*    local_pgm_name() { return local_pgm_nm; }
   cchr*    pgm_name() { return pgm_nm; }
   off_on   alphabetize_option() { return alphabetize_opt; }
   off_on   help_option() { return help_opt; }
   off_on   indent_option() { return indent_opt; }
   off_on   ncols_option() { return ncols_opt; }
   off_on   space_option() { return space_opt; }
   off_on   uppercase_option() { return uppercase_opt; }
   off_on   test_option() { return test_opt; }
   off_on   width_option() { return width_opt; }

private:
   char*    local_pgm_nm;
   cchr*    pgm_nm;
   int      o_cnt;
   int      fwai;                              // first working arg index
   int      nwacl;                      // # of working args on cmnd line
   int      indent;
   int      ncols;
   int      space;                               // space between columns
   int      width;
   off_on   alphabetize_opt;
   off_on   help_opt;
   off_on   indent_opt;
   off_on   ncols_opt;
   off_on   space_opt;
   off_on   test_opt;
   off_on   uppercase_opt;
   off_on   width_opt;

   void     get_local_pgm_nm();
   void     set_ncols(cchr* s);
   int      store_indent(cchr* s);
   int      store_width(cchr* s);
   int      store_space(cchr* s);
};

void       capitalize(char* word);
int        compare(const void* vp, const void* vq);
void       error_exit_cannot_open(cchr* fname);
void       error_exit_indent_not_found();
void       error_exit_indent_not_found(cchr* s);
void       error_exit_ncols_must_be_positive(int ncols, cchr* s);
void       error_exit_ncols_not_found(cchr* s);
void       error_exit_nonnegative_integer_required(int space);
void       error_exit_positive_integer_required(int val);
void       error_exit_too_many_cmnd_line_args();
void       error_exit_space_not_found();
void       error_exit_space_not_found(cchr* s);
void       error_exit_width_not_found();
void       error_exit_width_not_found(cchr* s);
void       mk_adjustments(int* fw, int n);
void       mk_cols(istream* isp);
cchr*      report(off_on val);
void       whoops_exit_ncols_not_specified();
void       whoops_exit_too_many_ncols_specified();
void       wrt_fw(int* fw, int n);
void       wrt_help(cchr* pgm_name);

ostream&   operator<<(ostream& os, matrix a);

#endif
