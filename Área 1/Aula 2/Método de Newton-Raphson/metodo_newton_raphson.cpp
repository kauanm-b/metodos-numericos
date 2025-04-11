/**
 * Método de Newton-Raphson para Encontrar Raízes
 * 
 * Este programa implementa o método de Newton-Raphson para encontrar raízes
 * de uma função f(x). Uma raiz é um valor de x onde f(x) = 0.
 * O método utiliza a derivada da função para convergir mais rapidamente.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * Função f(x) que será analisada
 * @param x Valor de entrada
 * @return Valor da função f(x)
 */
double f(double x) {
    return pow(x, 3) - 9 * x + 3;
    // return exp(-x / 7 - 4) + x / 5 + exp(x / 4 - 5); // Exercício 1
    // return exp(-x / 7 - 4) + x / 5 + exp(x / 4 - 5); // Exercício 2
}

/**
 * Derivada da função f(x)
 * @param x Valor de entrada
 * @return Valor da derivada f'(x)
 */
double derivada(double x) {
    return 3 * pow(x, 2) - 9;
    // return -exp(-x / 7 - 4) / 7 + 1.0 / 5 + exp(x / 4 - 5) / 4; // Exercício 1
    // return -exp(-x / 7 - 4) / 7 + 1.0 / 5 + exp(x / 4 - 5) / 4; // Exercício 2
}

/**
 * Método de Newton-Raphson para encontrar raízes
 * @param x0 Ponto inicial
 * @param eps1 Tolerância para a diferença entre iterações consecutivas
 * @param eps2 Tolerância para o valor da função
 * @param max_iter Número máximo de iterações
 * @return Raiz encontrada
 */
double metodo_newton_raphson(double x0, double eps1, double eps2, int max_iter) {
    double x1;
    int iteracao;
    
    std::cout << "Iteração |    x    |    f(x)    |    f'(x)    " << std::endl;
    std::cout << "---------|---------|------------|--------------" << std::endl;
    
    for (iteracao = 1; iteracao <= max_iter; iteracao++) {
        // Calculando a próxima aproximação usando o método de Newton-Raphson
        x1 = x0 - f(x0) / derivada(x0);
        
        // Exibindo informações da iteração atual
        std::cout << std::setw(9) << iteracao << " | " 
                  << std::fixed << std::setprecision(6) << std::setw(9) << x0 << " | " 
                  << std::setw(10) << f(x0) << " | " 
                  << std::setw(12) << derivada(x0) << std::endl;
        
        // Verificando critérios de convergência
        if (fabs(x1 - x0) < eps1 || fabs(f(x1)) < eps2) {
            break;
        }
        
        // Atualizando ponto para a próxima iteração
        x0 = x1;
    }
    
    return x1;
}

int main() {
    // Parâmetros do método
    double x0 = -0.5;     // Ponto inicial
    double eps1 = 1e-6;   // Tolerância para a diferença entre iterações
    double eps2 = 1e-6;   // Tolerância para o valor da função
    int max_iter = 100;   // Número máximo de iterações
    
    std::cout << "MÉTODO DE NEWTON-RAPHSON PARA ENCONTRAR RAÍZES" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "Função: f(x) = x³ - 9x + 3" << std::endl;
    std::cout << "Derivada: f'(x) = 3x² - 9" << std::endl;
    std::cout << "Ponto inicial: x = " << x0 << std::endl;
    std::cout << "Tolerâncias: eps1 = " << eps1 << ", eps2 = " << eps2 << std::endl << std::endl;
    
    // Aplicando o método de Newton-Raphson
    double raiz = metodo_newton_raphson(x0, eps1, eps2, max_iter);
    
    // Exibindo o resultado
    std::cout << std::endl;
    std::cout << "RESULTADO:" << std::endl;
    std::cout << "Raiz: x = " << std::fixed << std::setprecision(10) << raiz << std::endl;
    std::cout << "Valor da função: f(x) = " << f(raiz) << std::endl;
    std::cout << "Valor da derivada: f'(x) = " << derivada(raiz) << std::endl;
    
    // Verificando se é uma raiz
    if (fabs(f(raiz)) < eps2) {
        std::cout << "Confirmação: Este é uma raiz (f(x) ≈ 0)" << std::endl;
    } else {
        std::cout << "Atenção: O valor de f(x) não é próximo de zero. Pode não ser uma raiz." << std::endl;
    }
    
    return 0;
} 