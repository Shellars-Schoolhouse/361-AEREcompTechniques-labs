#include<stdlib.h>
#include<math.h>
#include<stdio.h>
//allows us to use string functions
#include<string.h>
#include<ctype.h>

/* varibale declartion */
int DecimalToBinary(int); 
int BinaryToDecimal(char*);
int FractionToBinary(double);
double BinaryToFraction(char*);


int main (int argc, char* argv[]) {

  if (argc > 3) {

    printf("Please enter only 2 arguments \n");

    return -1;
  }//end if argc > 3

  if (strcmp(argv[1], "-b") == 0) {

    int i = 0;

    for (i = 0; i < strlen(argv[2]); i++) {

      if (argv[2][i] == '.') {

	break;
      }//end if argv2i

    }//end for i<strlen

    char *intnum;
    intnum = malloc(sizeof(char) * i);

    for (int j = 0; j < i; j++) {

      int value = argv[2][j];

      if(isdigit(value) != 0 || argv[2][j] == '.') {

	intnum[j] = argv[2][j];
      }//end isdigit
      else {
	printf("%s\n", intnum);
	printf("Invalid input\n");
	return 1;
      }//end else
    }//end for int j

    char *fractionNum;
    fractionNum = malloc(sizeof(char) * (strlen(argv[2]) - i) );

    int k=0;
    for (int m = i; m < strlen(argv[2]); m++) {

      int value = argv[2][m];

      if(isdigit(value) != 0 || argv[2][m] == '.') {

	fractionNum[k] = argv[2][m];
	k++;
      }//end if isdigit

      else {
	printf("%s\n", intnum);
	printf("Invalid input\n");
	return 1;
      }//end else
    }//end for int m=i

    int integer = BinaryToDecimal (intnum);
    double fraction = BinaryToFraction (fractionNum);

    printf("%g \n", integer + fraction);

    return 0;

  }//end if strcmp

  else if (strcmp(argv[1], "-d") == 0) {

    int i = 0;
    for (i = 0; i < strlen(argv[2]); i++) {

      if(argv[2][i] == '.') {
	break;
      }//end if argv2i
    }//end for i<strlen

    char *intnum;
    intnum = malloc(sizeof(char) * i);

    for (int j = 0; j < i; j++) {
      int value = argv[2][j];

      if(isdigit(value) != 0 || argv[2][j] == '.') {
	intnum[j] = argv[2][j];
      }//end if isdigit

      else {

	printf("%s\n", intnum);
	printf("Invalid input \n");
	return 1;
      }//end else
    }//end for int j

    char *fractionNum;
    fractionNum = malloc(sizeof(char) * (strlen(argv[2]) - i) );

    int k = 0;
    for (int m = i; m < strlen(argv[2]); m++) {

      int value = argv[2][m];

      if(isdigit(value) != 0 || argv[2][m] == '.') {

	fractionNum[k] = argv[2][m];
        k++;
      }//end isdigit
      else {

	printf("%s \n", fractionNum);
	printf("Invalid Input\n");

	return 1;
      }//end else
      
   
    }//end for m<strlen

    /*lmao i need better variable names*/ 
    int intnum2 = atoi(intnum);
    double fractionNum2 = atof(fractionNum);

    DecimalToBinary(intnum2);
    FractionToBinary(fractionNum2);

    return 0; 
  }//end elseif

  else {

    printf("Please enter valid input \n");
    return 1; 
  }//end else


  //return 0;
}//end int main




int DecimalToBinary(int n) {

  int count = 0;
  int modify = n;

  while (modify > 0) {

    modify = modify/2;
    count++;
  }//end while modify

  char array[count];
  int i = 0;
  int value;

  while (n > 0) {

    value = n % 2;
    array[i] = value;
    n = n / 2;
    i++;
  } //end while n>0

  for (int m = count -1; m >= 0; m --) {
    printf("%d", array[m]);
  }//end for int m

  printf(".");

  return 0;
  
} //end int D2B



int BinaryToDecimal(char *x) {

  int val2 = 0;
  for (int i = 0; i < strlen(x); i++) {

    int binaryval = x[i] - '0';
    val2 = 2 * val2 + binaryval;
  }//end for i<strlen

  return val2;

}//end B2D


int FractionToBinary(double o) {

  double p = o;

  for (int i = 0; i < 11; i++) {

    p = p * 2;
    printf("%d", (int) fmod(p,2) );

    if (p >= 1) {
      p = p - 1;
    }//end if p

    if (p == 0) {
      break;
    }//end if p

  }//end for int i

  printf("\n");

  return 0;

}//end int F2D



double BinaryToFraction(char *m) {

  double val2 = 0;

  for (int i = strlen(m) - 1; i > 0; i--) {

    int binaryval = m[i] - '0';
    val2 = (binaryval + val2) / 2;
    
  }//end for i=strlen

  return val2;
}//end it B2F





    
