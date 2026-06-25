#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aventureiro {
    int id;
    char nome[50];
    struct Aventureiro* proximo;
} Aventureiro;

Aventureiro* adicionar_aventureiro(Aventureiro* grupo, int id, const char* nome) {
    Aventureiro* novo = (Aventureiro*) malloc(sizeof(Aventureiro));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->proximo = grupo;
    return novo;
}

void mostrar_grupo(Aventureiro* grupo) {
    Aventureiro* atual = grupo;
    while (atual) {
        printf("ID: %d, Nome: %s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
}

void liberar_grupo(Aventureiro* grupo) {
    Aventureiro* atual = grupo;
    while (atual) {
        Aventureiro* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Aventureiro* grupo = NULL;
    int opcao;

    do {
        printf("1: Adicionar Aventureiro\n");
        printf("2: Mostrar Grupo\n");
        printf("3: Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nome[50];
            printf("ID do aventureiro: ");
            scanf("%d", &id);
            printf("Nome do aventureiro: ");
            scanf("%s", nome);
            grupo = adicionar_aventureiro(grupo, id, nome);
        } else if (opcao == 2) {
            mostrar_grupo(grupo);
        }
    } while (opcao != 3);

    liberar_grupo(grupo);
    return 0;
}
