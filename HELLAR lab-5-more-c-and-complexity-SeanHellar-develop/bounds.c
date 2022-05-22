//Exercise 2


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//int power(int, int);

int main(void) {
  
  int s;
  float num;
  
  printf("Please enter size of array: ");
  s = scanf("%f" , &num);

  if (s != 1 && num != (int)num || num > 250 || num < 1) {

    printf("That is not a valid integer\n");
    return 1;
    
  }//close if


  float * array;
  array = (float*)malloc(sizeof(float) * num);

  for(int i = 0; i < num; i++) {

    array[i] = 1 + pow(i, 2) + pow(i, 3) / 3.0;
  }//close for

  int t;
  float numb;
  
  printf("Please enter an element to be retrieved: ");
  t = scanf("%f" , &numb);

  if (s != 1 && numb != (int)numb || numb > num || numb < 1) {

    printf("That is not a valid integer\n");
    return 1;
  }//close if

  printf("This element number is  %d - %.3f\n" , (int)numb, array[(int)numb - 1]);

  free(array);

  return 0;
  
}//close main

