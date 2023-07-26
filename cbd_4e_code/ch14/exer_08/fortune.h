#include <assert.h>
#include <ctype.h>
#include <fstream.h>
#include <iomanip.h>
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include <time.h>
#include <unistd.h>

class options;

enum no_yes {no, yes};
enum off_on {off, on};

typedef   const char   cchr;

extern const int   limit;
extern const int   maxline;
extern const int   maxstring;
extern options     o;                                     // options are global

class options {
public:
            options();
   void     get_options(int argc, char** argv);
   int      get_ffi() { return ffi; }
   off_on   help_option() { return help_opt; }
   off_on   help_help_option() { return help_help_opt; }
   off_on   help_help_help_option() { return help_help_help_opt; }
   cchr*    pgm_name() { return pgm_nm; }
   cchr*    uc_pgm_name() { return uc_pgm_nm; }           // uppercase pgm name
   off_on   test_option() { return test_opt; }

private:
   char*    pgm_nm;
   char*    uc_pgm_nm;                                    // uppercase pgm name
   int      o_cnt;
   int      ffi;                                            // first file index
   off_on   help_opt;
   off_on   help_help_opt;
   off_on   help_help_help_opt;
   off_on   test_opt;
};

void     find_fortune(cchr* phrase, int n);
no_yes   get_answer(cchr* line);
int      get_int_reply(int min, int max);
void     get_time(char* s);
cchr*    ggetenv(cchr* name);
pid_t    ggetpid();
void     good_bye(cchr* begin_time, int cnt,
                  int f_cnt, cchr* ffn, ofstream& ofs);
void     gremove(cchr* fname);
void     grewind(ifstream& ifs);
void     gsystem(cchr* cmnd);
void     prn_info(cchr* pgm_name);
void     prn_more_info(cchr* pgm_name);
void     prn_much_more_info();
void     save_fortune(ifstream& ifs, ofstream& ofs);
