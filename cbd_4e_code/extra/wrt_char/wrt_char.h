#include <assert.h>
#include <ctype.h>
#include <fstream.h>
#include <iomanip.h>
#include <limits.h>                                       // for CHAR_BIT
#include <stdio.h>                                        // for tmpnam()
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include <termios.h>
#include <unistd.h>                                       // for isatty()

class action;
class options;
class field_width;

enum off_on {off, on};

typedef   const char     cchr;
typedef   const int      cint;
typedef   unsigned int   uint;
typedef   field_width    f_w;

// ---
// mnc = minimum number of columns needed in an xterm window
// mnl = minimum number of lines needed in an xterm window
//

cint   maxline   = 300;
cint   maxstring = 100;
cint   mnc       = 92;
cint   mnl       = 17;

extern cchr*     repr[];
extern cchr*     name[];
extern options   o;                                 // options are global

// ---
//  ncols = number of columns in the current xterm window
// nlines = number of lines in the current xterm window
//

extern int   ncols;
extern int   nlines;

class action {
public:
   void   runrun();
   void   wrt_heading();

private:
   //
   // The variables c an cc are a pair in the sense
   // that we use cc to capture the value in c.
   //
   unsigned char   prev;
   unsigned char   c;
   unsigned int    cc;
   int             cnt;


   cchr*   bit_print(char c);
   void    set_heading(cchr**& h, int& len, int& sz);
   void    wrt_char();
   void    wrt_my_more();
};

class field_width {
public:
          field_width() { xfw = 0; }
          field_width(int n) { xfw = n; }
   int    value() { return xfw; }
   void   set(int n) { xfw = n; }
   f_w&   operator()(int n) { xfw = n; return *this; }

private:
   int   xfw;                                          // xfw = hidden fw
};

class options {
public:
            options();
   void     get_options(int argc, char** argv);
   cchr*    local_pgm_name() { return local_pgm_nm; }
   cchr*    pgm_name() { return pgm_nm; }
   off_on   alt_input_option() { return alt_input_opt; }
   off_on   help_option() { return help_opt; }
   off_on   keyboard_option() { return keyboard_opt; }
   off_on   rationale_option() { return rationale_opt; }
   off_on   test_option() { return test_opt; }
   off_on   wrt_all_names_option() { return wrt_all_names_opt; }
   off_on   wrt_everything_option() { return wrt_everything_opt; }

private:
   char*    local_pgm_nm;
   cchr*    pgm_nm;
   int      o_cnt;
   int      fwai;                              // first working arg index
   int      nwacl;                      // # of working args on cmnd line
   //
   // The next two variables
   // have opposite values.
   //
   off_on   alt_input_opt;
   off_on   keyboard_opt;
   off_on   help_opt;
   off_on   rationale_opt;
   off_on   test_opt;
   off_on   wrt_all_names_opt;
   off_on   wrt_everything_opt;

   void     get_local_pgm_nm();
};

void    chk_xterm_window();
void    error_exit_cannot_get_here(cchr* fct_name);
void    error_exit_xterm_window_too_small();
void    gremove(cchr* fname);
void    grewind(istream& is);
void    grewind(ostream& os);
void    gsystem(cchr* cmnd);
int     gtcgetattr(int fd, termios* termios_p);
int     gtcsetattr(int fd, int optional_actions, const termios* termios_p);
cchr*   report(int val);
cchr*   report(off_on val);
void    set_bits(termios& t);
void    wrt_all_names();
void    wrt_c_cc_array(const termios& t);
void    wrt_help(cchr* pgm_name);
void    wrt_msg_to_user();
void    wrt_rationale(cchr* pgm_name);

ostream&   operator<<(ostream& os, field_width fw);

//
// In the end, the following were not used.
//

ios& left(ios& s);
ios& right(ios& s);
