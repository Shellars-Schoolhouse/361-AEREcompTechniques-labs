/* 

Loop 5 times. Each loop ask the user for an integer and check that input is an integer and terminate OR ask for another input until user has given five corect inputs. 

*/

/* Algorithm 

1. Create finite loop of 5 times. 
2. Each loop will ask user for integer input
   2a. Each loop will check if input is integer 
   2b. If input is not integer print error and terminate
3. When 5 integers are given end loop, print happiness. 

*/

/*basic code to loop 5 times
#include<stdio.h>

int main(void) {

int a = 1;

while (a < 4){
  printf("Hello World!\n");
  a++;
 }end while
 return 0;
}/*end main 
*/

/*test code to see how input works
int main( ) {

   int c;

   printf( "Enter a value :");
   c = getchar( );

   printf( "You entered:\n ");
   putchar( c );

   return 0;
}
*/


/*exericse 8 code hopefully*/

#include<stdio.h>
#include<stdlib.h>
/*current work on pause
int main(void) { /*start main loop

  int a = 1; /* intializes my while loop

  while (a < 6){
    int c;

    printf("Enter an integer :\n");
    c = getchar();
    if (scanf("%d", &c))
      printf("Thanks! Please give me another input", c);
    else
      printf("Input was not an integer, let's try again");
    return 0;/*for integer check
    a++;/*creates next loop
  }/*end while loop
  



  return 0;/*for main loop
}/*end main loop*/

/*trying just the if statement
int main() 
{/*for main

  int a = 1; /*intializes while loop
  while (a < 6){ 

    int c;
      printf("Hello! Please give me an integer:");
      if (scanf("%d" , &c)) {  //checks if input is integer//
	continue;
      }
      	
      else {
	printf("Input was not an integer, let's start over\n");
	break;
      }

      a++;
      
      if (a = 6) {
	printf("Thanks! I am happy with five integers.\n");
	  return 0;
      }
      else {
	printf("You did not enter 5 integers, let's start over.\n");
	  return 1;
      }
      

  }/*ends while loop*/

  /* if reached prints final statement
  //* printf("Thanks! I am happy with five integers.\n");
  
return 0; /*for first main loop  

}/*end first main loop*/

/*

int main () {
    for (int i = 0; i < 5; i++) {
    
      float num;

      if (i == 0) {
	printf("Hello! Please give me an integer: ");
	scanf("%f" , &num);
      }


      if (i == 1 && i < 5) {
	printf("Thanks! Please give me another integer; \n");
      }

      if (i == 4) {
	printf("Thanks! I am happy with five integers. \n");
      }


      
      if(num == (int)num) {
	//printf("That is an integer\n");
      }
      else {
	//printf("That is not an integer\n");
	break;     
      }
      
    }//end for//

} /*end main*/

int main() {

  printf("Hello! Please give me an integer: ");
  int i;
  for(i = 0; i < 5; i++) {

    int num;
    int j = scanf("%d", &num);

    if (j == 1) {

      if(j == 4) {

	printf("Thanks! I am happy with five integers.\n");
	  }
      else {

	printf("Thanks! Please give me another integer: ");
	  }
      continue;
    }
    else {
      printf("That is not an integer, let's try again.\n");
	break;
    }
  }//for loop
    
}//main loop
