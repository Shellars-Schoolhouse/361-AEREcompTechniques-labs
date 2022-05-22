/*This is an example template for the Gauss-Jordan exercise. You are not required to use it. 
It simply provides an example structure to get you started.

This code does not compile and run on its own. That task falls to you. In order to get this
program working, you need to add in lines of code where we have placed comments. Keep in mind,
one comment != one line of code. The comment discussing "where the magic happens" will have
several lines in order to perform its function*/

/*The functionality of the program is up to you, and you can use whichever method you're most
comfortable with to write it. You may need more packages, or there may be other various things
you'll need in each of the steps. It depends on how you structure the program.*/

#include <stdio.h>
#include<stdlib.h>


void printmatrix (float ** a, int n) {

    for (int i = 0; i < n; i++) {

        for (int j =0; j <= n; j++) {

            printf("%f", a[i][j]); 
        }//end for int j

        printf("\n");
    }//end for i 
}//end void 



void RREF (float ** a, int n) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (i != j) {

                float factor = a[j][i] / a[i][i];

                for (int k = 0; k <= n; k++) { 

                    a[j][k] = a[j][k] - (a[i][k]) * factor;

                }//end for int k
            }//end if i
        }//end for j
    }//end for i
}//end void


void printanswer (float ** a, int n) {

    printf("\nThe solution is: \n"); 

    for (int i = 0; i < n; i++) {

        printf("\nx%d=%f\n", i, a[i][n] / a[i][i]);
    }//end for int i

    printf("\n");
}//end void




int main() {
    /* Declare Variables */
    int n; 
    /* You'll need a few more variables, including a matrix! */
    
    float **matrix;
    matrix = malloc(sizeof(double *) * n+1);

    /* Request System Order (Number of Equations) */
    printf("\nHow many equations: ");
    scanf("%d", &n);

    for (int a = 0; a < n; a++) {

        matrix[a] = malloc(sizeof(double) * n);
    }//end for int a



    /* Request Augmented Matrix Values. */
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n+1; j++) {
            printf(" A[%d][%d]:", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        } /*end for*/
    } /*end for*/
    
    RREF(matrix, n);
    printanswer(matrix, n);

    
    return 0; /*exit normally*/
} /*end main*/





/*pseudo code that will be the magic

    //Required variables
    //number of equations (n)
    int matrix1; // matrix of coeffcients 
    int matrix2; // matrix of answers
    int x;

    //Forward elimination
    for (k=1; n-1; k++) {
        for(i=k+1; n; i++) {
            normfactor = matrix1(i,k) / matrix1(k,k)
            
            for (j=k+1; n; j++) {
                matrix1(i,j) = matrix1(i,j) - normfactor * matrix1(k,j)
            }//end for j=k+1
            
            matrix2(i) = matrix2(i) - normfactor * matrix2(k)
        }//end for i=k+1
    }//end for k=1
    
    int total = 0; 
    //Backward elimination
    x(n) = matrix2(n) / matrix1(n,n)
    for (i=n-1; -1; i++) 
        for (j=i+1; n; j++) {
            total =  total + matrix1(i,j) * x(j)
        }//end for j+i+1
        x(i) = matrix2(i) - total / matrix2(i,j)
    }//end for i=n-1


    */ 