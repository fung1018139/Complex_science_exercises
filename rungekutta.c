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

double x_hist[Max_t];
double y_hist[Max_t];
double z_hist[Max_t];

//各初期値の代入
double x=1;
double y=2;
double z=1;

int t=0;
while (t<Max_t){
double k1=dxdt(x,y,z,t);
double m1=dydt(x,y,z,t);
double l1=dzdt(x,y,z,t);

double k2=dxdt(x+k1/2,y+m1/2,z+l1/2,t+DELTA_T/2);
double m2=dydt(x+k1/2,y+m1/2,z+l1/2,t+DELTA_T/2);
double l2=dzdt(x+k1/2,y+m1/2,z+l1/2,t+DELTA_T/2);

double k3=dxdt(x+k2/2,y+m2/2,z+l2/2,t+DELTA_T/2);
double m3=dydt(x+k2/2,y+m2/2,z+l2/2,t+DELTA_T/2);
double l3=dzdt(x+k2/2,y+m2/2,z+l2/2,t+DELTA_T/2);

double k4=dxdt(x+k3,y+m3,z+l3,t+DELTA_T);
double m4=dydt(x+k3,y+m3,z+l3,t+DELTA_T);
double l4=dzdt(x+k3,y+m3,z+l3,t+DELTA_T);

double K=DELTA_T*(k1+2*k2+2*k3+k4)/6;
double M=DELTA_T*(m1+2*m2+2*m3+m4)/6;
double L=DELTA_T*(l1+2*l2+2*l3+l4)/6;

t+=DELTA_T;

x_hist[t]=K;
y_hist[t]=M;
z_hist[t]=L;

x+=K;
y+=M;
z+=L;

}

for (int i=0;i<Max_t;i+=1){
    printf("\n");
    printf("%f  %f  %f",x_hist[i],y_hist[i],z_hist[i]);
}

return 0;
}