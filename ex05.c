#include <stdio.h>
#include <string.h>

#define MAX 10

// Variáveis Globais (conforme especificado na imagem)
char nomes[MAX][50];
char fones[MAX][20];
int total = 0; 

// Protótipos das funções obrigatórias
void cadastrar();
void listar();
int buscar(char nome[]);
void remover(int idx);
void menu();

int main() {
    // A main apenas inicia o menu coordenador
    menu();
    return 0;
}

// --- Implementação das Funções ---

// Função que exibe as opções e gerencia o fluxo de chamadas
void menu() {
    int opcao;
    char nomeBusca[50];
    int indice;

    do {
        printf("\n======= MINI-AGENDA (Contatos: %d/%d) =======\n", total, MAX);
        printf("1. Cadastrar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato por Nome\n");
        printf("4. Remover Contato\n");
        printf("0. Sair do Programa\n");
        printf("=============================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o caractere '\n' do buffer do scanf

        switch (opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
                listar();
                break;
            case 3:
                if (total == 0) {
                    printf("\nA agenda esta vazia.\n");
                } else {
                    printf("\nDigite o nome para buscar: ");
                    fgets(nomeBusca, 50, stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
                    
                    indice = buscar(nomeBusca);
                    if (indice != -1) {
                        printf("\nContato encontrado! Telefone: %s\n", fones[indice]);
                    } else {
                        printf("\nContato nao encontrado.\n");
                    }
                }
                break;
            case 4:
                if (total == 0) {
                    printf("\nA agenda esta vazia. Nao ha o que remover.\n");
                } else {
                    printf("\nDigite o nome exato do contato que deseja remover: ");
                    fgets(nomeBusca, 50, stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
                    
                    indice = buscar(nomeBusca);
                    if (indice != -1) {
                        remover(indice);
                    } else {
                        printf("\nContato nao localizado para remocao.\n");
                    }
                }
                break;
            case 0:
                printf("\nEncerrando a agenda. Ate mais!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

// Função para cadastrar um novo contato
void cadastrar() {
    if (total >= MAX) {
        printf("\nErro: A agenda esta cheia!\n");
        return;
    }

    printf("\n--- Cadastrar Novo Contato ---\n");
    printf("Nome: ");
    fgets(nomes[total], 50, stdin);
    nomes[total][strcspn(nomes[total], "\n")] = '\0'; // Remove o '\n'

    printf("Telefone: ");
    fgets(fones[total], 20, stdin);
    fones[total][strcspn(fones[total], "\n")] = '\0'; // Remove o '\n'

    total++; // Incrementa o contador global de contatos
    printf("Contato cadastrado com sucesso!\n");
}

// Função para listar todos os contatos cadastrados
void listar() {
    if (total == 0) {
        printf("\nA agenda nao possui nenhum contato cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Contatos ---\n");
    printf("%-4s | %-25s | %-15s\n", "Idx", "Nome", "Telefone");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-4d | %-25s | %-15s\n", i, nomes[i], fones[i]);
    }
    printf("--------------------------------------------------\n");
}

// Função que busca um nome e retorna o índice ou -1
int buscar(char nome[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            return i; // Encontrou, retorna o índice corrente
        }
    }
    return -1; // Percorreu tudo e não achou
}

// Função que remove o contato copiando o último para a vaga (conforme a dica)
void remover(int idx) {
    printf("\nRemovendo contato: %s...\n", nomes[idx]);
    
    // Se o contato a ser removido NÃO for o último, movemos o último para a posição dele
    if (idx != total - 1) {
        strcpy(nomes[idx], nomes[total - 1]);
        strcpy(fones[idx], fones[total - 1]);
    }
    
    // Decrementa o total global. O último elemento antigo fica fora do limite lógico do vetor
    total--; 
    printf("Contato removido de forma limpa!\n");
}
