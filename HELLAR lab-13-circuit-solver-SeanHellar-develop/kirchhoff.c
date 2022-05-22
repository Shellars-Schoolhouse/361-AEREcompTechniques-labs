#include <stdlib.h>
#include<stdio.h>
#include<string.h>



int varcounter(FILE *);
int linecounter(FILE *);
int eqcheck(FILE *);

typedef struct {

	double resistance;
	int equation;
	char *key;

}Node;//end typedef

typedef struct {

	char *variable;
	int index;
}Variable;//end  struct 


int main (int argc, char *argv[]) {

	FILE *file = fopen(argv[1], "r");
	FILE *vars = fopen(argv[2], "r");

	char line[1000];
	char *token;
	char **variables;
	char ***stepEq1;

	int count = varcounter(vars);
	int eqns = linecounter(file);

	variables = malloc(sizeof(char *) * (count));

	stepEq1 = malloc(sizeof(char **) * eqns);
	for (int i = 0; i < eqns; i++) {

		stepEq1[i] = malloc(sizeof(char *) * eqns);
	}//end for int i

	int x = 0; 

	while (fgetc(vars) != EOF) {

		fseek(vars, 12, SEEK_CUR);

		fgets(line, 1000, vars);

		token = strtok(line, "i");//hopefully will seperate at i

		while (token != NULL) {

			if (x == 0) {

				token = strtok(NULL, "i");
			}//end if x

			if (x < count) {

				variables[x] = token;
				
				printf("Variable %d = %s \n", x, token /*variables[x]*/);
				
				token = strtok(NULL, "i");
				x++;

			}//end if x<count

			else {

				token = strtok(NULL, "i");
			}//end else 

		}//end while token
	}//end while fgetc
	
	fclose(vars);
	printf("\n"); 

	x = 0;

	while (fgetc(file) != EOF) {

		int var = 0;

		fseek(file, 8, SEEK_CUR);

		fgets(line, 1000, file);

		token = strtok(line, " ");

		while (token != NULL) {

			if (atoi(token) == 0) {

				break;
			}//end if atoi

			stepEq1[x][var] = token;

			printf("%s ",stepEq1[x][var]);

			token = strtok(NULL, " ");

			var++;
		}//end while

		x++;
		printf("\n");
	}//end while fgetc

	int a = 0;

	for (int i = 0; i < eqns; i++) {

		if (stepEq1[i][1] != NULL) {

			a++;
		}//end if step

	}//end for int i

	printf("%d\n",a);


}//end main 


int varcounter(FILE *file) {

	int count = 0;
	char line[1000];
	char *token;

	while (fgetc(file) != EOF) {

		fseek(file, 12, SEEK_CUR);

		fgets(line, 1000, file);

		token = strtok(line, " ");

		while (token != NULL) {

			count++;
			token = strtok(NULL, " ");

		}//end while token

	}//end while fgetx

	fseek(file, 0, SEEK_SET);

	return count -2;

}//end int varcount 


int linecounter(FILE *file) {

	int count = 0;
	char line[1000];
	char *token;

	while (fgetc(file) != EOF) {

		fgets(line, 1000, file);
		count++;

	}
	fseek(file, 0, SEEK_SET);

	return count;

}//end int linecounter