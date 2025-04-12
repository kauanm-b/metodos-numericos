# 📊 Métodos Numéricos

![Python](https://img.shields.io/badge/Python-3.8%2B-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow)

## 📚 Sobre o Projeto

Este repositório contém implementações de diversos métodos numéricos para resolução de problemas matemáticos. O projeto foi desenvolvido como parte do curso de Métodos Numéricos, oferecendo uma abordagem prática e visual para compreensão dos conceitos.

## 🎯 Funcionalidades

### 🔍 Área 1 - Métodos para Encontrar Raízes e Otimização

#### Aula 1 - Fundamentos e Bissecção
- 📈 **Localização de Raízes**
  - Identificação de intervalos com raízes reais
  - Visualização gráfica dos intervalos
  - Seleção flexível de funções

- 🔄 **Método da Bissecção**
  - Implementação do algoritmo de busca por bissecção
  - Visualização passo a passo da convergência
  - Cálculo de erro relativo

- ⚙️ **Precisão Numérica**
  - Demonstração de problemas de arredondamento
  - Comparação entre tipos numéricos
  - Análise de erros de representação

#### Aula 2 - Métodos de Convergência Mais Rápida
- 📐 **Método da Posição Falsa**
  - Implementação do algoritmo
  - Análise de convergência acelerada
  - Cálculo de erro relativo

- 🚀 **Método de Newton-Raphson**
  - Implementação com derivadas
  - Convergência quadrática
  - Visualização das iterações

- 🔄 **Newton-Raphson Discreto**
  - Versão sem derivadas analíticas
  - Aproximação por diferenças finitas
  - Ideal para funções complexas

#### Aula 3 - Métodos Avançados
- 📊 **Método da Secante**
  - Implementação do algoritmo
  - Convergência super-linear
  - Visualização do processo

- 🔍 **Pontos de Inflexão**
  - Identificação por método da secante
  - Cálculo da derivada segunda
  - Visualização gráfica

#### Aula 4 - Sistemas Lineares
- 🔢 **Método de Gauss-Jacobi**
  - Resolução iterativa
  - Análise de convergência
  - Cálculo de erro relativo

- 📐 **Método de Gauss-Jordan**
  - Eliminação gaussiana
  - Forma escalonada
  - Visualização passo a passo

- 🚀 **Método de Gauss-Seidel**
  - Convergência acelerada
  - Atualização em tempo real
  - Comparação com Jacobi

## 🛠️ Tecnologias Utilizadas

- Python 3.8+
- NumPy para cálculos numéricos
- Matplotlib para visualizações
- SciPy para funções científicas

## 📦 Instalação

```bash
# Clone o repositório
git clone https://github.com/kauanm-b/metodos-numericos.git

# Entre no diretório
cd metodos-numericos

# Instale as dependências
pip install -r requirements.txt
```

## 🚀 Como Usar

1. Navegue até a área desejada
2. Execute o arquivo Python correspondente
3. Siga as instruções na interface do programa

## 📝 Exemplos de Uso

```python
# Exemplo de uso do método da bissecção
from metodos_numericos.bissecao import encontrar_raiz

raiz = encontrar_raiz(funcao, intervalo_a, intervalo_b, precisao)
```

## 🤝 Contribuindo

Contribuições são sempre bem-vindas! Por favor, leia as diretrizes de contribuição antes de enviar um pull request.

1. Faça um Fork do projeto
2. Crie uma Branch para sua Feature (`git checkout -b feature/AmazingFeature`)
3. Faça o Commit das suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. Faça o Push para a Branch (`git push origin feature/AmazingFeature`)
5. Abra um Pull Request

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## 👥 Autores

- **Kauan** - *Trabalho Inicial* - [kauanm-b](https://github.com/kauanm-b)

## 🙏 Agradecimentos

- Professor orientador
- Colegas de classe
- Comunidade Python 