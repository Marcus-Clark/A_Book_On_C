#include <assert.h>
#include <ctype.h>
#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>

enum no_yes {no, yes};

typedef   const char   cchr;

extern const int   maxline;
extern const int   maxstring;

void   bubble_str(char* s);
void   prn_info(cchr* pgm_name);
void   swap(char& c1, char& c2);
void   swap(no_yes& a1, no_yes& a2);
