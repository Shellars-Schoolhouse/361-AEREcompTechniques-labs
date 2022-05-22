/* 

   Takes input and reports if input is an integer or not. Prints "That is an integer" if it is, "That is not an integer" if it is not. Program should exit with non-zero error code if it was not an integer and with 0 as return code if it was an integer. 

*/

/*algorithm 

1. ask user for input
2. checks if input is integer
   2a.print if it is integer or not 
3. exit with non zero error code if not integer
4. exit with 0 as return in integer
*/

#include<stdio.h>
#include<stdlib.h>

/*
int main ()
{
  
int num;
   printf("Hello! Please give me an integer:");
   if (scanf("%d" , &num))/*checks if input is integer
     printf("That is an integer\n");
   else 
     printf("That is not an integer\n");

return 0;
}
*/
/*doesn't like floats*/
/*
int main () {
  
  
  printf("Hello! Please give me an integer: ");

  int num;
  int i = scanf("%d" , &num);

  if (i == 1) {
    printf("That is an integer\n");
    return 0;
  }
  else {
    printf("That is not an integer\n");
    return 1;
  }

} /*end main*/

  
  
/* this works too */    
int main () {

  float num;
  printf("Hello! Please give me an integer: ");

  scanf("%f" , &num);

  if (num != (int)num) {
    printf("That is not an integer\n");
    return 1;
  }

  else {
    printf("That is an integer\n");
  }

}




    
    
