#include<iostream>

int main()
{
	float parcela=0.2,soma=0; //tentar double
	int i;
	
	for(i=1;i<=30000;i=i+1) soma=soma+parcela;
	
	printf("A soma vale %f\n\n",soma); //tentar double lf
	
	system("PAUSE");
	return 0;
}
