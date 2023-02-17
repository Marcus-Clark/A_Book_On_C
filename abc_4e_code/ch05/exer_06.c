#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
   int   a, b, cnt = 0, i;

   srand(time(NULL));
   for (i = 0; i < 1000; ++i) {
      a = rand() % 3 + 1;          /* from 1 to 3 */
      b = rand() % 30 + 1;         /* from 1 to 30 */
      if (b  a <= 1)
       continue;
      assert(b  a > 2);
      printf("%3d\n", ++cnt);
   }
   return 0;
}
