#include<stdio.h>
#include<math.h>

double π=M_PI;

double F(double x){
    double xx=pow(x,2);
return x-tan(π/2-0.00000000000001);
}

double f(double x){
double h=0.01;
return (F(x+h)-F(x-h))/(2*h);
}

int main(void){
int l=200000;
double x0[l];
x0[0]=3;

int i=0;
while (i<l) {
    x0[i+1]=x0[i]-F(x0[i])/f(x0[i]);
    i+=1;
}
printf("%f",x0[l-1]);
return 0;
}
//printf("%f",x0[l-1]);
// #include <complex.h>
// int main(void){
// double _Complex z;
// z=cexp(I*π);

// printf("%f",creal(z));
// return 0;
//}  