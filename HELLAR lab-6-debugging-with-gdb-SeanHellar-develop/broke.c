#include <math.h>
#include <stdio.h>

// Thanks to Dr. Jeff Donahoo at Baylor University

int ComputeFactorial(int number) {
  int facto = 1;//change from 0 to 1

  for (int j = 1; j <= number; j++) {
    facto = facto * j;
  }//close for

  return facto;
}//close int computefactorial

double ComputeSeriesValue(double x, int n) {
  double seriesValue = 0.0;

  for (int k = 0; k <= n; k++) {
    seriesValue += x / ComputeFactorial(k);
  }//close for

  return seriesValue;
}//close double series value

void StringTest() {
  char temp[5] = "HelLo";//create 5 array

  int i;
  i=0;

  temp[3]='l';

  for (i =0 ; i < 5 ; i++ ) 
    printf("%c\n", temp[i]);
    //possible for loop missing {}
}//close void string

int main() { //possible needed void
  printf("This program is used to compute the value of the following series :\n");
  printf("x/0! + x/1! + x/2! + x/3! + x/4! + ........ + x/n! ");//added ; here

  double x = 0;//changed double to int
  //int x;//added declaration of x
  printf("Please enter the value of x : ");
  scanf("%lf", &x);//added ; here

  int n;//added = 0
  printf("Please enter an integer value for n :");
  scanf("%d", &n);

  //seg fault occurs right before here
  double seriesValue = ComputeSeriesValue(x, n);
  printf("The value of the series for the values entered is %lf\n", seriesValue);

  printf("String testing...\n");
  StringTest();

  return 0;
}//close int main

