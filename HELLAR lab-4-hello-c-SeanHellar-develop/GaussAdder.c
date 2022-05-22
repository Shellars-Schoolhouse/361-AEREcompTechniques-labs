/* use same structure as BFA, switch out for loop with given eqation*/

#include<stdio.h>

int main() {

  float num;
  int c;

  printf("Hello! Please enter an integer to sum: ");

  c = scanf("%f" , &num);

  long int gauss;

  if( c == 1 && num == (long int)num) {

    gauss = ( num * (num +1) ) / 2 ;
  }//close if//

  else {
    printf("That is not an integer, let's try again.\n");
    return 1;
  }//close else//

   printf("Total sum with GA is %ld\n" , gauss);

}//close main//


