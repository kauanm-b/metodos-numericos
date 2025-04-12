#include<iostream>
#include<math.h>

double f(double x) { // Esta � a fun��o f
	return(pow(x,3)-9*x+3); // Exemplo com x0=0,x1=1,eps1=1e-5,eps2=1e-5
//	return(3.453*pow(x,7)-2.0975*pow(x,6)-120.5323*pow(x,5)-1989.34*pow(x,3)+12003); // Exerc�cio 1 com x0=-7,x1=-6,eps1=1e-6,eps2=1e-6
//	return(3.453*pow(x,7)-2.0975*pow(x,6)-120.5323*pow(x,5)-1989.34*pow(x,3)+12003); // Exerc�cio 2 com x0=1,x1=2,eps1=1e-6,eps2=1e-6
//	return(3.453*pow(x,7)-2.0975*pow(x,6)-120.5323*pow(x,5)-1989.34*pow(x,3)+12003); // Exerc�cio 3 com x0=7,x1=8,eps1=1e-6,eps2=1e-6
}

int main()
{
    double x0=0,x1=2,eps1=1e-5,eps2=1e-5,x2;
    int k;

    for(k=1;k<=100;k++) {
        x2=x1-f(x1)*(x1-x0)/(f(x1)-f(x0));

        if( fabs(x2-x1)<eps1 || fabs(f(x2))<eps2 ) break;

        printf("Passo k = %2d, raiz x = %14.10f\n",k,x1);

        x0=x1;
        x1=x2;
    }

    printf("A raiz vale %14.10lf com %d passos.\n\n",x2,k);

    system("PAUSE");
    return 0;
}
