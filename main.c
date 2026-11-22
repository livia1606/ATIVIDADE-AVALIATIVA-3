#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6

// Identificacao dos vertices
char *vertices[N] = {
    "D0", "CD1", "CD2", "L1", "L2", "L3"
};

// Matriz de adjacencia ponderada
int grafo[N][N] = {
    {0, 4, 8, 0, 0, 0},
    {0, 0, 2, 5, 9, 0},
    {0, 0, 0, 0, 3, 4},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
};

// Variaveis para armazenar os resultados
int visitados[N];
int ordem[N];
int pai[N];
int quantidadeVisitados;
int quantidadeArestas;
int destino;
int encontrou;

// Imprime o caminho de descoberta ate o destino
void mostrarCaminho(int destino) {
    int caminho[N];
    int tamanho = 0;
    int atual = destino;

    while (atual != -1) {
        caminho[tamanho++] = atual;
        atual = pai[atual];
    }

    printf("Caminho ate o objetivo: ");

    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%s", vertices[caminho[i]]);

        if (i > 0)
            printf(" -> ");
    }

    printf("\n");
}

// Inicializa os dados da busca
void inicializarBusca() {
    for (int i = 0; i < N; i++) {
        visitados[i] = 0;
        pai[i] = -1;
    }

    quantidadeVisitados = 0;
    quantidadeArestas = 0;
    encontrou = 0;
}

// =================================================
// BUSCA EM PROFUNDIDADE - DFS
// Utiliza recursividade e backtracking
// =================================================

void DFS(int atual) {

    // Marca o vertice como visitado
    visitados[atual] = 1;

    // Armazena a ordem de visita
    ordem[quantidadeVisitados++] = atual;

    printf("Visitando: %s\n", vertices[atual]);

    // Verifica se encontrou o destino
    if (atual == destino) {
        encontrou = 1;
        return;
    }

    // Percorre os vizinhos
    for (int i = 0; i < N; i++) {

        if (grafo[atual][i] > 0 && !visitados[i]) {

            quantidadeArestas++;
            pai[i] = atual;

            printf("Percorrendo arco: %s -> %s\n",
                   vertices[atual], vertices[i]);

            // Chamada recursiva
            DFS(i);

            // Backtracking:
            // retorna a execucao ao vertice anterior
            if (encontrou)
                return;
        }
    }
}

// =================================================
// BUSCA EM LARGURA - BFS
// Utiliza estrutura de fila
// =================================================

void BFS(int origem) {

    int fila[N];
    int inicio = 0;
    int fim = 0;

    // Marca a origem como visitada
    visitados[origem] = 1;
    fila[fim++] = origem;

    while (inicio < fim) {

        // Retira o primeiro elemento da fila
        int atual = fila[inicio++];

        // Registra a visita
        ordem[quantidadeVisitados++] = atual;

        printf("Visitando: %s\n", vertices[atual]);

        // Verifica se encontrou o destino
        if (atual == destino) {
            encontrou = 1;
            break;
        }

        // Analisa os vizinhos do vertice atual
        for (int i = 0; i < N; i++) {

            if (grafo[atual][i] > 0 && !visitados[i]) {

                visitados[i] = 1;
                pai[i] = atual;

                quantidadeArestas++;

                printf("Percorrendo arco: %s -> %s\n",
                       vertices[atual], vertices[i]);

                // Insere o vizinho na fila
                fila[fim++] = i;
            }
        }
    }
}

// =================================================
// RELATORIO DOS RESULTADOS
// =================================================

void mostrarResultados(int origem) {

    printf("\n========== RESULTADO DA BUSCA ==========\n");

    printf("Vertice de origem: %s\n", vertices[origem]);

    printf("Vertices visitados: ");

    for (int i = 0; i < quantidadeVisitados; i++) {
        printf("%s", vertices[ordem[i]]);

        if (i < quantidadeVisitados - 1)
            printf(" -> ");
    }

    printf("\n");

    printf("Quantidade de vertices visitados: %d\n",
           quantidadeVisitados);

    printf("Quantidade de arestas percorridas: %d\n",
           quantidadeArestas);

    printf("Sequencia de descoberta: ");

    for (int i = 0; i < quantidadeVisitados; i++) {
        printf("%s", vertices[ordem[i]]);

        if (i < quantidadeVisitados - 1)
            printf(" -> ");
    }

    printf("\n");

    if (encontrou) {
        printf("Objetivo encontrado: SIM\n");
        mostrarCaminho(destino);
    } else {
        printf("Objetivo encontrado: NAO\n");
        printf("Nao existe caminho ate o destino informado.\n");
    }

    printf("========================================\n");
}

// =================================================
// FUNCAO PRINCIPAL
// =================================================

int main() {

    int opcao;
    int origem;

    do {

        printf("\n");
        printf("====================================\n");
        printf("       SISTEMA DE BUSCA EM GRAFOS\n");
        printf("        REDE DE DISTRIBUICAO\n");
        printf("====================================\n");

        printf("1 - Busca em Profundidade (DFS)\n");
        printf("2 - Busca em Largura (BFS)\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1 || opcao == 2) {

            printf("\nVertices disponiveis:\n");

            for (int i = 0; i < N; i++) {
                printf("%d - %s\n", i, vertices[i]);
            }

            printf("Informe o numero do vertice de origem: ");
            scanf("%d", &origem);

            if (origem < 0 || origem >= N) {
                printf("Vertice de origem invalido!\n");
                continue;
            }

            printf("Informe o numero do vertice de destino: ");
            scanf("%d", &destino);

            if (destino < 0 || destino >= N) {
                printf("Vertice de destino invalido!\n");
                continue;
            }

            inicializarBusca();

            if (opcao == 1) {

                printf("\n--- EXECUTANDO DFS ---\n");

                DFS(origem);

            } else {

                printf("\n--- EXECUTANDO BFS ---\n");

                BFS(origem);
            }

            mostrarResultados(origem);

        } else if (opcao == 0) {

            printf("\nEncerrando o programa...\n");

        } else {

            printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
