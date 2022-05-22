
//Exercise 3//

/*
Algorithm for exercise 3 
1.) accept and validate input 
2.) allocate the array
3.) fill the array
4.) output the array 
first to output then to a file 
*/

//write a function to print a NxN test matrix// 


//starting code//


//11111111111111111111111//
/*
Goal: Implement algorithm for creating and printing a spiral matrix

Program Input: An integer n, where 1 <= n <= 100

Program Output: For a given integer n, your program will output to a file named ans.out a n x n matrix such that all the integer numbers between 1 to n^2 are stored in the matrix following the given pattern.

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Write a function to PRINT an NxN  test matrix*/
/* Needed for debugging and can be used for final output*/


//Testing from here************************

void printmatrix(int, int, int);    
  
void print_matrix(int N, int number_width, int **myMatrix) {

  FILE *file;
  file = fopen("ans.out" , "w");

  int m,n; /*loop counters: row, column*/

  for (m = 0; m < N; m++){
    for (n = 0; n < N; n++) {
      printf("%*d" , number_width, myMatrix[m][n]);
    } /*end for n*/
    printf("\n");
  } /*end for m*/
  fclose(file);
  printf("\n");
  
  return; /*return normally*/
} /*end print_matrix */


int main(void) { 
  
  /* 1111111111111111111111111111
     1. Accept and validate input 
     11111111111111111111111111111111*/

    printf("Please give me an integer: ");
    float n;
    int r;

    r = scanf("%f" , &n);

    if(r != 1 || n != (int)n || n > 101 || n <= 0) {

      printf("That is not a valid integer, try again\n");
      return 1;
    }//end if

    int input = (int) n; 
    int number_width = input;
 
 
    /* 2. Allocate the array 
       Using: code from Section 5.3.2 lab manual*/
  
    int **bar; /* double pointer */
  
    bar = malloc(sizeof(int *) * input); /*first allocate the array of int * */
  
    for(int i = 0 ; i < input ; ++i) { /*loop through this array of int * */
    
      bar[i] = malloc(sizeof(int) * input); /*allocate a column of ints each time */
    } /*end for*/
  
    /* 3. Fill the array */
  
    /*first learn to test if I'm doing this right*/


    if(input == 1) {
      bar[0][0] = 1;
    }//end if 


    int row = ceil((input - 1) / 2);
    int col = ceil((input - 1) / 2);

    int d = 0;
    int c = 1;
    int s = 1;

      
    for (int k =1; k < input; k++) {
      for (int j = 0; j<(k<(input-1)?2:3); j++) {
	for (int i = 0; i < s; i++){

	finalinput:
	  bar[row][col] = c;
	  ;
	  if (c == input *input) {
	    goto printstatement;
	  }//end if
	  c++;
	  switch (d)
	    {
	    case 0: col = col + 1; break;
	    case 1: row = row + 1; break;
	    case 2: col = col - 1; break;
	    case 3: row = row - 1; break;
	    }
	  if (c == input * input) {
	    goto finalinput;
	  }//end if
	}
	d = (d+1)%4; //modulo division
      }
      s = s + 1;
    }

  printstatement:
    printf(input, number_width , bar);
    ;
    
    return 0; /*exit normally if I got here */

}
