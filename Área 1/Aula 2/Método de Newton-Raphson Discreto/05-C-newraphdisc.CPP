#include<iostream>
#include<math.h>

double f(double x) { // Esta � a fun��o f
    return(pow(x,3)-9*x+3);}

double fld(double x) { // Esta � a derivada de f
    double h=1e-5;
    return((f(x-2*h)-8*f(x-h)+8*f(x+h)-f(x+2*h))/(12*h));}

int main()
{
    double x0=0.5,eps1=1e-5,eps2=1e-5,x1;
    int k;

    for(k=1;k<=100;k++) {
        x1=x0-f(x0)/fld(x0);

        if( fabs(x1-x0)<eps1 || fabs(f(x1))<eps2 ) break;

        printf("Passo k = %2d, raiz x = %14.10lf\n",k,x1);

        x0=x1;
    }

    printf("A raiz vale %14.10lf com %d passos.\n\n",x1,k);

    system("PAUSE");
    return 0;
}
