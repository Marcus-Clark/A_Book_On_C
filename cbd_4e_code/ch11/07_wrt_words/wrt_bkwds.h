#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>

typedef   const char   cchr;

extern const int   max_line_len;
extern const int   maxword;

void   prn_info(cchr* pgm_name);
void   wrt_bkwds_by_word(ifstream& ifs);
