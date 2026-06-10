#include <stdio.h>

// Protótipos das funções obrigatórias
void lerVetor(int v[], int n);
int buscar(int v[], int n, int alvo);
int contar(int v[], int n, int alvo);
void exibirInverso(int v[], int n);

int main() {
    int tamanho = 15;
    int vetor[tamanho];
    int numeroAlvo, indiceEncontrado, qtdVezes;

    // 1. Preenche o vetor com os 15 inteiros
    lerVetor(vetor, tamanho);

    // Perguntar ao usuário qual número ele deseja pesquisar
    printf("\nDigite um numero inteiro para buscar e contar no vetor: ");
    scanf("%d", &numeroAlvo);

    // 2. Executa as operações de busca e contagem
    indiceEncontrado = buscar(vetor, tamanho, numeroAlvo);
    qtdVezes = contar(vetor, tamanho, numeroAlvo);

    // Exibe os resultados da busca
    printf("\n--- Resultados da Busca ---\n");
    if (indiceEncontrado != -1) {
        printf("O numero %d existe no vetor (encontrado primeiro no indice %d).\n", numeroAlvo, indiceEncontrado);
    } else {
        printf("O numero %d NAO existe no vetor.\n", numeroAlvo);
    }
    printf("O numero %d aparece %d vez(es) no vetor.\n", numeroAlvo, qtdVezes);

    // 3. Exibe o vetor em ordem inversa (usando a dica do enunciado)
    exibirInverso(vetor, tamanho);

    return 0;
}

// --- Implementação das Funções ---

// Função para ler os 15 números inteiros
void lerVetor(int v[], int n) {
    printf("Digite %d numeros inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &v[i]);
    }
}

// Função que busca um número e retorna o seu índice (ou -1 se não encontrar)
int buscar(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {
            return i; // Retorna o índice da primeira ocorrência e encerra a função
        }
    }
    return -1; // Se percorrer todo o vetor e não achar, retorna -1
}

// Função que conta quantas vezes o número aparece no vetor
int contar(int v[], int n, int alvo) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {
            contador++;
        }
    }
    return contador;
}

// Função que exibe o vetor de trás para frente
void exibirInverso(int v[], int n) {
    printf("\n--- Vetor em Ordem Inversa ---\n");
    // Seguindo a dica: de n-1 até 0 de forma decrescente
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", v[i]);
    }
    printf("\n------------------------------\n");
}
