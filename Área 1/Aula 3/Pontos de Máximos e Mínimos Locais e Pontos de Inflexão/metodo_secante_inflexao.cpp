/**
 * Método da Secante para Encontrar Pontos de Inflexão
 * 
 * Este programa implementa o método da secante para encontrar pontos de inflexão
 * de uma função f(x). Um ponto de inflexão é um ponto onde a concavidade da curva
 * muda, ou seja, onde a segunda derivada f''(x) é igual a zero.
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
    return pow(x, 3) - 8 * pow(x, 2) - 54 * x + 95;
}

/**
 * Primeira derivada da função f(x) calculada numericamente
 * @param x Valor de entrada
 * @return Valor da primeira derivada f'(x)
 */
double primeira_derivada(double x) {
    double h = 1e-3;
    return (f(x-2*h) - 8*f(x-h) + 8*f(x+h) - f(x+2*h)) / (12*h);
}

/**
 * Segunda derivada da função f(x) calculada numericamente
 * @param x Valor de entrada
 * @return Valor da segunda derivada f''(x)
 */
double segunda_derivada(double x) {
    double h = 1e-3;
    return (-f(x-2*h) + 16*f(x-h) - 30*f(x) + 16*f(x+h) - f(x+2*h)) / (12*pow(h, 2));
}

/**
 * Método da secante para encontrar pontos de inflexão
 * @param x0 Primeiro ponto inicial
 * @param x1 Segundo ponto inicial
 * @param eps1 Tolerância para a diferença entre iterações consecutivas
 * @param eps2 Tolerância para o valor da segunda derivada
 * @param max_iter Número máximo de iterações
 * @return Ponto de inflexão encontrado
 */
double metodo_secante_inflexao(double x0, double x1, double eps1, double eps2, int max_iter) {
    double x2;
    int iteracao;
    
    std::cout << "Iteração |    x    |    f(x)    |    f''(x)    " << std::endl;
    std::cout << "---------|---------|------------|--------------" << std::endl;
    
    for (iteracao = 1; iteracao <= max_iter; iteracao++) {
        // Aplicando o método da secante para encontrar onde f''(x) = 0
        x2 = x1 - segunda_derivada(x1) * (x1 - x0) / (segunda_derivada(x1) - segunda_derivada(x0));
        
        // Exibindo informações da iteração atual
        std::cout << std::setw(9) << iteracao << " | " 
                  << std::fixed << std::setprecision(6) << std::setw(9) << x1 << " | " 
                  << std::setw(10) << f(x1) << " | " 
                  << std::setw(12) << segunda_derivada(x1) << std::endl;
        
        // Verificando critérios de convergência
        if (fabs(x2 - x1) < eps1 || fabs(segunda_derivada(x2)) < eps2) {
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
    double x0 = 2.0;      // Primeiro ponto inicial
    double x1 = 3.0;      // Segundo ponto inicial
    double eps1 = 1e-6;   // Tolerância para a diferença entre iterações
    double eps2 = 1e-6;   // Tolerância para o valor da segunda derivada
    int max_iter = 100;   // Número máximo de iterações
    
    std::cout << "MÉTODO DA SECANTE PARA ENCONTRAR PONTOS DE INFLEXÃO" << std::endl;
    std::cout << "=================================================" << std::endl;
    std::cout << "Função: f(x) = x³ - 8x² - 54x + 95" << std::endl;
    std::cout << "Procurando ponto de inflexão entre x = " << x0 << " e x = " << x1 << std::endl;
    std::cout << "Tolerâncias: eps1 = " << eps1 << ", eps2 = " << eps2 << std::endl << std::endl;
    
    // Aplicando o método da secante
    double ponto_inflexao = metodo_secante_inflexao(x0, x1, eps1, eps2, max_iter);
    
    // Exibindo o resultado
    std::cout << std::endl;
    std::cout << "RESULTADO:" << std::endl;
    std::cout << "Ponto de inflexão: x = " << std::fixed << std::setprecision(10) << ponto_inflexao << std::endl;
    std::cout << "Valor da função: f(x) = " << f(ponto_inflexao) << std::endl;
    std::cout << "Valor da segunda derivada: f''(x) = " << segunda_derivada(ponto_inflexao) << std::endl;
    
    // Verificando se é um ponto de inflexão
    if (fabs(segunda_derivada(ponto_inflexao)) < eps2) {
        std::cout << "Confirmação: Este é um ponto de inflexão (f''(x) ≈ 0)" << std::endl;
    } else {
        std::cout << "Atenção: O valor de f''(x) não é próximo de zero. Pode não ser um ponto de inflexão." << std::endl;
    }
    
    return 0;
} 