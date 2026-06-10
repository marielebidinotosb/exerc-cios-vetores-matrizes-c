#include <stdio.h>

#define DIAS 7
#define PERIODOS 3

// Protótipos das funções obrigatórias
void lerMatriz(float m[][PERIODOS], int dias);
float mediaDiaria(float m[][PERIODOS], int dia);
float maiorDaSemana(float m[][PERIODOS], int dias);
int diaQuente(float m[][PERIODOS], int dias);
void exibirTabela(float m[][PERIODOS], int dias);

int main() {
    float matrizTemperaturas[DIAS][PERIODOS];
    
    // Vetor auxiliar apenas para exibir o nome do dia na main
    const char *diasDaSemana[] = {"Domingo", "Segunda-feira", "Terca-feira", 
                                  "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado"};

    // 1. Entrada de dados
    lerMatriz(matrizTemperaturas, DIAS);

    // 2. Saída da tabela compacta com as médias já calculadas
    exibirTabela(matrizTemperaturas, DIAS);

    // 3. Processamento e exibição dos resultados globais
    float maiorTemp = maiorDaSemana(matrizTemperaturas, DIAS);
    int indiceDiaMaisQuente = diaQuente(matrizTemperaturas, DIAS);

    printf("\n--- Analise Estatistica da Semana ---\n");
    printf("Maior temperatura registrada: %.1f C\n", maiorTemp);
    printf("O dia mais quente (maior media diaria): %s\n", diasDaSemana[indiceDiaMaisQuente]);
    printf("-------------------------------------\n");

    return 0;
}

// --- Implementação das Funções ---

// Função para preencher a matriz 7x3
void lerMatriz(float m[][PERIODOS], int dias) {
    const char *periodos[] = {"Manha", "Tarde", "Noite"};
    
    printf("Digite as temperaturas para os 7 dias da semana:\n");
    for (int i = 0; i < dias; i++) {
        printf("\nDia [%d] (0=Dom, 1=Seg...):\n", i);
        for (int j = 0; j < PERIODOS; j++) {
            printf("  Periodo %s: ", periodos[j]);
            scanf("%f", &m[i][j]);
        }
    }
}

// Função que calcula a média de UMA linha específica (um dia)
float mediaDiaria(float m[][PERIODOS], int dia) {
    float soma = 0;
    for (int j = 0; j < PERIODOS; j++) {
        soma += m[dia][j];
    }
    return soma / PERIODOS;
}

// Função que varre a matriz inteira atrás do maior valor absoluto
float maiorDaSemana(float m[][PERIODOS], int dias) {
    float maior = m[0][0];
    for (int i = 0; i < dias; i++) {
        for (int j = 0; j < PERIODOS; j++) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }
    }
    return maior;
}

// Função que usa a dica do enunciado: chama mediaDiaria() num loop e retorna o índice da maior
int diaQuente(float m[][PERIODOS], int dias) {
    int melhorIndice = 0;
    float maiorMedia = mediaDiaria(m, 0); // Inicializa com a média do primeiro dia (índice 0)

    for (int i = 1; i < dias; i++) {
        float mediaAtual = mediaDiaria(m, i);
        if (mediaAtual > maiorMedia) {
            maiorMedia = mediaAtual;
            melhorIndice = i;
        }
    }
    return melhorIndice;
}

// Função para exibir a tabela formatada e mostrar a média de cada linha ao lado
void exibirTabela(float m[][PERIODOS], int dias) {
    printf("\n================ TABELA DE TEMPERATURAS ================\n");
    printf("%-7s | %-7s | %-7s | %-7s | %-7s\n", "Dia", "Manha", "Tarde", "Noite", "Media");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < dias; i++) {
        float media = mediaDiaria(m, i);
        printf("Dia [%d]  | %-7.1f | %-7.1f | %-7.1f | %-7.1f\n", 
               i, m[i][0], m[i][1], m[i][2], media);
    }
    printf("========================================================\n");
}
