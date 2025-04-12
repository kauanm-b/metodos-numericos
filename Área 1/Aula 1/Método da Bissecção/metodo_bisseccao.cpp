/**
 * Método da Bissecção para Encontrar Raízes
 * 
 * Este programa implementa o método da Bissecção para encontrar raízes
 * de uma função f(x). Uma raiz é um valor de x onde f(x) = 0.
 * O método requer um intervalo [a,b] onde f(a) e f(b) têm sinais opostos.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

#define PI acos(-1.0)

/**
 * Função f(x) que será analisada
 * @param x Valor de entrada
 * @return Valor da função f(x)
 */
double f(double x) {
    // return pow(x, 3) - 9 * x + 3;
    // return exp(2.0 / 5 * x + 3.0 / 2) - 18; // Exercício 1
     return pow(x, 1.0 / 2) - 5 * exp(-x); // Exercício 2
}

/**
 * Método da Bissecção para encontrar raízes
 * @param a Limite inferior do intervalo
 * @param b Limite superior do intervalo
 * @param eps1 Tolerância para a diferença entre limites
 * @param eps2 Tolerância para o valor da função
 * @param max_iter Número máximo de iterações
 * @return Raiz encontrada
 */
double metodo_bisseccao(double a, double b, double eps1, double eps2, int max_iter) {
    double x, fa = f(a), fb = f(b);
    int iteracao;
    
    // Verificando se o intervalo é válido
    if (fa * fb >= 0) {
        std::cout << "ERRO: O intervalo [" << a << ", " << b << "] não contém uma raiz." << std::endl;
        std::cout << "f(" << a << ") = " << fa << " e f(" << b << ") = " << fb << " têm o mesmo sinal." << std::endl;
        return 0.0;
    }
    
    std::cout << "\nIteração |    x    |    f(x)    |    a    |    b    |  |b-a|  " << std::endl;
    std::cout << "---------|---------|------------|---------|---------|---------" << std::endl;
    
    for (iteracao = 1; iteracao <= max_iter; iteracao++) {
        x = (a + b) / 2.0;
        double fx = f(x);
        
        std::cout << std::setw(9) << iteracao << " | " 
                  << std::fixed << std::setprecision(6) << std::setw(9) << x << " | " 
                  << std::setw(10) << fx << " | " 
                  << std::setw(9) << a << " | " 
                  << std::setw(9) << b << " | "
                  << std::setw(9) << fabs(b-a) << std::endl;
        
        if (fa * fx > 0) {
            a = x;
            fa = fx;
        } else {
            b = x;
            fb = fx;
        }
        
        if (fabs(b - a) < eps1 || fabs(fx) < eps2) {
            break;
        }
    }
    
    return x;
}

int main() {
    // Configuração da precisão de saída
    std::cout << std::fixed << std::setprecision(6);
    
    // Parâmetros do método
    double a = 1.0;       // Limite inferior do intervalo
    double b = 2.0;       // Limite superior do intervalo
    double eps1 = 5e-6;   // Tolerância para a diferença entre limites
    double eps2 = 2e-6;   // Tolerância para o valor da função
    int max_iter = 100;   // Número máximo de iterações
    
    std::cout << "MÉTODO DA BISSECÇÃO PARA ENCONTRAR RAÍZES" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "Função: f(x) = x³ - 9x + 3" << std::endl;
    std::cout << "Intervalo: [" << a << ", " << b << "]" << std::endl;
    std::cout << "Tolerâncias: eps1 = " << eps1 << ", eps2 = " << eps2 << std::endl;
    
    // Aplicando o método da Bissecção
    double raiz = metodo_bisseccao(a, b, eps1, eps2, max_iter);
    
    // Exibindo o resultado
    std::cout << "\nRESULTADO:" << std::endl;
    std::cout << "Raiz: x = " << std::fixed << std::setprecision(10) << raiz << std::endl;
    std::cout << "Valor da função: f(x) = " << f(raiz) << std::endl;
    
    if (fabs(f(raiz)) < eps2) {
        std::cout << "Confirmação: Este é uma raiz (f(x) ≈ 0)" << std::endl;
    } else {
        std::cout << "Atenção: O valor de f(x) não é próximo de zero. Pode não ser uma raiz." << std::endl;
    }
    
    return 0;
} 