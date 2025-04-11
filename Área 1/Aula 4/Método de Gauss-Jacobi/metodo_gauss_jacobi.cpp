/**
 * Método de Gauss-Jacobi para Resolução de Sistemas Lineares
 * 
 * Este programa implementa o método de Gauss-Jacobi para resolver sistemas
 * de equações lineares. O método é iterativo e converge para a solução
 * se a matriz dos coeficientes for diagonalmente dominante.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * Função para resolver um sistema linear pelo método de Gauss-Jacobi
 * @param A Matriz dos coeficientes
 * @param b Vetor dos termos independentes
 * @param x Vetor solução (inicial e final)
 * @param n Dimensão do sistema
 * @param eps Tolerância para o critério de parada
 * @param max_iter Número máximo de iterações
 * @return Número de iterações realizadas
 */
int metodo_gauss_jacobi(double A[20][20], double b[20], double x[20], int n, double eps, int max_iter) {
    double x_novo[20];
    double d[20];
    double dmax;
    int i, j, k;
    
    // Exibindo valores iniciais
    std::cout << "\nValores iniciais:" << std::endl;
    for (i = 0; i < n; i++) {
        x[i] = b[i] / A[i][i];
        std::cout << "x" << i << "^(0) = " << std::fixed << std::setprecision(12) << x[i] << std::endl;
    }
    
    // Iterações do método
    for (k = 0; k < max_iter; k++) {
        std::cout << "\n-------------- Passo " << std::setw(2) << k + 1 << " --------------\n";
        
        // Calculando nova aproximação
        for (i = 0; i < n; i++) {
            x_novo[i] = b[i];
            for (j = 0; j < n; j++) {
                if (i == j) continue;
                x_novo[i] = x_novo[i] - A[i][j] * x[j];
            }
            x_novo[i] = x_novo[i] / A[i][i];
            std::cout << "x" << i << "^(" << k + 1 << ") = " << std::fixed << std::setprecision(12) << x_novo[i] << std::endl;
        }
        
        // Calculando diferenças e verificando convergência
        dmax = 0;
        std::cout << "\n";
        for (i = 0; i < n; i++) {
            d[i] = fabs(x_novo[i] - x[i]);
            std::cout << "d[" << i << "] = " << std::fixed << std::setprecision(12) << d[i] << std::endl;
            if (d[i] > dmax) dmax = d[i];
        }
        
        // Verificando critério de parada
        if (dmax < eps) {
            std::cout << "\n          d[max] < eps\n" << std::fixed << std::setprecision(12) 
                      << dmax << " < " << eps << " --->>> convergencia alcancada.\n"
                      << "--------------------------------------\n\n";
            break;
        }
        
        std::cout << "\n          d[max] > eps\n" << std::fixed << std::setprecision(12) 
                  << dmax << " > " << eps << " --->>> continuar\n"
                  << "--------------------------------------\n\n";
        
        // Atualizando valores para próxima iteração
        for (i = 0; i < n; i++) {
            x[i] = x_novo[i];
        }
    }
    
    return k + 1;
}

int main() {
    // Parâmetros do sistema
    int n = 3;  // Número de equações e variáveis
    double eps = 5E-2;  // Critério de parada
    
    // Matriz dos coeficientes
    double A[20][20] = {
        {10, 2, 1},
        {1, 5, 1},
        {2, 3, 10}
    };
    
    // Vetor dos termos independentes
    double b[20] = {7, -8, 6};
    
    // Vetor solução
    double x[20];
    
    std::cout << "MÉTODO DE GAUSS-JACOBI PARA RESOLUÇÃO DE SISTEMAS LINEARES" << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << "Sistema de " << n << " equações e " << n << " variáveis" << std::endl;
    std::cout << "Critério de parada: eps = " << eps << std::endl << std::endl;
    
    // Exibindo o sistema
    std::cout << "Sistema:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(5) << A[i][j] << " ";
        }
        std::cout << "| " << std::setw(5) << b[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Aplicando o método de Gauss-Jacobi
    int iteracoes = metodo_gauss_jacobi(A, b, x, n, eps, 100);
    
    // Exibindo o resultado
    std::cout << "Vetor solução calculado em " << iteracoes << " iterações:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "x" << i << " = " << std::fixed << std::setprecision(12) << x[i] << std::endl;
    }
    
    // Verificando a solução
    std::cout << "\nVerificação da solução:" << std::endl;
    for (int i = 0; i < n; i++) {
        double res = 0;
        for (int j = 0; j < n; j++) {
            res += A[i][j] * x[j];
        }
        std::cout << "Equação " << i << ": " << std::fixed << std::setprecision(12) 
                  << res << " ≈ " << b[i] << " (diferença: " << fabs(res - b[i]) << ")" << std::endl;
    }
    
    return 0;
} 