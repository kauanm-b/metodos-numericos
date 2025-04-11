/**
 * Método de Gauss-Seidel para Resolução de Sistemas Lineares
 * 
 * Este programa implementa o método de Gauss-Seidel para resolver sistemas
 * de equações lineares. O método é iterativo e converge para a solução
 * se a matriz dos coeficientes for diagonalmente dominante.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * Função para resolver um sistema linear pelo método de Gauss-Seidel
 * @param A Matriz dos coeficientes
 * @param b Vetor dos termos independentes
 * @param x Vetor solução inicial e final
 * @param n Dimensão do sistema
 * @param e Tolerância para convergência
 * @param max_iter Número máximo de iterações
 * @return true se convergiu, false caso contrário
 */
bool metodo_gauss_seidel(double A[20][20], double b[20], double x[20], int n, double e, int max_iter) {
    double x_antigo[20];
    double soma;
    int i, j, iter;
    
    // Exibindo o sistema original
    std::cout << "Sistema original:" << std::endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            std::cout << std::setw(8) << A[i][j] << " ";
        }
        std::cout << "| " << std::setw(8) << b[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Exibindo valores iniciais
    std::cout << "Valores iniciais:" << std::endl;
    for (i = 0; i < n; i++) {
        std::cout << "x" << i + 1 << " = " << x[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Iterações do método
    for (iter = 1; iter <= max_iter; iter++) {
        // Salvando valores anteriores
        for (i = 0; i < n; i++) {
            x_antigo[i] = x[i];
        }
        
        // Calculando novos valores
        for (i = 0; i < n; i++) {
            soma = 0;
            for (j = 0; j < n; j++) {
                if (j != i) {
                    soma += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - soma) / A[i][i];
        }
        
        // Exibindo iteração atual
        std::cout << "Iteração " << iter << ":" << std::endl;
        for (i = 0; i < n; i++) {
            std::cout << "x" << i + 1 << " = " << std::fixed << std::setprecision(12) << x[i] << std::endl;
        }
        
        // Verificando convergência
        bool convergiu = true;
        for (i = 0; i < n; i++) {
            if (fabs(x[i] - x_antigo[i]) > e) {
                convergiu = false;
                break;
            }
        }
        
        if (convergiu) {
            std::cout << "\nConvergiu em " << iter << " iterações!" << std::endl;
            return true;
        }
        
        std::cout << std::endl;
    }
    
    std::cout << "ERRO: Não convergiu em " << max_iter << " iterações" << std::endl;
    return false;
}

int main() {
    // Parâmetros do sistema
    int n = 3;  // Número de equações e variáveis
    double e = 1e-6;  // Tolerância
    int max_iter = 100;  // Número máximo de iterações
    
    // Matriz dos coeficientes
    double A[20][20] = {
        {10, 2, 1},
        {1, 5, 1},
        {2, 3, 10}
    };
    
    // Vetor dos termos independentes
    double b[20] = {7, -8, 6};
    
    // Vetor solução inicial
    double x[20] = {0, 0, 0};
    
    std::cout << "MÉTODO DE GAUSS-SEIDEL PARA RESOLUÇÃO DE SISTEMAS LINEARES" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "Sistema de " << n << " equações e " << n << " variáveis" << std::endl;
    std::cout << "Tolerância: " << e << std::endl;
    std::cout << "Máximo de iterações: " << max_iter << std::endl << std::endl;
    
    // Aplicando o método de Gauss-Seidel
    bool sucesso = metodo_gauss_seidel(A, b, x, n, e, max_iter);
    
    // Exibindo o resultado
    if (sucesso) {
        std::cout << "\nSolução do sistema:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << "x" << i + 1 << " = " << std::fixed << std::setprecision(12) << x[i] << std::endl;
        }
        
        // Verificando a solução
        std::cout << "\nVerificação da solução:" << std::endl;
        for (int i = 0; i < n; i++) {
            double res = 0;
            for (int j = 0; j < n; j++) {
                res += A[i][j] * x[j];
            }
            std::cout << "Equação " << i + 1 << ": " << std::fixed << std::setprecision(12) 
                      << res << " ≈ " << b[i] << " (diferença: " << fabs(res - b[i]) << ")" << std::endl;
        }
    }
    
    return 0;
} 