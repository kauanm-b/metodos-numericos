#include <iostream>
#include <math.h>

int main(){
    int ne=3; //número de equações e variáveis
	//Matriz dos coeficientes
	double A[20][20]=  {{2,4,2},
						{3,5,2},
						{4,0,5}};
	//Termos independentes
	double b[20]={-8,-9,-1};
	
	double x[20],m,s;
	int i,j,k;
    
    for(k=0;k<=ne-2;k++){
		for(i=k+1;i<=ne-1;i++){
			m=A[i][k]/A[k][k];
			A[i][k]=0;
			for(j=k;j<=ne-1;j++) A[i][j]-=m*A[k][j]; //A[i][j]=A[i][j]-m*A[k][j];
			b[i]-=m*b[k];}} //b[i]=b[i]-m*b[k]
    
    x[ne]=b[ne]/A[ne][ne];
    for(k=ne-1;k>=0;k--){
    	s=0;
		for(j=k;j<=ne-1;j++) s+=A[k][j]*x[j];
		x[k]=(b[k]-s)/A[k][k];}

    for(i=0;i<=ne-1;i++) printf("x%d = %16.12lf\n",i+1,x[i]);
    system("PAUSE");
    return 0;}
