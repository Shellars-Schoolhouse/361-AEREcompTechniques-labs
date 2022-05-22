/*
Goal:
Ask the user for an integer ’n’, loop n times. Each time, ask the user for a char, check that
the input received is that type, and then either terminate with an error message or ask for
another input until the user has given n correct inputs.*/ 


#include<stdio.h>
#include<ctype.h>


/*int main(void) {
/*Declare variables
char userInputNum; /*this is for when I ask the user for a number, but don't know what type they put*/
/*int numChars = 0; /*number from the user, which is how many times I loop/how many chars*/
/*char userChar; /*note: this may need to be a different type in case the user doesn't enter a char*/

/*Ask the user for an integer
printf("Please enter an integer: ");

/* Read in the input and save it in userInputNum (which is a char) */

/* Check if the userInputNumber is really an integer, then if so, move it to numChars */
/* if (they didn't give an integer) { */
/*   terminate with an error: userInputNum is not an int! /\*print(...*\/ */
/* } /\*end if*\/ */
/* if (the integer is <= 0) {/\*need to exit also*\/} */
/* /\*If I got here, then I know the user entered a positive integer and it's saved in numChars*\/ */
/* /\*Now I can loop numChars times*\/ */

/* Loop (numChars times) { */
/*   /\*Maybe need a check here if we've reached numChars? Depends on the type of loop*\/ */

/*   /\*if we get here, we know that we need at least one more char from the user*\/   */
/*   Ask the user for a char; SAY a char is ... */
/*   Read in the input and save it in userChar */
/*   Check if userChar is really a Char /\*check if it's a-z? A-Z? Nothing else allowed*\/ */

/*   if (they didn't give a char) { */
/*     terminate with an error: userChar is not a char! /\*for terminate, let's use exit(1)*\/ */
/*   } /\*end if the user didn't give a char*\/ */
/*   /\*if I got here, I know the user gave me a good char!*\/ */
/*  print: Thanks for this char. /\*Need to know whether to ask for another char*\/ */
/*     /\*depending on type of loop, see if numChars == numLoops; if so exit loop, not: loop again*\/ */
/* } /\*end loop*\/ */

/* /\*If we get here, we know that the user gave us numChars chars and we printed them*\/ */
/* print a 'thank you' message and return 0; 

 return 0;
} /*end main*/

int main () {

  printf("Hello! How many char should I take? ");

  float num;
  int c;

  c = scanf("%f" , &num);

  if (c != 1 || num != (int)num) {
    printf("That is not an integer, let's try again.");
    return 1;
  }

  printf("Please give me a char: ");

  for(int i = 0; i < num; i++) {

    char chec;
    int a = scanf("%s" , &chec);

    if(isalpha(chec)) {

      if (i == num - 1) {
	printf("Thanks! I am happy with %.0f chars.\n" , num);
	return 0;
      } //close if happy//
      else {
	printf("Thanks! Please give me another char: ");
      }//close else another char//
      
    }//close isalpha//

    else {
      printf("That is not a char, let's try again.\n");
      return 1;
    }//close else not char//

  }//close for//

}//close main//
  
  
