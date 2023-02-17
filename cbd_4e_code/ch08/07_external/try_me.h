/*
// The keyword extern means
//
//    "look for it elsewhere, either
//     in this file or in some other file"
//
// In this header file we are not allocating
// space for variables; that gets done in
// the .c files.
*/

#include <stdio.h>

typedef   const char   cchr;

extern cchr*   msg;

extern int     a;
extern int     b;
extern int     c;

void increment_all(void);     /* fct prototypes */
void decrement_all(void);
void print_all(void);
