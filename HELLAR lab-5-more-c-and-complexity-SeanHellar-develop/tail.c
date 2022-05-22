//stuff


#include<stdio.h>
#include<stdlib.h>

int main(void) {

  printf("Please enter a filename: ");

  char *filename;
  filename = (char*) malloc(255 * sizeof(char));
  scanf("%s" , filename);

  FILE * data;
  char * line = NULL;
  size_t length = 0;
  ssize_t read;

  data = fopen(filename , "r");

  if(data == NULL) {

    printf("FIle does not exist, try again\n");

    return 1;

  }

  int counter = 0;
  fseek(data, 0, SEEK_END);
  while(counter < 3) {

    fseek(data, -2, SEEK_CUR);

    if(fgetc(data) == '\n') {

      counter++;

    }//end if
  }//end while

  for(int i = 0; i < 3; i++) {

    read = getline(&line, &length, data);

    printf("%s" , line);

  }//end for

  fclose(data);

  if(line) {

    free(line);

  }//end if

  free(filename);

  return 0;
  
}//end main
