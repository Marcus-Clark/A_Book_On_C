#include <stdio.h>
#include <stdlib.h>

int toss(void);
int main(void) {
	
	
	printf("%d\n", toss());
}

 int toss(void) {

   int HorT = rand() %2;

if ( HorT == 0) {

  printf( "Tails " );
  }

   else
{
  
printf( "Heads " );    }

return HorT;
 }
	
