#include <stdio.h>
int main(){


FILE *fpr; 
    fpr = fopen("100_rand", "r");




int count = 0, value;


double sum = 0.0;


while ( fscanf(fpr, "%d", &value ) == 1 ) {
  sum += value;
  count++;
}


printf("The average weight is %lf",sum/count);


        fclose(fpr);


        return 0;


}
