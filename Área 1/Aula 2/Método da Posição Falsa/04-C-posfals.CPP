#include <iostream>
#include <math.h>
#define PI acos(-1.0)

double f(double x) { // Esta é a função f
	return(pow(x,3)-9*x+3); //Exemplo com a=0,b=1,eps1=1e-5,eps2=1e-5
//	return(sin(0.11*x-PI/7)/4); //Exercício 1 com a=-25,b=-24,eps1=1e-4,eps2=1e-4
//	return(x-cos(x)); //Exercício 2 com a=0,b=1,eps1=1e-6,eps2=1e-6
}

int main()
{
    double a=0,b=1,eps1=1e-5,eps2=1e-5,x;
    int k;
    
    for(k=1;k<=100;k++) {
    	x=(a*f(b)-b*f(a))/(f(b)-f(a));
    	
    	if(f(a)*f(x)>0) a=x;
    	else b=x;
    	
    	if( (b-a)<eps1 || fabs(f(x))<eps2 ) break;
    	
    	printf("Passo k = %2d, raiz x = %14.10lf\n",k,x);
    }

    printf("A raiz vale %14.10lf com %d passos.\n\n",x,k);

    system("PAUSE");   
    return 0;
}
