#include <assert.h>
#include <ctype.h>
#include <errno.h>                               // for use with perror()
#include <fstream.h>
#include <iomanip.h>
#include <stdio.h>                           // for perror() and tmpnam()
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include <unistd.h>
#include <sys/stat.h>                                       // for stat()
#include <sys/time.h>                                     // for utimes()
#include <sys/types.h>                                      // for stat()

class fname_ext;
class options;

enum kcs      {c, cpp, mixed, none, error};      // kind of comment style
enum no_yes   {no, yes};
enum off_on   {off, on};

typedef   const char   cchr;
typedef   const int    cint;

cint   default_right_edge = 73;
cint   maxline            = 700;
cint   maxstring          = 100;
cint   maxword            = 100;
cint   tabstop            = 8;

extern cchr*     file_extensions;
extern cint      default_right_edge;
extern int       right_edge;
extern cint      tabstop;
extern options   o;                                 // options are global

class fname_ext {
public:
           fname_ext();
           ~fname_ext();
   int     maxlen() { return mlen; }
   int     size() { return sz; }

   cchr*   operator[](int i) { return el[i]; }

private:
   char**   el;
   int      sz;
   int      mlen;
};

class options {
public:
            options();
   void     get_options(int argc, char** argv);
   cchr*    pgm_name() { return pgm_nm; }
   int      get_fwai() { return fwai; }
   int      get_nwacl() { return nwacl; }

   off_on   force_option() { return force_opt; }
   off_on   help_option() { return help_opt; }
   off_on   right_edge_option() { return right_edge_opt; }
   off_on   style_option() { return style_opt; }
   kcs      get_style() { return sty; }
   off_on   test_option() { return test_opt; }

private:
   cchr*    pgm_nm;
   int      o_cnt;
   int      fwai;                              // first working arg index
   int      nwacl;                      // # of working args on cmnd line
   int      re;                              // same as global right_edge
   kcs      sty;                                 // kind of comment style
   off_on   force_opt;
   off_on   help_opt;
   off_on   right_edge_opt;
   off_on   style_opt;
   off_on   test_opt;

   int      store_right_edge(cchr* s);
   int      store_style(cchr* s);
};

void     adjust_comment(cchr* fname, int cnt, char* line, char* cp);
void     c_align(cchr* fname, cchr* tfn);
void     change_comment_style(char* comment);
void     chk_filenames(int argc, char** argv);
void     copy(cchr* from, cchr* to);
void     error_exit_cannot_access(cchr* fname);
void     error_exit_cannot_get_here(cchr* place);
void     error_exit_cannot_open(cchr* fname);
void     error_exit_closing_char_not_found(cchr* fn, cchr c, int ct, cchr* li);
void     error_exit_comment_not_closed(cchr* fname, int cnt, cchr* line);
void     error_exit_filename_ext_not_found(cchr* fname);
void     error_exit_mixed_comment(cchr* fn, int cnt, cchr* li, cchr* comm);
void     error_exit_not_a_comment(cchr* fn, int cnt, cchr* li, cchr* comm);
void     error_exit_positive_integer_required(int re);
void     error_exit_right_edge_not_found();
void     error_exit_right_edge_not_found(cchr* s);
void     error_exit_style_not_found();
void     error_exit_style_not_found(cchr* s);
void     error_exit_wrong_filename_ext(cchr* fname);
kcs      get_comment_style(cchr* comment);
void     get_file_times(cchr* fn, int& last_access_ti, int& last_modify_ti);
void     gremove(cchr* fname);
void     grewind(istream& is);
void     gstat(cchr* fname, struct stat* statbuf_ptr);
void     gsystem(cchr* cmnd);
void     gutimes(char* fname, struct timeval* tvp);
no_yes   is_blank(cchr* line);
no_yes   is_define_line(cchr* line);
char*    move_to_closing_char(char* p);
void     pretty_up(char* comment, kcs style);
cchr*    report(kcs val);
cchr*    report(off_on val);
void     restore_file_times(cchr* fn, int last_access_ti, int last_modify_ti);
void     strip(char* s);
void     untab(cchr* fname);
void     view(cchr* tfn);
void     wrapup(ifstream& ifs, ofstream& ofs, cchr* tfn);
void     wrt_help(cchr* pgm_name);
  
ostream&   operator<<(ostream&, fname_ext e);

// ---
// 5 May 98
//
// According to the man page for utimes(), the function prototype
// should be in the following file:
//
//    #include <sys/time.h>
//
// Well, it is there, but buried in an unexpected way.  After we
// extract it, here it is:
//
//    int   utimes(const char *, const struct timeval *);
//
// Unfortunately, this does not coincide with what is in the man
// page, which is the following:
//
//    int utimes(const char *path, const struct timeval times);
//
// Most likely the man page is wrong.  If we use the first function
// prototype directly, then version 4.2 of the Sun C++ compiler cannot
// find the associated object file in the standard C++ library.  But
// note that "pointer to a const struct" is not what we want anyway.
// Hence we drop the const and pick up the object file from the C
// standard library.
//

extern "C" {
   int   utimes(char* file, struct timeval* tvp);
}
