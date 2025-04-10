#include<iostream>
#include<math.h>

double f(double x) { // Esta é a função f
	return(pow(x,3)-8*pow(x,2)-54*x+95);
	// Exemplo 2 raiz com x0=-6,x1=-5,eps1=1e-6,eps2=1e-6
	// Exemplo 2 raiz com x0=1,x1=2,eps1=1e-6,eps2=1e-6
	// Exemplo 2 raiz com x0=11,x1=12,eps1=1e-6,eps2=1e-6
}

double fl(double x) { // Esta é a primeira derivada de f
    double h=1e-3;
    return((f(x-2*h)-8*f(x-h)+8*f(x+h)-f(x+2*h))/(12*h)); 
	// Exemplo 2 ponto de máx/min local com x0=-3,x1=-2,eps1=1e-6,eps2=1e-6
	// Exemplo 2 ponto de máx/min local com x0=7,x1=8,eps1=1e-6,eps2=1e-6
}
    
double fll(double x) { // Esta é a segunda derivada de f
    double h=1e-3;
    return((-f(x-2*h)+16*f(x-h)-30*f(x)+16*f(x+h)-f(x+2*h))/(12*pow(h,2)));
	// Exemplo 2 ponto de inflexão com x0=2,x1=3,eps1=1e-6,eps2=1e-6
}

int main()
{
    double x0=2,x1=3,eps1=1e-6,eps2=1e-6,x2;
    int k;

    for(k=1;k<=100;k++) {
//		x2=x1-f(x1)*(x1-x0)/(f(x1)-f(x0)); // Para estimar raízes
//		x2=x1-fl(x1)*(x1-x0)/(fl(x1)-fl(x0)); // Para estimar pontos de máximo e mínimos locais
		x2=x1-fll(x1)*(x1-x0)/(fll(x1)-fll(x0)); // Para estimar pontos de inflexão

//		if( fabs(x2-x1)<eps1 || fabs(f(x2))<eps2 ) break; // Para estimar raízes
//		if( fabs(x2-x1)<eps1 || fabs(fl(x2))<eps2 ) break; // Para estimar pontos de máximo e mínimos locais
		if( fabs(x2-x1)<eps1 || fabs(fll(x2))<eps2 ) break; // Para estimar pontos inflexão

		printf("Passo k = %2d, raiz x = %14.10f\n",k,x1);

        x0=x1;
        x1=x2;
    }

//	printf("A raiz vale %14.10lf com %d passos.\n\n",x2,k); // Para estimar raízes
//	printf("O ponto de %s local vale x = %14.10lf e f(x) = %14.10lf com %d passos.\n\n",fll(x2)<0?"MAX":"MIN",x2,f(x2),k); // Para estimar pontos de máximo e mínimos locais
	printf("O ponto de INFLEX vale x = %14.10lf e f(x) = %14.10lf com %d passos.\n\n",x2,f(x2),k); // Para estimar pontos de inflexão

    system("PAUSE");
    return 0;
}
