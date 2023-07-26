#include <assert.h>
#include <iostream.h>
#include <stdlib.h>

class elem;                                                 // incomplete types
class stack;

enum no_yes {no, yes};

typedef   char         data;                            // keep the data simple
typedef   const char   cchr;

extern const int   maxdata;
extern const int   maxline;

extern const int   empty;
extern const int   full;

class stack {
public:
            stack();                                             // constructor
   no_yes   is_empty();
   no_yes   is_full();
   data     get_top();
   data     pop();
   void     push(data d);
   void     reset();

private:
   data*   s;                                              // a pointer to data
   int     top;                                      // an index into the array
};
