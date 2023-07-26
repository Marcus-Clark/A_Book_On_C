#include <assert.h>
#include <iomanip.h>
#include <iostream.h>
#include <limits.h>
#include <stdlib.h>
#include <strstream.h>
#include <time.h>

typedef   const char   cchr;

enum no_yes {no, yes};

cchr*   bit_print(short a);
void    chk(short a, short b, short c, short majority);
short   majority(short a, short b, short c);
void    prn_results(short a, short b, short c, short majority);
short   vote();
