



/* my algorithm 
1. promt the user for an integer n 
2. read/check that input is an integer 
   2a. if not integer program should terminate here
3. print the number from the main function 
4. call a function to compute the sum from 1 to user integer

 BFA function 
 1. print message telling user that it has begun adding numbers 
 2. add the number from 1 to user integer in a loop
 3. print the sum with message and terminate 

 GA function 
 1. print message telling user that it has begun adding numbers
 2. add the numbers from 1 to user integer using gaussian formula
 3. print the sum with message and terminate 

5. Run with linux time command for both 
*/

#include<stdio.h>

int main() {

  float num;
  int c;

  printf("Hello! Please enter an integer to sum: ");

  c = scanf("%f" , &num);

  int sum;

  if( c == 1 && num == (int)num) {

    sum = num + 1;
  }//close if//

  else {
    printf("That is not an integer, let's try again.\n");
    return 1;
  }//close else//

  long int total = 0;
  for(long int i = 0; i < sum; i++) {
    total += i;
  }//close for//

  printf("Total sum with BFA is %ld\n" , total);

}//close main
  
  
      
