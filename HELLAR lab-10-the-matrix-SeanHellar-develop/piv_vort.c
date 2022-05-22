#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


int main() {

  int size = 22361;
  double *xpos, *ypos, *xvel, *yvel;

  xpos = malloc(sizeof(double) * size);
  ypos = malloc(sizeof(double) * size);
  xvel = malloc(sizeof(double) * size);
  yvel = malloc(sizeof(double) * size);

  FILE *pFile;
  pFile = fopen("PIV.dat", "rows"); 

  char line[256];
  
  fgets(line, sizeof(line), pFile);

  int i, j;
  for (i = 0; i < size; i++) {
    
    fgets(line, sizeof(line), pFile);
    
    sscanf(line, "%lf %lf %lf %lf [^/n]", &xpos[i], &ypos[i], &xvel[i], &yvel[i]);
    
    xpos[i] /= 1000;
    ypos[i] /= 1000;
  
  }//end for i 

  double xposmax = xpos[0], xposmin = xpos[0], yposmax = ypos[0], yposmin = ypos[0];

  //there must be better way
  for (i = 0; i < size; i++) {
    
    if (xpos[i] > xposmax) {
      
      xposmax = xpos[i]; 
    }//end if > xposmax
    
    if (xpos[i] < xposmin) {
      
      xposmin = xpos[i]; 
    }//end if < xposmin
    
    if (ypos[i] > yposmax) {
      
      yposmax = ypos[i]; 
    }//end if >yposmax
    
    if (ypos[i] < yposmin) {
      yposmin = ypos[i]; 
    }//end < yposmin

  }//end for i size

  fclose(pFile); 

  
  int rows = 130;
  int cols = 172;
  int k = 0;

  double Uvel[rows][cols], Vvel[rows][cols];

  for (i = 0; i < rows; i++) {
    
    for (j = 0; j < cols; j++) {
      
      Uvel[i][j] = xvel[k]; 
      
      Vvel[i][j] = yvel[k]; 

      k++;
    }//end for j < cols
  
  }//end for i < rows

  
  FILE *Xvel;
  
  Xvel = fopen("Xvel.txt", "w"); 
  
  for (i = 0; i < rows; i++) {
    
    for (j = 0; j < cols; j++) {
    
      fprintf(Xvel, "%*lf ", 10, Uvel[i][j]); 
    
    }//end for j<cols
    
    fprintf(Xvel, "\n");
  
  }//end for i<rows
  
  fclose(Xvel); 


  //literally the same thing but y

  FILE *Yvel;

  Yvel = fopen("Yvel.txt", "w"); 
  
  for (i = 0; i < rows; i++) {
  
    for (j = 0; j < cols; j++) {
  
      fprintf(Yvel, "%*lf ", 9, Vvel[i][j]); 
  
    }//end for i<rows
  
    fprintf(Yvel, "\n"); 
  
  }//end for j<cols
  
  fclose(Yvel);

  

  double xspace, yspace;

  xspace = (xposmax - xposmin) / (cols - 1); 

  yspace = (yposmax - yposmin) / (rows - 1); 


  double w[126][168];
  double wx, wy;

  //i swear math better work
  //report math no work
  //thank you symbolab 

  for (i = 2; i < rows - 2; i++) { 
  
    for (j = 2; j < cols - 2; j++) { 
  
      wx = (-Vvel[i][j + 2] + 8.0 * Vvel[i][j + 1] - 8.0 * Vvel[i][j - 1] + Vvel[i][j - 2]) / (12.0 * xspace); 
  
      wy = (-Uvel[i + 2][j] + 8.0 * Uvel[i + 1][j] - 8.0 * Uvel[i - 1][j] + Uvel[i - 2][j]) / (12.0 * yspace); 
  
      w[i - 2][j - 2] = (wx - wy);
   
    }//end for j<cols
  
  }//end for i<rows


  FILE *Vort;

  Vort = fopen("Vort.txt", "w"); 
  
  for (i = 0; i < rows - 4; i++) {
  
    for (j = 0; j < cols - 4; j++) {
  
      fprintf(Vort, "%*lf ", 12, w[i][j]); 
  
    }//end for i<rows
  
    fprintf(Vort, "\n"); 
  
  }//end for j<cols
  
  fclose(Vort); 


}//end main