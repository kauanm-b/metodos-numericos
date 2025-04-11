/**
 * Localização de Raízes
 * 
 * Este programa implementa um método para localizar intervalos que contêm raízes
 * de uma função f(x). Uma raiz é um valor de x onde f(x) = 0.
 * O método verifica mudanças de sinal da função em intervalos regulares.
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
}

/**
 * Função para encontrar intervalos com possíveis raízes
 * @param limite_inferior Limite inferior do domínio de busca
 * @param limite_superior Limite superior do domínio de busca
 * @param passo Tamanho do passo para a busca
 * @return Número de intervalos encontrados
 */
int encontrar_raizes(double limite_inferior, double limite_superior, double passo) {
    int intervalos_encontrados = 0;
    
    std::cout << "Intervalo |    f(a)    |    f(b)    " << std::endl;
    std::cout << "---------|------------|------------" << std::endl;
    
    for (double x = limite_inferior; x <= limite_superior - passo; x += passo) {
        double a = x;
        double b = x + passo;
        double fa = f(a);
        double fb = f(b);
        
        // Exibindo informações do intervalo atual
        std::cout << "[" << std::fixed << std::setprecision(2) << std::setw(5) << a 
                  << ", " << std::setw(5) << b << "] | " 
                  << std::setw(10) << fa << " | " 
                  << std::setw(10) << fb << std::endl;
        
        // Verificando se há mudança de sinal no intervalo
        if (fa * fb < 0) {
            std::cout << ">>> POSSÍVEL RAIZ NO INTERVALO [" << a << ", " << b << "]" << std::endl;
            intervalos_encontrados++;
        }
    }
    
    return intervalos_encontrados;
}

int main() {
    // Parâmetros do método
    double limite_inferior = -20.0;  // Limite inferior do domínio de busca
    double limite_superior = 20.0;   // Limite superior do domínio de busca
    double passo = 1.0;              // Tamanho do passo para a busca
    
    std::cout << "LOCALIZAÇÃO DE RAÍZES" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Função: f(x) = x³ - 9x + 3" << std::endl;
    std::cout << "Domínio de busca: [" << limite_inferior << ", " << limite_superior << "]" << std::endl;
    std::cout << "Passo: " << passo << std::endl << std::endl;
    
    // Aplicando o método de localização de raízes
    int num_intervalos = encontrar_raizes(limite_inferior, limite_superior, passo);
    
    // Exibindo o resultado
    std::cout << std::endl;
    std::cout << "RESULTADO:" << std::endl;
    std::cout << "Foram encontrados " << num_intervalos << " intervalos com possíveis raízes." << std::endl;
    
    if (num_intervalos == 0) {
        std::cout << "Nenhuma raiz foi encontrada no intervalo especificado." << std::endl;
        std::cout << "Sugestão: Aumente o domínio de busca ou diminua o tamanho do passo." << std::endl;
    } else {
        std::cout << "Use um dos métodos de refinamento (Bissecção, Posição Falsa, Newton-Raphson, Secante) " << std::endl;
        std::cout << "para encontrar a raiz com maior precisão em cada um desses intervalos." << std::endl;
    }
    
    return 0;
} 