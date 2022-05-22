//stuff


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

double factorial(int n);

int main(int argc, char *argv[]) {
  
  //varaible declaration, float variables must be double
  char testing[100];
  double errin;
  double err = 1;
  double x;
  double ans0 = 0;
  double ans = 1;
  int itr = 0;

  char *i = argv[1];
  char *j = argv[2];

  if ( argc > 1) {

    x = atof(i);
    errin = atof(j);
  }//close if argc

  else {

    printf("Please enter a value for x: ");
    scanf("%lf", &x);

    if (x <= 0) {
      printf("x must be a positive integer, let's try again.\n");
      return -1;
    }//close if x <=0

    printf("Please enter the relative error: ");
    scanf("%lf" , &errin);

    if (errin <= 0 || errin >= 1) {
      printf("Error must be between 0 and 1, let's try again.\n");
      return -1;
    }//close err bounds

  }//close else

  //add magic math here


     while (err > errin) {

     itr = itr + 1;
     ans0 = ans;
     ans = ans + (pow(x, itr) / factorial(itr));
     err = fabs(ans0 - ans);
    
     }//close while 


     printf("After %d terms in the series, exp(%lf) is approx. %lf with an error of %lf.\n", itr, x, ans, err);


  return 0;
}//close main


double factorial(int n) {
  double fact = 1;
  int a;
  for (a = 2; a <= n; a += 1) {
    fact = fact *a;
  }//close if a
  return fact;
}//close double factorial


