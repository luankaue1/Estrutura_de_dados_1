#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movimento {
    int id;
    char nome[50];
} Movimento;

typedef struct No {
    Movimento movimento;
    struct No* proximo;
} No;

typedef struct Lista {
    No* cabeca;
} Lista;

void inserir_movimento(Lista* lista, int id, const char* nome) {
    No* novo = (No*) malloc(sizeof(No));
    novo->movimento.id = id;
    strcpy(novo->movimento.nome, nome);
    novo->proximo = lista->cabeca;
    lista->cabeca = novo;
}

void liberar_lista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->cabeca = NULL;
}

int main() {
    Lista lista = { NULL };
    int opcao;

    do {
        printf("1: Inserir novo movimento\n");
        printf("2: Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nome[50];
            printf("ID do movimento: ");
            scanf("%d", &id);
            printf("Nome do movimento: ");
            scanf("%s", nome);
            inserir_movimento(&lista, id, nome);
        }
    } while (opcao != 2);

    liberar_lista(&lista);
    return 0;
}
