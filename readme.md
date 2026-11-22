# Implementação de Grafos em C — Rede de Distribuição

##  Sobre o projeto

Este projeto foi desenvolvido para a atividade avaliativa de implementação de grafos utilizando a linguagem C.

O sistema representa uma rede de distribuição composta por centros de distribuição e locais de entrega, permitindo realizar buscas no grafo por meio de dois algoritmos: **Busca em Profundidade (DFS)** e **Busca em Largura (BFS)**.

A aplicação possui um menu interativo que permite ao usuário escolher o algoritmo, informar o vértice de origem e o vértice de destino, além de visualizar os resultados da busca.

##  Objetivos

- Implementar um grafo utilizando matriz de adjacência.
- Aplicar o algoritmo de Busca em Profundidade (DFS).
- Aplicar o algoritmo de Busca em Largura (BFS).
- Utilizar recursividade e backtracking na DFS.
- Utilizar uma estrutura de fila na BFS.
- Exibir o caminho percorrido e informações da busca.

##  Estrutura do grafo

O grafo representa uma rede de distribuição com 6 vértices:

| Código | Vértice |
|---|---|
| 0 | D0 |
| 1 | CD1 |
| 2 | CD2 |
| 3 | L1 |
| 4 | L2 |
| 5 | L3 |

As conexões entre os vértices são representadas por uma matriz de adjacência ponderada, em que os valores maiores que zero indicam a existência de uma aresta e seu respectivo peso.

### Conexões existentes

- D0 → CD1 (peso 4)
- D0 → CD2 (peso 8)
- CD1 → CD2 (peso 2)
- CD1 → L1 (peso 5)
- CD1 → L2 (peso 9)
- CD2 → L2 (peso 3)
- CD2 → L3 (peso 4)

##  Funcionalidades

O programa disponibiliza um menu interativo com as seguintes opções:

- **1 – Busca em Profundidade (DFS):** explora os caminhos do grafo aprofundando-se em cada vértice antes de retornar ao anterior.
- **2 – Busca em Largura (BFS):** explora os vértices por níveis, utilizando uma fila.
- **0 – Sair:** encerra a execução do programa.

Durante a execução, o usuário informa o vértice de origem e o destino desejado.

##  Algoritmos implementados

### Busca em Profundidade (DFS)

A DFS (Depth-First Search) utiliza recursividade para explorar o grafo. O algoritmo visita um vértice e continua explorando seus vizinhos não visitados até chegar ao destino ou não encontrar mais possibilidades.

O backtracking permite retornar aos vértices anteriores quando necessário, continuando a exploração de outros caminhos.

### Busca em Largura (BFS)

A BFS (Breadth-First Search) utiliza uma estrutura de fila para explorar os vértices por níveis.

Primeiro, visita os vizinhos diretos da origem e, posteriormente, os vizinhos dos vértices encontrados, até localizar o destino ou finalizar a busca.

##  Informações apresentadas

Ao finalizar cada busca, o sistema apresenta:

- Vértice de origem;
- Vértices visitados;
- Sequência de descoberta;
- Quantidade de vértices visitados;
- Quantidade de arestas percorridas;
- Caminho encontrado até o destino;
- Indicação se o objetivo foi encontrado.

##  Tecnologias utilizadas

- Linguagem C
- Matriz de adjacência
- Recursividade
- Backtracking
- Estrutura de fila
- Algoritmos de grafos (DFS e BFS)

##  Como executar

1. Clone o repositório:

```bash
git clone https://github.com/SEU-USUARIO/SEU-REPOSITORIO.git
```

2. Entre na pasta do projeto:

```bash
cd SEU-REPOSITORIO
```

3. Compile o programa utilizando GCC:

```bash
gcc grafo.c -o grafo
```

4. Execute:

**Windows:**

```bash
grafo.exe
```

**Linux:**

```bash
./grafo
```

##  Exemplo de utilização

Ao iniciar o programa, será apresentado o menu:

```text
====================================
       SISTEMA DE BUSCA EM GRAFOS
        REDE DE DISTRIBUICAO
====================================
1 - Busca em Profundidade (DFS)
2 - Busca em Largura (BFS)
0 - Sair

Escolha uma opcao:
```

O usuário escolhe o algoritmo, informa a origem e o destino, e o programa apresenta os resultados da busca.

##  Desenvolvedoras

- **Ana Beatriz Barreto Teixeira**
- **Livia Pontes Argenton**
- **Raissa Albuquerque Diniz**

---

Desenvolvido para a atividade avaliativa de Implementação de Grafos em C.
