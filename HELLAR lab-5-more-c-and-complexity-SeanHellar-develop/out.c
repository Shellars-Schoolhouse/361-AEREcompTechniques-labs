//stuff

#include<stdio.h>
#include<stdlib.h>

int main(void) {

  printf("Please enter a new filename: ");

  char *filename;
  filename = (char*) malloc(255 * sizeof(char));
  scanf("%s" , filename);

  FILE * data;
  FILE * data1;

  data = fopen(filename , "r");

  if(data == NULL) {

    data1 = fopen(filename, "w");

    for(int i = 1; i < 101; i++) {

      fprintf(data1, "%d\n" , i);

    }//close for

    printf("File has been created :)\n");
    fclose(data1);

  }//close if

  else {

    printf("File already exists, try again\n");
    fclose(data);
    return 1;

  }//close else
	      
  return 0;
}

