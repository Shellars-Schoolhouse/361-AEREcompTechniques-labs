#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

double Err = 1e-4;
int EOI = 10;
#define ROW_SIZE 1000
int count;

double ans[10];

int getfilesize(FILE *);
void gaussSeidel (int, double **);
void changeErrandEOI ();


int main(int argc, char *argv[]) {

    changeErrandEOI ();

        if (Err == -1 || EOI == -1) {

            return 4;
        }//end if Err
    

	if (argc == 2) {

		//file input stuff

		char *filename = argv[1];

        FILE *file = fopen(filename, "r");

        if (file == NULL) {

            fprintf(stderr, "File does not exist \n");
            return -2;
        }//end for if FILE 


        int rows = getfilesize(file);
        int cols = rows + 1;
        fprintf(stderr, "Matrix size gotten R=%d, C=%d, Continue \n", rows, cols);


        double **A;
        A = malloc(sizeof(double *) * (cols));

        for (int i = 0; i < rows; i++) {

            A[i] = malloc(sizeof(double) * rows);
        }//end for int i 
        fprintf(stderr, "Matrix created, continue \n");


        char row[ROW_SIZE];
        char *token;

        for (int i = 0; i < rows; i++) {

            fgets(row, ROW_SIZE, file);
            token = strtok(row, ",");

            for (int j = 0; j < cols; j++) {

                double value = atof(token);
                A[i][j] = value;
                token = strtok(NULL, ",");
            }//end for int j

        }//end for int i
        fclose(file);
        printf("Filled matrix, continue \n");

        gaussSeidel(rows, A);
        printf("Math done, continue \n");

        FILE *ansCSV = fopen("ans.csv", "w");
        for (int e = 0; e < rows; e++) {

            fprintf(ansCSV, "%g \n", ans[e]);
        }//end for int e


        int NNZ = rows * cols; 

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j <cols; j++) {

                if (A[i][j] == 0) {
                    NNZ--;
                }//end for if A
            }//end for int j
            
        }

        free(A);

        double savings = 1. - ((double)NNZ / ((double)rows *(double)cols));

        fprintf(stderr, "Compressed matrix contains %d elements, compressed by %g%% \n", NNZ, 100*savings);

        return 0;

	}//end if argc == 2


	else if (argc == 1) {

		//human input 
		printf("\nHow many equations: ");
		int noe; //nummber of equations
		
        int check = scanf("%d", &noe);

        if (check != 1 || (int)check != check) {

            fprintf(stderr, "Incorrect number of equations \n");
            return 1;
        } //end if check
        printf("\n");


		//i am confusion

        double **A;
        A = malloc(sizeof(double *) * (noe));

        for (int i = 0;i < noe; i++) {

            A[i] = malloc(sizeof(double) * noe + 1);
        }//end for int i

        //ans = malloc(sizeof(double) * noe);



        for (int i = 0; i < noe; i++) {

            for (int j = 0; j < noe+1; j++){

                printf("A[%d][%d] = ", i, j);

                double value;
                int check = scanf("%lf", &value);

                if (check != 1 || (double)value != value) {

                    fprintf(stderr, "Incorrect number of equations \n");
                    return 2;
                }//end for if check

                A[i][j] = value;
            }//end for int j
        }//end for int i

        gaussSeidel(noe, A);
        printf("\n");

        for (int e = 0; e < noe; e++) {

            fprintf(stderr, "x%d = %g \n", e, ans[e]);
        }//end for int e

        int NNZ = noe * (noe + 1); 

        for (int i = 0; i < noe; i++) {

            for (int j = 0; j <noe + 1; j++) {

                if (A[i][j] == 0) {
                    NNZ--;
                }//end for if A
            }//end for int j
            
        }

        free(A);

        double savings = 1. - ((double)NNZ / ((double)noe *(double)(noe + 1)));

        fprintf(stderr, "Compressed matrix contains %d elements, compressed by %g%% \n", NNZ, 100*savings);

        return 0;

	}//end elseif

    else {

        fprintf(stderr,"Incorrect arguement count \n");
        return -1;
    }



	//stuff 
}//end main 



int getfilesize(FILE * data) {

    int rows = 1;

    for (char c = getc(data); c != EOF; c = getc(data)) {

        if (c == '\n') {

            rows++;
        }//end if c

    }//end for char 

    fseek(data, 0, SEEK_SET);
    return rows;
}//end int getfilesize



void gaussSeidel(int noe, double **matrix) {

    count = 1;
    int ready = 0;

    while (ready < noe && count < EOI) {
        printf("\nIter %d ", count);
        for (int i = 0; i < noe; i++) {

            int previous = ans[i];
            ans[i] = matrix[i][noe];

            for (int j = 0; j < noe; j++) {

                //int previous = ans[i];
                //ans[i] = matrix[i][noe];

                if(j != i) {

                    ans[i] = ans[i] - matrix[i][j] * ans[j];

                }//end if int j
            }//end for int j


            ans[i] = ans[i] / matrix[i][i];

            if (abs(ans[i] - previous) <= Err) {

                ready++;
            }//end if abs '=
            printf("x%d = %lf ", i, ans[i]);
        }//end for int i
        count ++;
    }//end while ready
    printf("\n");

}//end void gaussSeidel



void changeErrandEOI () {

    char choice[1000];

    printf("Do you want to change the error limit or iteration limit\n\
        Change error limit - err\n\
        Change iteration limit - itr\n\
        Both - both\n\
        None - anything else\n>> ");
    scanf("%s", choice);

    if (strcmp(choice, "err") == 0) {

        printf("What is the new error: ");
        int check = scanf("%lf", &Err);

        if (check != 1 || (double)Err != Err) {

            printf("Not a valid input");
            Err = -1;
            return;
        }//end if check
    }//end if strcmp


    else if (strcmp(choice, "itr") == 0) {

        printf("What is the new iteration limit: ");
        int check = scanf("%d", &EOI);

        if (check != 1 || (double)EOI != EOI) {

            printf("Not a valid input");
            Err = -1;
            return;
        }//end if check
    }//end else if itr


    else if (strcmp(choice, "both") == 0) {

        printf("What is the new error:");

        int check = scanf("%lf", &Err);

        if (check != 1 || (double)Err != Err) {

            printf("Not a valid input");
            Err = -1;
            return;
        }//end if check

        printf("What is the new iteration limit:");

        check = scanf("%d", &EOI);

        if (check != 1 || (int)EOI != EOI) {

            printf("Not a valid input");
            Err = -1;
            return;
        }//end if check

    }//end else if both 

    else {

        return;
    }//end else 

}//end void











// geeks 4 geeks generic gauss seidel 
/*
int main()
{
    int count, t, limit;
    float temp, error, a, sum = 0;
    float matrix[10][10], y[10], allowed_error;
     
    printf("\nEnter the Total Number of Equations:\t");
    scanf("%d", & limit);
    // maximum error limit till which errors are considered,
    // or desired accuracy is obtained)
     
    printf("Enter Allowed Error:\t");
    scanf("%f", & allowed_error);
    printf("\nEnter the Co-Efficients\n");
     
    for(count = 1; count <= limit; count++)
    {
        for(t = 1; t <= limit + 1; t++)
        {
            printf(" Matrix[%d][%d] = " , count, t);
            scanf(" %f" , & matrix[count][t]);
        }
    }
     
    for(count = 1; count <= limit; count++)
    {
        y[count] = 0;
    }
    do
    {
        a = 0;
        for(count = 1; count <= limit; count++)
        {
            sum = 0;
            for(t = 1; t < a)
            {
                a = error;
            }
            y[count] = temp;
            printf("\nY[%d]=\t%f", count, y[count]);
        }
        printf("\n");
    }
    while(a >= allowed_error);
     
    printf("\n\nSolution\n\n");
     
    for(count = 1; count <= limit; count++)
    {
        printf(" \nY[%d]:\t%f" , count, y[count]);
    }
    return 0;
}


*/






