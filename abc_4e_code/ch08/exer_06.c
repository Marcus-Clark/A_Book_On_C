#include <stdio.h>

int main(void)
{
   printf("%s%s\n%s%s\n%s%d\n%s%d\n%s%s\n",
      "__DATE__ = ", __DATE__,
      "__FILE__ = ", __FILE__,
      "__LINE__ = ", __LINE__,
      "__STDC__ = ", __STDC__,
      "__TIME__ = ", __TIME__);
   return 0;
}
