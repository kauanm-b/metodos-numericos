#include <iostream>
#include <math.h>

int main()
{
    int ne=3; //número de equações e variáveis
	//Matriz dos coeficientes
	double A[20][20]=  {{10,2,1},
						{1,5,1},
						{2,3,10}};
	//Termos independentes
	double b[20]={7,-8,6};
	//Valor do Critério de Parada
	double eps3=5E-2;

	double xk1[20],xk[20],d[20],dmax;
    int i,j,k;

	printf("\nValores iniciais:\n");
	for(i=0;i<=ne-1;i++){
		xk[i]=b[i]/A[i][i];
		printf("x%d^(0) = %16.12lf\n",i,xk[i]);}

    for(k=0;k<=100;k++){
    	printf("\n-------------- Passo %2d --------------\n",k+1);
		for(i=0;i<=ne-1;i++){
            xk1[i]=b[i];
            for(j=0;j<=ne-1;j++){
            	if(i==j) continue;
                xk1[i]=xk1[i]-A[i][j]*xk[j];
				}
            xk1[i]=xk1[i]/A[i][i];
            printf("x%d^(%d) = %16.12lf\n",i,k+1,xk1[i]);
        	}
       dmax=0;
       printf("\n");
       for(i=0;i<=ne-1;i++){
			d[i]=fabs(xk1[i]-xk[i]);
			printf("d[%d] = %16.12lf\n",i,d[i]);
			if(d[i]>dmax) dmax=d[i];
        }
    	if(dmax<eps3) break;
		printf("\n          d[max] > eps3\n%16.12lf > %16.12lf --->>> continuar\n\
--------------------------------------\n\n",dmax,eps3);
    	for(i=0;i<=ne-1;i++){
			xk[i]=xk1[i];
        }
    }

    printf("\n          d[max] < eps3\n%16.12lf < %16.12lf --->>> convergencia alcancada.\n\
--------------------------------------\n\n",dmax,eps3);
    
	printf("\nVetor final calculado no passo %d:\n",k+1);
    for(i=0;i<=ne-1;i++) printf("x%d = %16.12lf\n",i,xk1[i]);
    
    system("PAUSE");
    return 0;
}
