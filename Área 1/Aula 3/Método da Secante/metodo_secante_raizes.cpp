/**
 * Método da Secante para Encontrar Raízes
 * 
 * Este programa implementa o método da secante para encontrar raízes
 * de uma função f(x). Uma raiz é um valor de x onde f(x) = 0.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

/**
 * Função f(x) que será analisada
 * @param x Valor de entrada
 * @return Valor da função f(x)
 */
double f(double x) {
    return pow(x, 3) - 9 * x + 3;
    // return 3.453 * pow(x, 7) - 2.0975 * pow(x, 6) - 120.5323 * pow(x, 5) - 1989.34 * pow(x, 3) + 12003; // Exercício 1
    // return 3.453 * pow(x, 7) - 2.0975 * pow(x, 6) - 120.5323 * pow(x, 5) - 1989.34 * pow(x, 3) + 12003; // Exercício 2
    // return 3.453 * pow(x, 7) - 2.0975 * pow(x, 6) - 120.5323 * pow(x, 5) - 1989.34 * pow(x, 3) + 12003; // Exercício 3
}

/**
 * Método da secante para encontrar raízes
 * @param x0 Primeiro ponto inicial
 * @param x1 Segundo ponto inicial
 * @param eps1 Tolerância para a diferença entre iterações consecutivas
 * @param eps2 Tolerância para o valor da função
 * @param max_iter Número máximo de iterações
 * @return Raiz encontrada
 */
double metodo_secante_raizes(double x0, double x1, double eps1, double eps2, int max_iter) {
    double x2;
    int iteracao;
    
    std::cout << "Iteração |    x    |    f(x)    " << std::endl;
    std::cout << "---------|---------|------------" << std::endl;
    
    for (iteracao = 1; iteracao <= max_iter; iteracao++) {
        // Aplicando o método da secante para encontrar onde f(x) = 0
        // Usando divisão com ponto flutuante para maior precisão
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        
        // Exibindo informações da iteração atual com alta precisão
        std::cout << std::setw(9) << iteracao << " | " 
                  << std::fixed << std::setprecision(15) << std::setw(17) << x1 << " | " 
                  << std::setw(17) << f(x1) << std::endl;
        
        // Verificando critérios de convergência
        if (fabs(x2 - x1) < eps1 || fabs(f(x2)) < eps2) {
            break;
        }
        
        // Atualizando pontos para a próxima iteração
        x0 = x1;
        x1 = x2;
    }
    
    return x2;
}

int main() {
    // Parâmetros do método
    double x0 = 0.0;      // Primeiro ponto inicial
    double x1 = 2.0;      // Segundo ponto inicial
    double eps1 = 1e-5;  // Tolerância para a diferença entre iterações (máxima precisão)
    double eps2 = 1e-5;  // Tolerância para o valor da função (máxima precisão)
    int max_iter = 100;   // Número máximo de iterações
    
    std::cout << "MÉTODO DA SECANTE PARA ENCONTRAR RAÍZES" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Procurando raiz entre x = " << x0 << " e x = " << x1 << std::endl;
    std::cout << "Tolerâncias: eps1 = " << eps1 << ", eps2 = " << eps2 << std::endl << std::endl;
    
    // Aplicando o método da secante
    double raiz = metodo_secante_raizes(x0, x1, eps1, eps2, max_iter);
    
    // Exibindo o resultado com máxima precisão
    std::cout << std::endl;
    std::cout << "RESULTADO:" << std::endl;
    std::cout << "Raiz: x = " << std::fixed << std::setprecision(10) << raiz << std::endl;
    std::cout << "Valor da função: f(x) = " << f(raiz) << std::endl;
    
    // Verificando se é uma raiz
    if (fabs(f(raiz)) < eps2) {
        std::cout << "Confirmação: Este é uma raiz (f(x) ≈ 0)" << std::endl;
    } else {
        std::cout << "Atenção: O valor de f(x) não é próximo de zero. Pode não ser uma raiz." << std::endl;
    }
    
    return 0;
} 
