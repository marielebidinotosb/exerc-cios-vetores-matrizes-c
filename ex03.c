#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Protótipos das funções obrigatórias
void lerNomes(char nomes[][50], int n);
void paraMaiusculas(char s[]);
void ordenarNomes(char nomes[][50], int n);
int buscarNome(char nomes[][50], int n, char alvo[]);

int main() {
    int tamanho = 5;
    char listaNomes[5][50];
    char nomePesquisa[50];
    int indiceEncontrado;

    // 1. Entrada de dados: lê os 5 nomes
    lerNomes(listaNomes, tamanho);

    // 2. Processamento: Converte cada nome para maiúsculas
    for (int i = 0; i < tamanho; i++) {
        paraMaiusculas(listaNomes[i]);
    }

    // 3. Processamento: Ordena a matriz alfabeticamente
    ordenarNomes(listaNomes, tamanho);

    // Exibe a lista após ser tratada e ordenada
    printf("\n--- Lista de Nomes Ordenada e em Maiusculas ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d: %s\n", i + 1, listaNomes[i]);
    }
    printf("------------------------------------------------\n");

    // 4. Busca: Solicita o nome para pesquisa
    printf("\nDigite um nome para buscar na lista: ");
    fgets(nomePesquisa, 50, stdin);
    nomePesquisa[strcspn(nomePesquisa, "\n")] = '\0'; // Remove o '\n' do fgets

    // Garante que o termo de busca também esteja em maiúsculas para a comparação funcionar
    paraMaiusculas(nomePesquisa);

    // Executa a busca
    indiceEncontrado = buscarNome(listaNomes, tamanho, nomePesquisa);

    // Exibe o resultado da busca
    if (indiceEncontrado != -1) {
        printf("\nSucesso! O nome \"%s\" foi encontrado na posicao (indice) %d da lista ordenada.\n", nomePesquisa, indiceEncontrado);
    } else {
        printf("\nO nome \"%s\" NAO foi encontrado na lista.\n", nomePesquisa);
    }

    return 0;
}

// --- Implementação das Funções ---

// Função para ler as 5 strings
void lerNomes(char nomes[][50], int n) {
    printf("Digite os nomes de %d alunos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Aluno %d: ", i + 1);
        fgets(nomes[i], 50, stdin);
        
        // Remove a quebra de linha '\n' que o fgets armazena ao pressionar Enter
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }
}

// Função que converte uma string individual para maiúsculas (no lugar)
void paraMaiusculas(char s[]) {
    // Percorre caractere por caractere até encontrar o fim da string '\0'
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = toupper((unsigned char)s[i]);
    }
}

// Função de ordenação Bubble Sort utilizando strcmp e strcpy
void ordenarNomes(char nomes[][50], int n) {
    char aux[50]; // Variável auxiliar para a troca de strings
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Se nomes[j] for alfabeticamente maior que nomes[j+1], strcmp retorna maior que 0
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                // Troca de strings usando strcpy
                strcpy(aux, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], aux);
            }
        }
    }
}

// Função que realiza a busca e retorna o índice (ou -1)
int buscarNome(char nomes[][50], int n, char alvo[]) {
    for (int i = 0; i < n; i++) {
        // Se forem idênticas, strcmp retorna 0
        if (strcmp(nomes[i], alvo) == 0) {
            return i;
        }
    }
    return -1;
}
