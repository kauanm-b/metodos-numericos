/**
 * Método da Posição Falsa para Encontrar Raízes
 * 
 * Este programa implementa o método da Posição Falsa (Regula Falsi) para encontrar raízes
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
    return pow(x, 3) - 9 * x + 3;
    // return sin(0.11 * x - PI / 7) / 4; // Exercício 1
    // return x - cos(x); // Exercício 2
}

/**
 * Método da Posição Falsa para encontrar raízes
 * @param a Limite inferior do intervalo
 * @param b Limite superior do intervalo
 * @param eps1 Tolerância para a diferença entre limites
 * @param eps2 Tolerância para o valor da função
 * @param max_iter Número máximo de iterações
 * @return Raiz encontrada
 */
double metodo_posicao_falsa(double a, double b, double eps1, double eps2, int max_iter) {
    double x;
    int iteracao;
    
    // Verificando se o intervalo é válido (f(a) e f(b) devem ter sinais opostos)
    if (f(a) * f(b) >= 0) {
        std::cout << "ERRO: O intervalo [" << a << ", " << b << "] não contém uma raiz." << std::endl;
        std::cout << "f(" << a << ") = " << f(a) << " e f(" << b << ") = " << f(b) << " têm o mesmo sinal." << std::endl;
        return 0.0;
    }
    
    std::cout << "Iteração |    x    |    f(x)    |    a    |    b    " << std::endl;
    std::cout << "---------|---------|------------|---------|---------" << std::endl;
    
    for (iteracao = 1; iteracao <= max_iter; iteracao++) {
        // Calculando a próxima aproximação usando o método da Posição Falsa
        x = (a * f(b) - b * f(a)) / (f(b) - f(a));
        
        // Exibindo informações da iteração atual
        std::cout << std::setw(9) << iteracao << " | " 
                  << std::fixed << std::setprecision(6) << std::setw(9) << x << " | " 
                  << std::setw(10) << f(x) << " | " 
                  << std::setw(9) << a << " | " 
                  << std::setw(9) << b << std::endl;
        
        // Atualizando os limites com base no sinal da função
        if (f(a) * f(x) > 0) {
            a = x;
        } else {
            b = x;
        }
        
        // Verificando critérios de convergência
        if ((b - a) < eps1 || fabs(f(x)) < eps2) {
            break;
        }
    }
    
    return x;
}

int main() {
    // Parâmetros do método
    double a = 0.0;       // Limite inferior do intervalo
    double b = 1.0;       // Limite superior do intervalo
    double eps1 = 1e-5;   // Tolerância para a diferença entre limites
    double eps2 = 1e-5;   // Tolerância para o valor da função
    int max_iter = 100;   // Número máximo de iterações
    
    std::cout << "MÉTODO DA POSIÇÃO FALSA PARA ENCONTRAR RAÍZES" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "Intervalo: [" << a << ", " << b << "]" << std::endl;
    std::cout << "Tolerâncias: eps1 = " << eps1 << ", eps2 = " << eps2 << std::endl << std::endl;
    
    // Aplicando o método da Posição Falsa
    double raiz = metodo_posicao_falsa(a, b, eps1, eps2, max_iter);
    
    // Exibindo o resultado
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