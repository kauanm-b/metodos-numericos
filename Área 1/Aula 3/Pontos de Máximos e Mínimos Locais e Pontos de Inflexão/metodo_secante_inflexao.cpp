/**
 * Método da Secante para Diferentes Aplicações
 * 
 * Este programa implementa o método da secante para diferentes aplicações:
 * 1. Encontrar raízes de uma função f(x)
 * 2. Encontrar pontos de máximo e mínimo locais (onde f'(x) = 0)
 * 3. Encontrar pontos de inflexão (onde f''(x) = 0)
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

// Estrutura para armazenar informações sobre uma função
struct Funcao {
    std::string nome;
    std::string expressao;
    double (*funcao)(double);
    std::vector<std::pair<double, double>> exemplos_raiz;
    std::vector<std::pair<double, double>> exemplos_maxmin;
    std::vector<std::pair<double, double>> exemplos_inflexao;
};

// Funções disponíveis para análise
double f1(double x) {
    return pow(x, 3) - 8 * pow(x, 2) - 54 * x + 95;
}

double f2(double x) {
    return sin(x) * exp(-x/10);
}

double f3(double x) {
    return x * x * x - 3 * x * x + 2 * x - 1;
}

// Vetor com as funções disponíveis
std::vector<Funcao> funcoes = {
    {
        "f(x) = x³ - 8x² - 54x + 95",
        "pow(x, 3) - 8 * pow(x, 2) - 54 * x + 95",
        f1,
        {{-6, -5}, {1, 2}, {11, 12}},
        {{-3, -2}, {7, 8}},
        {{2, 3}}
    },
    {
        "f(x) = sin(x) * exp(-x/10)",
        "sin(x) * exp(-x/10)",
        f2,
        {{-5, -4}, {0, 1}, {10, 11}},
        {{-2, -1}, {2, 3}, {8, 9}},
        {{0, 1}, {5, 6}}
    },
    {
        "f(x) = x³ - 3x² + 2x - 1",
        "x * x * x - 3 * x * x + 2 * x - 1",
        f3,
        {{-1, 0}, {0, 1}, {2, 3}},
        {{0, 1}, {2, 3}},
        {{1, 2}}
    }
};

// Função atual selecionada
double (*f)(double) = f1;

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
 * Método da secante para encontrar raízes de uma função
 * @param x0 Primeiro ponto inicial
 * @param x1 Segundo ponto inicial
 * @param eps1 Tolerância para a diferença entre iterações consecutivas
 * @param eps2 Tolerância para o valor da função
 * @param max_iter Número máximo de iterações
 * @return Raiz encontrada
 */
double metodo_secante_raiz(double x0, double x1, double eps1, double eps2, int max_iter) {
    double x2;
    int iteracao;
    
    std::cout << "Iteração |    x    |    f(x)    " << std::endl;
    std::cout << "---------|---------|------------" << std::endl;
    
    for (iteracao = 1; iteracao <= max_iter; iteracao++) {
        // Aplicando o método da secante para encontrar onde f(x) = 0
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        
        // Exibindo informações da iteração atual
        std::cout << std::setw(9) << iteracao << " | " 
                  << std::fixed << std::setprecision(6) << std::setw(9) << x1 << " | " 
                  << std::setw(10) << f(x1) << std::endl;
        
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

/**
 * Método da secante para encontrar pontos de máximo e mínimo locais
 * @param x0 Primeiro ponto inicial
 * @param x1 Segundo ponto inicial
 * @param eps1 Tolerância para a diferença entre iterações consecutivas
 * @param eps2 Tolerância para o valor da primeira derivada
 * @param max_iter Número máximo de iterações
 * @return Ponto de máximo ou mínimo encontrado
 */
double metodo_secante_maxmin(double x0, double x1, double eps1, double eps2, int max_iter) {
    double x2;
    int iteracao;
    
    std::cout << "Iteração |    x    |    f(x)    |    f'(x)    " << std::endl;
    std::cout << "---------|---------|------------|--------------" << std::endl;
    
    for (iteracao = 1; iteracao <= max_iter; iteracao++) {
        // Aplicando o método da secante para encontrar onde f'(x) = 0
        x2 = x1 - primeira_derivada(x1) * (x1 - x0) / (primeira_derivada(x1) - primeira_derivada(x0));
        
        // Exibindo informações da iteração atual
        std::cout << std::setw(9) << iteracao << " | " 
                  << std::fixed << std::setprecision(6) << std::setw(9) << x1 << " | " 
                  << std::setw(10) << f(x1) << " | " 
                  << std::setw(12) << primeira_derivada(x1) << std::endl;
        
        // Verificando critérios de convergência
        if (fabs(x2 - x1) < eps1 || fabs(primeira_derivada(x2)) < eps2) {
            break;
        }
        
        // Atualizando pontos para a próxima iteração
        x0 = x1;
        x1 = x2;
    }
    
    return x2;
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
    // Configurações do método - Defina aqui os parâmetros desejados
    int funcao_escolhida = 1;  // 1: f1, 2: f2, 3: f3
    int aplicacao_escolhida = 1;  // 1: Raízes, 2: Máximos/Mínimos, 3: Pontos de Inflexão
    double x0 = 2.0;  // Valor inicial x0
    double x1 = 3.0;  // Valor inicial x1
    double eps1 = 1e-6;  // Tolerância para a diferença entre iterações
    double eps2 = 1e-6;  // Tolerância para o valor da função/derivada
    int max_iter = 100;  // Número máximo de iterações
    
    // Definindo a função escolhida
    if (funcao_escolhida < 1 || funcao_escolhida > static_cast<int>(funcoes.size())) {
        std::cout << "Função inválida! Usando a função padrão (f1)." << std::endl;
        funcao_escolhida = 1;
    }
    f = funcoes[funcao_escolhida - 1].funcao;
    
    std::cout << "MÉTODO DA SECANTE PARA DIFERENTES APLICAÇÕES" << std::endl;
    std::cout << "===========================================" << std::endl;
    
    // Exibindo os valores iniciais e tolerâncias
    std::cout << "Valores iniciais: x0 = " << x0 << ", x1 = " << x1 << std::endl;
    std::cout << "Tolerâncias: eps1 = " << eps1 << ", eps2 = " << eps2 << std::endl << std::endl;
    
    double resultado;
    
    // Aplicando o método da secante de acordo com a aplicação escolhida
    switch (aplicacao_escolhida) {
        case 1: // Raízes
            std::cout << "MÉTODO DA SECANTE PARA ENCONTRAR RAÍZES" << std::endl;
            std::cout << "=====================================" << std::endl;
            resultado = metodo_secante_raiz(x0, x1, eps1, eps2, max_iter);
            
            // Exibindo o resultado
            std::cout << std::endl;
            std::cout << "RESULTADO:" << std::endl;
            std::cout << "Raiz: x = " << std::fixed << std::setprecision(10) << resultado << std::endl;
            std::cout << "Valor da função: f(x) = " << f(resultado) << std::endl;
            break;
            
        case 2: // Máximos e mínimos
            std::cout << "MÉTODO DA SECANTE PARA ENCONTRAR PONTOS DE MÁXIMO E MÍNIMO" << std::endl;
            std::cout << "=====================================================" << std::endl;
            resultado = metodo_secante_maxmin(x0, x1, eps1, eps2, max_iter);
            
            // Exibindo o resultado
            std::cout << std::endl;
            std::cout << "RESULTADO:" << std::endl;
            std::cout << "Ponto de " << (segunda_derivada(resultado) < 0 ? "MÁXIMO" : "MÍNIMO") 
                      << " local: x = " << std::fixed << std::setprecision(10) << resultado << std::endl;
            std::cout << "Valor da função: f(x) = " << f(resultado) << std::endl;
            std::cout << "Valor da primeira derivada: f'(x) = " << primeira_derivada(resultado) << std::endl;
            std::cout << "Valor da segunda derivada: f''(x) = " << segunda_derivada(resultado) << std::endl;
            break;
            
        case 3: // Pontos de inflexão
            std::cout << "MÉTODO DA SECANTE PARA ENCONTRAR PONTOS DE INFLEXÃO" << std::endl;
            std::cout << "=================================================" << std::endl;
            resultado = metodo_secante_inflexao(x0, x1, eps1, eps2, max_iter);
            
            // Exibindo o resultado
            std::cout << std::endl;
            std::cout << "RESULTADO:" << std::endl;
            std::cout << "Ponto de inflexão: x = " << std::fixed << std::setprecision(10) << resultado << std::endl;
            std::cout << "Valor da função: f(x) = " << f(resultado) << std::endl;
            std::cout << "Valor da segunda derivada: f''(x) = " << segunda_derivada(resultado) << std::endl;
            
            // Verificando se é um ponto de inflexão
            if (fabs(segunda_derivada(resultado)) < eps2) {
                std::cout << "Confirmação: Este é um ponto de inflexão (f''(x) ≈ 0)" << std::endl;
            } else {
                std::cout << "Atenção: O valor de f''(x) não é próximo de zero. Pode não ser um ponto de inflexão." << std::endl;
            }
            break;
            
        default:
            std::cout << "Aplicação inválida!" << std::endl;
            return 1;
    }
    
    return 0;
} 
