// ---
// With this program we experiment with
// variations on the error line.
//

#include <iostream.h>

int main()
{
   char   *p[2][3] = {{"abc", "defg", "hi"},
                      {"jklmno", "pqrstuvw", "xyz"}};

   cout << "\n"
           "*(*(p + 1) + 1)[-3] = " << *(*(p + 1) + 1)[-3]   << "\n" 
           "*(*(p + 1) + 1)[-2] = " << *(*(p + 1) + 1)[-2]   << "\n" 
           "*(*(p + 1) + 1)[-1] = " << *(*(p + 1) + 1)[-1]   << "\n" 
           "*(*(p + 1) + 1)[+0] = " << *(*(p + 1) + 1)[+0]   << "\n" 
           "*(*(p + 1) + 1)[+1] = " << *(*(p + 1) + 1)[+1]   << "\n" 
           "*(*(p + 1) + 1)[+2] = " << *(*(p + 1) + 1)[+2]   << "\n" 
           "*(*(p + 1) + 1)[+3] = " << *(*(p + 1) + 1)[+3]   << "\n" 
           "*(*(p + 1) + 1)[+7] = " << *(*(p + 1) + 1)[+7]   << "\n" 
           "\n";
}