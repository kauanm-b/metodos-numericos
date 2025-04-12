/**
 * Teste de Precisão Numérica
 * 
 * Este programa determina a precisão da máquina para números de ponto flutuante
 * usando o método de soma sucessiva.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	// Configuração da precisão de saída
	std::cout << std::scientific << std::setprecision(15);
	
	// Usando double para maior precisão
	double A = 1.0;
	double S = 2.0;
	
	std::cout << "Teste de Precisão Numérica" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << "Valor inicial de A: " << A << std::endl;
	std::cout << "Valor inicial de S: " << S << std::endl << std::endl;
	
	int iteracao = 0;
	while (S > 1.0) {
		A = A / 10.0;
		S = 1.0 + A;
		iteracao++;
		
		std::cout << "Iteração " << iteracao << ":" << std::endl;
		std::cout << "A = " << A << std::endl;
		std::cout << "S = " << S << std::endl;
		std::cout << "|S - 1| = " << std::abs(S - 1.0) << std::endl << std::endl;
	}
	
	std::cout << "RESULTADO:" << std::endl;
	std::cout << "A precisão da máquina é aproximadamente: " << (10.0 * A) << std::endl;
	std::cout << "Número de iterações necessárias: " << iteracao << std::endl;
	
	return 0;
}

