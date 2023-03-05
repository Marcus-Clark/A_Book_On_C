#include "multiply.h"

char * multiply(char a[],char b[]){
    static char mul[MAX];
    char c[MAX];
    char temp[MAX];
    int la,lb;
    int i, j, k = 0, x = 0, y;
    long int r =  0;
    long sum = 0;
    la=strlen(a)-1;
        lb=strlen(b)-1;
   
        for(i=0;i<=la;i++){
                a[i] = a[i] - 48; /* ASCII value of character '0' is 48, '1'
                 *is 49 and so on. So if we will subtract 48 from it will become equivalent numeric value from character string. For example:
				 *'0' - 48 = 0
				 *'1' - 48 = 49-48 = 1
				 *'9' - 48 = 57-48 = 9 */
        }

        for(i=0;i<=lb;i++){
                b[i] = b[i] - 48;
        }

    for(i=lb;i>=0;i--){
         r=0;
         for(j=la;j>=0;j--){
             temp[k++] = (b[i]*a[j] + r)%10;
             r = (b[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y = 0;y<x;y++){
             temp[k++] = 0;
         }
    }
   
    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++){
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++){
             if(i <= la+j){
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--){
         mul[j++]=c[i] + 48;
    }
    mul[j]='\0';
    return mul;
}
