# 🧮 Métodos Numéricos

<div align="center">

![C/C++](https://img.shields.io/badge/C%2FC%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

</div>

## 🗂️ Estrutura do Projeto

### 📂 Área 1 - Métodos para Resolução de Equações
- 🎯 **Aula 1**: 
  - Precisão Numérica
  - Localização de Raízes
  - Método da Bissecção
- 📊 **Aula 2**: 
  - Método da Posição Falsa
  - Método de Newton-Raphson
  - Método de Newton-Raphson Discreto
- 📈 **Aula 3**: 
  - Método da Secante
  - Pontos de Máximos e Mínimos Locais e Pontos de Inflexão
- 🔢 **Aula 4**: 
  - Método de Gauss-Jordan
  - Método de Gauss-Jacobi
  - Método de Gauss-Seidel

### 📂 Área 2
- 🚧 Em desenvolvimento...

### 📂 Área 3
- 🚧 Em desenvolvimento...

## 🛠️ Requisitos

- Compilador C/C++ (gcc/g++)
- Editor de código (VS Code, Dev-C++, etc.)

## 🤝 Contribuições

Sinta-se à vontade para contribuir com este projeto! 

1. 🍴 Faça um fork do repositório
2. 🌿 Crie uma branch para sua feature (`git checkout -b feature/nova-feature`)
3. 💾 Commit suas mudanças (`git commit -m 'Adiciona nova feature'`)
4. 📤 Push para a branch (`git push origin feature/nova-feature`)
5. 🔄 Abra um Pull Request

## 📝 Exemplos de Código

```c
// Exemplo de implementação do Método da Bissecção
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 4; // f(x) = x² - 4
}

int main() {
    double a = 0, b = 3;
    double c;
    int iter = 0;
    
    while (fabs(b-a) > 1e-6) {
        c = (a + b)/2;
        if (f(c) == 0) break;
        if (f(a)*f(c) < 0) b = c;
        else a = c;
        iter++;
    }
    
    printf("Raiz encontrada: %f\n", c);
    return 0;
}
```

## 📊 Visualização dos Resultados

Para visualizar os resultados, você pode usar:
- 📈 Gnuplot
- 📊 Python com matplotlib
- 🎨 Qualquer outro software de plotagem

## 📫 Contato

Se você tiver dúvidas ou sugestões, sinta-se à vontade para abrir uma issue!

---

<div align="center">
  
### ⭐️ Se este projeto foi útil para você, considere dar uma estrela! ⭐️

</div>

## Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes. "# metodos-numericos" 
