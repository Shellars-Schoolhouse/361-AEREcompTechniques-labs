#include<stdio.h>
#include<math.h>

//stuff
//all four of integration files go here
//name exactly as named in template/main.c

//main.c from template
//name all integration functions as this
/* 1111111111111111111

double integrand(double x){
    // Your test fucntion goes here
    return x*x;
}

// Forword declaration of function prototypes here

int main(void) {
    double ans;

    ans = midpoint(integrand, 0, 2);
    printf("Midpoint integration: %g\n", ans);

    ans = simpson_13(integrand, 0, 2);
    printf("Simpson's 1/3 Rule: %g\n", ans);

    ans = simpson_38(integrand, 0, 2);
    printf("Simpson's 3/8 Rule: %g\n", ans);

    ans = gauss_quad(integrand, 0, 2, 3);
    printf("Gauss Quad: %g\n", 0, 2);

    return 0;
}
11111111111111111111*/

// Declare your functions here

// Use the names exactly as spelled in the sample main.c file
// Error to do so means your program won't get called

// Argument order is:
//      Integrand Function
//      Lower Bound
//      Upper Bound
//      Order (Gauss only - Integer)

/*222222222222*/
//starting here

//first declare my functions

double midpoint(double (*integrand)(double), double a, double b);
double simpson_13(double (*integrand)(double), double a, double b);
double simpson_38(double (*integrand)(double), double a, double b);
double gauss_quad(double (*integrand)(double), double a, double b, int n);

/*
double midpoint (double (double) , double , double);
double simpson_13 (double (double) , double , double);
double simpson_38 (double (double) , double , double);
double gauss_quad (double (double) , double , double, int n);
*/

//math of functions

double midpoint(double (*integrand)(double), double a, double b) {
  
    return (b-a) * integrand((a+b)/2);
}//end double midpoint

double simpson_13(double (*integrand)(double), double a, double b) {

  return ((b-a)/6) * (integrand(a) + ( 4 * integrand((a+b)/2)) + integrand(b))  ;
}//end double simpson 13

double simpson_38(double (*integrand)(double), double a, double b) {

  return ((b-a)/8) * (integrand(a) + ( 3 * integrand(((2*a) + b) / 3)) + ( 3 * integrand((a + (2 * b)) / 3)) + integrand(b));
}//end double simpson 38


double gauss_quad(double (*integrand)(double), double a, double b, int n) {

  double c = .5 * (b+a);
  double m = .5 * (b-a);
  double tot = 0;

  double t[11][11];
  double w[11][11];

  t[2][1]=0.57735027;
  t[2][2]=-0.57735027;
  t[3][2]=0.77459667;
  t[3][3]=-0.77459667;
  t[4][1]=0.33998104;
  t[4][2]=-0.33998104;
  t[4][3]=0.86113631;
  t[4][4]=-0.86113631;
  t[5][2]=0.53846931;
  t[5][3]=-0.53846931;
  t[5][4]=0.90617985;
  t[5][5]=-0.90617985;
  t[6][1]=0.23861918;
  t[6][2]=-0.23861918;
  t[6][3]=0.66120939;
  t[6][4]=-0.66120939;
  t[6][5]=0.93246951;
  t[6][6]=-0.93246951;
  t[7][2]=0.40584515;
  t[7][3]=-0.40584515;
  t[7][4]=0.74153119;
  t[7][5]=-0.74153119;
  t[7][6]=0.94910791;
  t[7][7]=-0.94910791;
  t[8][1]=0.18343464;
  t[8][2]=-0.18343464;
  t[8][3]=0.52553241;
  t[8][4]=-0.52553241;
  t[8][5]=0.79666648;
  t[8][6]=-0.79666648;
  t[8][7]=0.96028986;
  t[8][8]=-0.96028986;
  t[9][2]=0.32425342;
  t[9][3]=-0.32425342;
  t[9][4]=0.61337143;
  t[9][5]=-0.61337143;
  t[9][6]=0.83603111;
  t[9][7]=-0.83603111;
  t[9][8]=0.96816024;
  t[9][9]=-0.96816024;
  t[10][1]=0.14887434;
  t[10][2]=-0.14887434;
  t[10][3]=0.43339539;
  t[10][4]=-0.43339539;
  t[10][5]=0.67940957;
  t[10][6]=-0.67940957;
  t[10][7]=0.86506337;
  t[10][8]=-0.86506337;
  t[10][9]=0.97390653;
  t[10][10]=-0.97390653;

  w[2][1]=1;
  w[2][2]=1;
  w[3][1]=0.88888889;
  w[3][2]=0.55555555;
  w[3][3]=0.55555555;
  w[4][1]=0.65214515;
  w[4][2]=0.65214515;
  w[4][3]=0.34785485;
  w[4][4]=0.34785485;
  w[5][1]=0.56888889;
  w[5][2]=0.47862867;
  w[5][3]=0.47862867;
  w[5][4]=0.23692689;
  w[5][5]=0.23692689;
  w[6][1]=0.46791393;
  w[6][2]=0.46791393;
  w[6][3]=0.36076157;
  w[6][4]=0.36076157;
  w[6][5]=0.17132449;
  w[6][6]=0.17132449;
  w[7][1]=0.41795918;
  w[7][2]=0.38183005;
  w[7][3]=0.38183005;
  w[7][4]=0.27970539;
  w[7][5]=0.27970539;
  w[7][6]=0.12948497;
  w[7][7]=0.12948497;
  w[8][1]=0.36268378;
  w[8][2]=0.36268378;
  w[8][3]=0.31370665;
  w[8][4]=0.31370665;
  w[8][5]=0.22238103;
  w[8][6]=0.22238103;
  w[8][7]=0.10122854;
  w[8][8]=0.10122854;
  w[9][1]=0.33023936;
  w[9][2]=0.31234708;
  w[9][3]=0.31234708;
  w[9][4]=0.26061070;
  w[9][5]=0.26061070;
  w[9][6]=0.18064816;
  w[9][7]=0.18064816;
  w[9][8]=0.08127439;
  w[9][9]=0.08127439;
  w[10][1]=0.29552422;
  w[10][2]=0.29552422;
  w[10][3]=0.26926672;
  w[10][4]=0.26926672;
  w[10][5]=0.21908636;
  w[10][6]=0.21908636;
  w[10][7]=0.14945135;
  w[10][8]=0.14945135;
  w[10][9]=0.06667134;
  w[10][10]=0.06667134;


  for (int i = 0; i <= n; i++) {

    tot = tot + (w[n][i] * integrand((c) + ((m) * t[n][i])));
  }//end for

  return tot;

}//end double gauss


