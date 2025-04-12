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
    double d[20];
    double dmax;
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
    
    // Inicializando valores com x[i] = b[i]/A[i][i] (como no código padrão)
    std::cout << "Valores iniciais:" << std::endl;
    for (i = 0; i < n; i++) {
        x[i] = b[i] / A[i][i];
        std::cout << "x" << i + 1 << "^(0) = " << std::fixed << std::setprecision(12) << x[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Iterações do método
    for (iter = 1; iter <= max_iter; iter++) {
        std::cout << "-------------- Passo " << std::setw(2) << iter << " --------------" << std::endl;
        
        // Salvando valores anteriores
        for (i = 0; i < n; i++) {
            x_antigo[i] = x[i];
        }
        
        // Calculando novos valores (implementação mais eficiente como no código padrão)
        for (i = 0; i < n; i++) {
            x[i] = b[i];
            for (j = 0; j < n; j++) {
                if (i == j) continue;
                if (i > j) {
                    x[i] = x[i] - A[i][j] * x[j];
                } else {
                    x[i] = x[i] - A[i][j] * x_antigo[j];
                }
            }
            x[i] = x[i] / A[i][i];
            std::cout << "x" << i + 1 << "^(" << iter << ") = " << std::fixed << std::setprecision(12) << x[i] << std::endl;
        }
        
        // Verificando convergência (calculando diferença máxima como no código padrão)
        dmax = 0;
        std::cout << std::endl;
        for (i = 0; i < n; i++) {
            d[i] = fabs(x[i] - x_antigo[i]);
            std::cout << "d[" << i << "] = " << std::fixed << std::setprecision(12) << d[i] << std::endl;
            if (d[i] > dmax) dmax = d[i];
        }
        
        if (dmax < e) {
            std::cout << "\n          d[max] < eps\n" << std::fixed << std::setprecision(12) 
                      << dmax << " < " << e << " --->>> convergencia alcancada." << std::endl;
            std::cout << "--------------------------------------\n" << std::endl;
            return true;
        }
        
        std::cout << "\n          d[max] > eps\n" << std::fixed << std::setprecision(12) 
                  << dmax << " > " << e << " --->>> continuar" << std::endl;
        std::cout << "--------------------------------------\n" << std::endl;
    }
    
    std::cout << "ERRO: Não convergiu em " << max_iter << " iterações" << std::endl;
    return false;
}

int main() {
    // Parâmetros do sistema
    int n = 3;  // Número de equações e variáveis
    double e = 5e-2;  // Tolerância
    int max_iter = 100;  // Número máximo de iterações
    
    // Matriz dos coeficientes
    double A[20][20] = {
        {10, 2, 1},
        {1, 5, 1},
        {2, 3, 10}
    };
    
    // Vetor dos termos independentes
    double b[20] = {7, -8, 6};
    
    // Vetor solução inicial (será inicializado dentro da função)
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
        std::cout << "\nVetor final calculado:" << std::endl;
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