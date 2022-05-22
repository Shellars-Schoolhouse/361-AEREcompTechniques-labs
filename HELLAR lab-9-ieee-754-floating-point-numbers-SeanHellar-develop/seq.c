#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//now i can just include function reference 
long double FunctionSequence(long double, long double);


int main(int argc, char *argv[]) {

  if (argc == 2) {

    if (strcmp(argv[1], "-d") == 0) {

      int a = 21;
      long double x[a];

      x[0] = 11.L/2.L;
      x[1] = 61.L/11.L;

      printf("Iterationn - %d, Value - %Lf \nIteration - %d, Value - %Lf \n", 0, x[0], 1, x[1]);

      long double lastvalue;
      long double currentvalue;

      for (int i = 1; i < a; i++) {

	lastvalue = x[i-1];
	currentvalue = x[i];
	//function goes here
	x[i+1] = FunctionSequence(lastvalue,currentvalue);
	printf("IIteration - %d, Value - %Lg \n", i+1, x[i+1]);
      }//end for int i

    }//end if string comparison

    else {

      printf("Not the correct type of arguement (Expected -d)\n");
    }//end else

  }//end if argc=2

  else if (argc == 1) {

    int a = 11;
    long double x[a];

    x[0] = 11.L/2.L;
    x[1] = 61.L/11.L;

    printf("Itteration - %d, Value - %Lf \nIteration - %d, Value - %Lf \n", 0, x[0], 1, x[1]);

      long double lastvalue;
      long double currentvalue;

      for (int i = 1; i < a; i++) {

	lastvalue = x[i-1];
	currentvalue = x[i];
	//function goes here
	x[i+1] = FunctionSequence(lastvalue,currentvalue);
	printf("Iteeration - %d, Value - %Lg \n", i+1, x[i+1]);
      }//end for int i

  }//end else if
  
} //end int main

long double FunctionSequence (long double previous, long double current) {

  long double result;
  result = 111.L - ( 1130 * previous - 3000 ) / ( current * previous );
  return result;
}//end function sequence 
