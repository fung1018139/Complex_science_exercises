#include<stdio.h>

double dxdt(x,y,z,t){
    return -10*x+10*y;
}
double dydt(x,y,z,t){
    return -x*z+28*x-y;
}
double dzdt(x,y,z,t){
    return x*y-(8/3)*z;
}

int main(void){

int Max_t=1000;
double DELTA_T=0.01;

double x[Max_t];
double y[Max_t];
double z[Max_t];

//各初期値の代入
x[0]=1;
y[0]=2;
z[0]=1;

int t=0;
while (t<Max_t){
double k1=dxdt(x[t],y[t],z[t],t);
double m1=dydt(x[t],y[t],z[t],t);
double l1=dzdt(x[t],y[t],z[t],t);

double k2=dxdt(x[t]+k1/2,y[t]+m1/2,z[t]+l1/2,t+DELTA_T/2);
double m2=dydt(x[t]+k1/2,y[t]+m1/2,z[t]+l1/2,t+DELTA_T/2);
double l2=dzdt(x[t]+k1/2,y[t]+m1/2,z[t]+l1/2,t+DELTA_T/2);

double k3=dxdt(x[t]+k1/2,y[t]+m1/2,z[t]+l1/2,t+DELTA_T/2);
double m3=dydt(x[t]+k1/2,y[t]+m1/2,z[t]+l1/2,t+DELTA_T/2);
double l3=dzdt(x[t]+k1/2,y[t]+m1/2,z[t]+l1/2,t+DELTA_T/2);


double k4=dxdt(x[t]+k1,y[t]+m1,z[t]+l1,t+DELTA_T);
double m4=dydt(x[t]+k1,y[t]+m1,z[t]+l1,t+DELTA_T);
double l4=dzdt(x[t]+k1,y[t]+m1,z[t]+l1,t+DELTA_T);

double K=DELTA_T*(k1+2*k2+2*k3+k4)/6;
double M=DELTA_T*(m1+2*m2+2*m3+m4)/6;
double L=DELTA_T*(l1+2*l2+2*l3+l4)/6;

t+=1;
x[t]=K;
y[t]=M;
z[t]=L;

x[t]+=K;
y[t]+=M;
z[t]+=L;

}

for (int i=0;i<Max_t;i+=1){
    printf("\n");
    printf("%f  %f  %f",x[i],y[i],z[i]);
}

return 0;
}