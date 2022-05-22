#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>




//qaudratice eqaution solver
//somehow needs a binary file

int main(int argc, char *argv[]) {

  /*
    double a,b,c;*/
  long double i,r1,r2;
  long double c1p,c1n;
  long double e1;
  long double a1p,a1n;
  

  long double a = atof(argv[1]);
  long double b = atof(argv[2]);
  long double c = atof(argv[3]);
  
  /*input arugments indiviudally 
  printf("Please enter a,b,c of the quadratic equation: ");
  //checks all input are floats
  scanf("%lf%lf%lf",&a,&b,&c);
  */

  //making this "robust"
  for (int d = 1; d < 4; d++) {

    for (int f = 0; f < strlen(argv[f]); f++) {

      int value = argv[d][f];

      if (isdigit(value) != 0 || argv[d][f] == '.' || argv[d][f] == '-' || argv[d][f] == 'e' || argv[d][f] == '*' || argv[d][f] == '^' ) {

	continue;
      }//end if isdigit

      else {

	printf("Invalid Input \n");
      }//end else

    }//end for int f

  }//end for d
	



  //check to see if roots are imaginary
  i = (b*b) - 4*a*c ;
  printf("Discriminant is %Lf \n", i);


  if (a==0) {

    a1p = (2*c) / ( (-b) -( sqrtl(i)) ) ;
    a1n = (2*c) / ( (-b) + sqrtl(i) ) ;

    printf("Roots are %.5Lf, %.5Lf \n", a1p,a1n);

    return 0;

  } //end if a==0


  if (i<0) {

    printf("Roots are imaginary\n");

    
    
    /*
    c1p = (-b)/(2*a) + sqrtl(-i)/(2*a);
    c1n = (-b)/(2*a) - sqrtl(-i)/(2*a);
    printf("Roots are %.5fi, %.5fi \n", c1p,c1n);
    */ //apparently we can just break
    return -1;

  }//end if

  else if(i==0) {

    printf("Roots are the same \n");

    e1 = (-b)/(2*a) ;
    printf("Roots are %.3Lf \n", e1);

    return 0;

  }//end else if

  else {

    printf("Roots are real numbers \n");

    r1 = ( (b*-1) + sqrtl(i) ) / (2*a) ;
    r2 = ( (b*-1) - sqrtl(i) ) / (2*a) ;

    printf("Roots are %.5Lf, %.9Lf \n", r1,r2);

    return 0;

  }//close else
  

  return 0;

}// end int main 

/*check to divide by big number */




