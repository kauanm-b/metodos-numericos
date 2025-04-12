#include<iostream>
#include<math.h>
#define PI acos(-1.0)

double f(double x) {  // Esta � a fun��o f
	return(pow(x,3)-9*x+3);
}

int main()
{
    double Limite_Inferior=-20,Limite_Superior=20,passo=1,x;

    for(x=Limite_Inferior;x<=Limite_Superior;x=x+passo) {
    	
    	if(f(x)*f(x+1)<0) printf("Possibilidade de raiz no intervalo [%lf; %lf]\n",x,x+1);

    }

    system("PAUSE");   
    return 0;
}