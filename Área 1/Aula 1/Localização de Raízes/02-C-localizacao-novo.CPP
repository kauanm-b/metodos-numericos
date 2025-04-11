#include <stdio.h>
#include <math.h>

// Função f(x) = x³ - 9x + 3
double f(double x) {
    return pow(x, 3) - 9 * x + 3;
}

int main() {
    double a = -20, b = 20, passo = 1;
    
    printf("Localizando raízes de f(x) = x³ - 9x + 3\n\n");
    
    for (double x = a; x < b; x += passo) {
        // Se f(x) e f(x+passo) têm sinais opostos, existe raiz no intervalo
        if (f(x) * f(x + passo) < 0) {
            printf("Raiz no intervalo [%lf; %lf]\n", x, x + passo);
        }
    }
    
    printf("\nPressione Enter para sair...");
    getchar();
    return 0;
} 