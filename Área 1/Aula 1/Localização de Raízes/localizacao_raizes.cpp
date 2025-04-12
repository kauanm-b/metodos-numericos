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
#include <vector>

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
 * Estrutura para armazenar um intervalo com possível raiz
 */
struct Intervalo {
    double a;
    double b;
    double fa;
    double fb;
};

/**
 * Função para encontrar intervalos com possíveis raízes
 * @param limite_inferior Limite inferior do domínio de busca
 * @param limite_superior Limite superior do domínio de busca
 * @param passo Tamanho do passo para a busca
 * @return Vetor de intervalos encontrados
 */
std::vector<Intervalo> encontrar_raizes(double limite_inferior, double limite_superior, double passo) {
    std::vector<Intervalo> intervalos;
    
    std::cout << "\nIntervalo |    f(a)    |    f(b)    |  |f(b)-f(a)|  " << std::endl;
    std::cout << "---------|------------|------------|---------------" << std::endl;
    
    for (double x = limite_inferior; x <= limite_superior - passo; x += passo) {
        double a = x;
        double b = x + passo;
        double fa = f(a);
        double fb = f(b);
        
        std::cout << "[" << std::fixed << std::setprecision(2) << std::setw(5) << a 
                  << ", " << std::setw(5) << b << "] | " 
                  << std::setw(10) << fa << " | " 
                  << std::setw(10) << fb << " | "
                  << std::setw(13) << fabs(fb-fa) << std::endl;
        
        if (fa * fb < 0) {
            intervalos.push_back({a, b, fa, fb});
            std::cout << ">>> POSSÍVEL RAIZ NO INTERVALO [" << a << ", " << b << "]" << std::endl;
        }
    }
    
    return intervalos;
}

int main() {
    // Configuração da precisão de saída
    std::cout << std::fixed << std::setprecision(6);
    
    // Parâmetros do método
    double limite_inferior = -20.0;   // Limite inferior do domínio de busca
    double limite_superior = 20.0;    // Limite superior do domínio de busca
    double passo = 1.0;              // Tamanho do passo para a busca
    
    std::cout << "LOCALIZAÇÃO DE RAÍZES" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Domínio de busca: [" << limite_inferior << ", " << limite_superior << "]" << std::endl;
    std::cout << "Passo: " << passo << std::endl;
    
    // Aplicando o método de localização de raízes
    auto intervalos = encontrar_raizes(limite_inferior, limite_superior, passo);
    
    // Exibindo o resultado
    std::cout << "\nRESULTADO:" << std::endl;
    std::cout << "Foram encontrados " << intervalos.size() << " intervalos com possíveis raízes." << std::endl;
    
    if (intervalos.empty()) {
        std::cout << "Nenhuma raiz foi encontrada no intervalo especificado." << std::endl;
        std::cout << "Sugestão: Aumente o domínio de busca ou diminua o tamanho do passo." << std::endl;
    } else {
        std::cout << "\nIntervalos encontrados:" << std::endl;
        for (const auto& intervalo : intervalos) {
            std::cout << "[" << intervalo.a << ", " << intervalo.b << "]" << std::endl;
        }
    }
    
    return 0;
} 
