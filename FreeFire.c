#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Constantes globais
#define MAX_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 10

// Estrutura de dados
struct Territorio {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
};

// Protótipos das funções
struct Territorio* alocarMapa();
void inicializarTerritorios(struct Territorio* mapa);
void exibirMapa(const struct Territorio* mapa);
void liberarMemoria(struct Territorio* mapa);
void limparBufferEntrada();

// Função principal
int main() {
    struct Territorio* mapa = alocarMapa(); 
    if (mapa == NULL) {
        printf("Errro ao alocar memória!\n");
        return 1;
    }

    inicializarTerritorios(mapa);
    exibirMapa(mapa);
    liberarMemoria(mapa);

    return 0;
}

// Implementação de funções

struct Territorio* alocarMapa() {
    struct Territorio* mapa = (struct Territorio*) calloc(MAX_TERRITORIOS, sizeof(struct Territorio));
    return mapa;
}

void inicializarTerritorios(struct Territorio* mapa) {
    printf("=== Cadastro de territórios ===\n");

    for (int i = 0; i <MAX_TERRITORIOS; i++) {
        printf("Território %d: \n", i + 1);

        printf("Digite o nome: ");
        fgets(mapa[i].nome, TAM_NOME, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Digite a cor do exército: ");
        fgets(mapa[i].cor, TAM_COR, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparBufferEntrada();

        printf("\n");
    }
}

void exibirMapa(const struct Territorio* mapa) {
    printf("\n=== Territórios cadastrados ===\n\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d: \n", i + 1);
        printf("Nome: %s\n", mapa [i].nome);
        printf("Cor do exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
        printf("-----------------\n");
    }
}

void liberarMemoria(struct Territorio* mapa) {
    free(mapa);
}

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}