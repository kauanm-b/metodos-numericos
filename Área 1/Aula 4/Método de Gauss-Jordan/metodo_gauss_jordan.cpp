/**
 * Método de Gauss-Jordan para Resolução de Sistemas Lineares
 * 
 * Este programa implementa o método de Gauss-Jordan para resolver sistemas
 * de equações lineares. O método transforma a matriz dos coeficientes
 * em uma matriz identidade, obtendo a solução diretamente.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * Função para resolver um sistema linear pelo método de Gauss-Jordan
 * @param A Matriz dos coeficientes (será modificada)
 * @param b Vetor dos termos independentes (será modificado)
 * @param x Vetor solução
 * @param n Dimensão do sistema
 * @return true se o sistema tem solução, false caso contrário
 */
bool metodo_gauss_jordan(double A[20][20], double b[20], double x[20], int n) {
    double m;
    int i, j, k;
    
    // Exibindo o sistema original
    std::cout << "Sistema original:" << std::endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            std::cout << std::setw(8) << A[i][j] << " ";
        }
        std::cout << "| " << std::setw(8) << b[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Eliminação progressiva
    for (k = 0; k < n - 1; k++) {
        std::cout << "Passo " << k + 1 << " - Eliminação progressiva:" << std::endl;
        
        for (i = k + 1; i < n; i++) {
            m = A[i][k] / A[k][k];
            A[i][k] = 0;
            
            for (j = k + 1; j < n; j++) {
                A[i][j] -= m * A[k][j];
            }
            
            b[i] -= m * b[k];
        }
        
        // Exibindo o sistema após cada passo
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                std::cout << std::setw(8) << A[i][j] << " ";
            }
            std::cout << "| " << std::setw(8) << b[i] << std::endl;
        }
        std::cout << std::endl;
    }
    
    // Verificando se o sistema tem solução
    if (fabs(A[n-1][n-1]) < 1e-10) {
        std::cout << "ERRO: Sistema sem solução única (matriz singular)" << std::endl;
        return false;
    }
    
    // Substituição regressiva
    x[n-1] = b[n-1] / A[n-1][n-1];
    
    for (k = n - 2; k >= 0; k--) {
        double s = 0;
        for (j = k + 1; j < n; j++) {
            s += A[k][j] * x[j];
        }
        x[k] = (b[k] - s) / A[k][k];
    }
    
    return true;
}

int main() {
    // Parâmetros do sistema
    int n = 3;  // Número de equações e variáveis
    
    // Matriz dos coeficientes
    double A[20][20] = {
        {2, 4, 2},
        {3, 5, 2},
        {4, 0, 5}
    };
    
    // Vetor dos termos independentes
    double b[20] = {-8, -9, -1};
    
    // Vetor solução
    double x[20];
    
    std::cout << "MÉTODO DE GAUSS-JORDAN PARA RESOLUÇÃO DE SISTEMAS LINEARES" << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << "Sistema de " << n << " equações e " << n << " variáveis" << std::endl << std::endl;
    
    // Aplicando o método de Gauss-Jordan
    bool sucesso = metodo_gauss_jordan(A, b, x, n);
    
    // Exibindo o resultado
    if (sucesso) {
        std::cout << "Solução do sistema:" << std::endl;
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