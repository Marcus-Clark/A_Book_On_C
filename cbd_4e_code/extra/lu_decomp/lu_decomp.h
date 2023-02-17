#include <assert.h>
#include <ctype.h>
#include <fstream.h>
#include <iomanip.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include <time.h>

#define   MAXLINE     700
#define   MAXSTRING   300

class ivec;
class matrix;
class options;

enum no_yes {no, yes};
enum off_on {off, on};

typedef   const char   cchr;
typedef   double       dbl;

extern options   o;                                       // options are global

class ivec {
public:
          ivec() { sz = 0; el = NULL; }
          ivec(int n);
          ivec(int m, int n);

   int&   operator[](int i) { return el[i]; }

   int    begin() { return bgn; }
   void   get_space(int n);
   void   get_space(int m, int n);
   int    size() { return sz; }
   void   release_space();

private:
   int*   el;
   int    bgn;                                             // index of 1st elem
   int    sz;
};

class matrix {
public:
             matrix();
             matrix(int m, int n);
   int       row_size() { return row_sz; }
   int       col_size() { return col_sz; }
   dbl       norm();
   void      fill();
   void      fill(cchr* fname);
   void      identity();
   void      get_space(int m, int n);
   void      release_space();

   dbl*&     operator[](int i) { return el[i]; }
   matrix&   operator=(matrix a);

private:
   int     row_sz;                                                  // row size
   int     col_sz;                                                  // col size
   dbl*    base;
   dbl**   el;
};

class options {
public:
            options();

   void     get_options(int argc, char** argv);
   cchr*    filename() { return fn; }
   cchr*    pgm_name() { return pgm_nm; }
   int      get_fwai() { return fwai; }
   int      get_nwacl() { return nwacl; }
   int      precision() { return prec; }
   off_on   file_option() { return file_opt; }
   off_on   help_option() { return help_opt; }
   off_on   norm_only_option() { return norm_only_opt; }
   off_on   prec_option() { return prec_opt; }
   off_on   test_option() { return test_opt; }
   off_on   time_option() { return time_opt; }
   off_on   verbose_option() { return verbose_opt; }

private:
   char*    fn;
   cchr*    pgm_nm;
   int      o_cnt;
   int      fwai;                                    // first working arg index
   int      nwacl;                            // # of working args on cmnd line
   int      prec;
   off_on   file_opt;
   off_on   help_opt;
   off_on   norm_only_opt;
   off_on   prec_opt;
   off_on   test_opt;
   off_on   time_opt;
   off_on   verbose_opt;

   cchr*    report(off_on val);
   int      store_filename(cchr* s);
   int      store_precision(cchr* s);
};

// ---
// Function prototypes.
//

dbl      chk(matrix a, matrix lu, ivec pv);
void     error_exit_cannot_open(cchr* fname);
void     error_exit_el_not_found(int i, int j, cchr* fname);
int      get_from_cmnd_line(int argc, char** argv);
no_yes   lu_decomp(matrix a, matrix lu, ivec pv);
void     wrt_help(cchr* pgm_name);

ostream&   operator<<(ostream& os, ivec pv);
ostream&   operator<<(ostream& os, matrix a);
