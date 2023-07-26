#include   <iostream.h>
#include   <stddef.h>

typedef struct {
   double   a, b, c;
} data;

int main()
{
   cout << "\n"
           "   offsetof(data, a) = " << offsetof(data, a) << "\n"
           "   offsetof(data, b) = " << offsetof(data, b) << "\n"
           "\n";
}
