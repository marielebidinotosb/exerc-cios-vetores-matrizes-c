#include <stdio.h>

// Protótipos das funções obrigatórias
void lerNotas(float notas[], int n);
float calcularMedia(float notas[], int n);
float maiorNota(float notas[], int n);
float menorNota(float notas[], int n);
void exibirResultados(float media, float maior, float menor);

int main() {
    int tamanho = 10;
    float vetorNotas[tamanho];
    
    // Variáveis para armazenar os resultados dos cálculos
    float media, maior, menor;

    // 1. Entrada de dados
    lerNotas(vetorNotas, tamanho);

    // 2. Processamento/Cálculos
    media = calcularMedia(vetorNotas, tamanho);
    maior = maiorNota(vetorNotas, tamanho);
    menor = menorNota(vetorNotas, tamanho);

    // 3. Saída de dados
    exibirResultados(media, maior, menor);

    return 0;
}

// --- Implementação das Funções ---

// Função para ler as 10 notas do aluno
void lerNotas(float notas[], int n) {
    printf("Digite as %d notas do aluno:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
}

// Função para calcular a média aritmética das notas
float calcularMedia(float notas[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += notas[i];
    }
    return soma / n;
}

// Função para encontrar a maior nota (usando a dica de inicializar com notas[0])
float maiorNota(float notas[], int n) {
    float maior = notas[0]; 
    for (int i = 1; i < n; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }
    return maior;
}

// Função para encontrar a menor nota (usando a dica de inicializar com notas[0])
float menorNota(float notas[], int n) {
    float menor = notas[0]; 
    for (int i = 1; i < n; i++) {
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }
    return menor;
}

// Função para exibir os resultados formatados na tela
void exibirResultados(float media, float maior, float menor) {
    printf("\n--- Estatísticas das Notas ---\n");
    printf("Média do aluno: %.2f\n", media);
    printf("Maior nota:     %.2f\n", maior);
    printf("Menor nota:     %.2f\n", menor);
    printf("------------------------------\n");
}
