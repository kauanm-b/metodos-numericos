#include<iostream>

int main()
{
	float A=1,S=2; //tentar double
	
	while(S>1) {
		A=A/10;
		S=1+A;
	}
	
	printf("A precisao vale %e\n\n",10*A);
	
	system("PAUSE");
	return 0;
}

