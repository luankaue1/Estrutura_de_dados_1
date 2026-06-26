#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heroi {
    int id;
    char nome[50];
    struct Heroi* proximo;
} Heroi;

Heroi* adicionar_heroi(Heroi* lista, int id, const char* nome) {
    Heroi* novo = (Heroi*) malloc(sizeof(Heroi));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->proximo = lista;
    return novo;
}

void dispensar_heroi(Heroi** lista, int id) {
    if (*lista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Heroi* atual = *lista;
    Heroi* anterior = NULL;

    while (atual && atual->id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (!atual) {
        printf("Herói com ID %d não encontrado.\n", id);
        return;
    }

    if (anterior) {
        anterior->proximo = atual->proximo;
    } else {
        *lista = atual->proximo;
    }

    free(atual);
}

void mostrar_herois(Heroi* lista) {
    Heroi* atual = lista;
    while (atual) {
        printf("ID: %d, Nome: %s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
}

int main() {
    Heroi* lista = NULL;
    int opcao;

    do {
        printf("1 - Adicionar Herói\n");
        printf("2 - Mostrar todos os Heróis\n");
        printf("3 - Dispensar um Herói por ID\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nome[50];
            printf("ID do herói: ");
            scanf("%d", &id);
            printf("Nome do herói: ");
            scanf("%s", nome);
            lista = adicionar_heroi(lista, id, nome);
        } else if (opcao == 2) {
            mostrar_herois(lista);
        } else if (opcao == 3) {
            int id;
            printf("ID do herói a ser dispensado: ");
            scanf("%d", &id);
            dispensar_heroi(&lista, id);
        }
    } while (opcao != 4);

    return 0;
}