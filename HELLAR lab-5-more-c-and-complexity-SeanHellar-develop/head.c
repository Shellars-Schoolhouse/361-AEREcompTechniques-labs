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

    printf("File does not exist, try again\n");

    return 1;

  }

  for(int i = 0; i < 3; i++) {

    read = getline(&line, &length, data);

    printf("%s" , line);

  }

  fclose(data);

  return 0;

}

