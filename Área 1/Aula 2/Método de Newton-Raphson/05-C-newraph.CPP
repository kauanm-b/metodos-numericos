#include<iostream>
#include<math.h>

double f(double x) { // Esta � a fun��o f
	return(pow(x,3)-9*x+3); //Exemplo com x0=0.5,eps1=1e-5,eps2=1e-5
//	return(exp(-x/7-4)+x/5+exp(x/4-5)); //Exerc�cio 1 com x0=-43.5,eps1=1e-6,eps2=1e-6
//	return(exp(-x/7-4)+x/5+exp(x/4-5)); //Exerc�cio 2 com x0=-0.5,eps1=1e-6,eps2=1e-6
}

double fl(double x) { // Esta � a derivada de f
//	return(3*pow(x,2)-9); //Exemplo com x0=0.5,eps1=1e-5,eps2=1e-5
//	return(-exp(-x/7-4)/7+1./5+exp(x/4-5)/4); //Exerc�cio 1 com x0=-43.5,eps1=1e-6,eps2=1e-6
	return(-exp(-x/7-4)/7+1./5+exp(x/4-5)/4); //Exerc�cio 2 com x0=-0.5,eps1=1e-6,eps2=1e-6
}

int main()
{
    double x0=-0.5,eps1=1e-6,eps2=1e-6,x1;
    int k;

    for(k=1;k<=100;k++) {
        x1=x0-f(x0)/fl(x0);

        if( fabs(x1-x0)<eps1 || fabs(f(x1))<eps2 ) break;

        printf("Passo k = %2d, raiz x = %14.10lf\n",k,x1);
        
        x0=x1;
    }

    printf("A raiz vale %14.10lf com %d passos.\n\n",x1,k);

    system("PAUSE");
    return 0;
}

