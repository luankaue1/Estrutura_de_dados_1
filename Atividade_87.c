#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int id;
    char nome[50];
    struct Jogador* proximo;
} Jogador;

Jogador* adicionar_jogador_fim(Jogador* fila, int id, const char* nome) {
    Jogador* novo = (Jogador*) malloc(sizeof(Jogador));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->proximo = NULL;

    if (!fila) {
        return novo;
    }

    Jogador* atual = fila;
    while (atual->proximo) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return fila;
}

Jogador* iniciar_partida(Jogador* fila) {
    if (!fila) {
        printf("Não há jogadores na fila.\n");
        return NULL;
    }

    Jogador* removido = fila;
    fila = fila->proximo;
    free(removido);
    return fila;
}

void mostrar_fila(Jogador* fila) {
    Jogador* atual = fila;
    while (atual) {
        printf("ID: %d, Nome: %s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
}

void liberar_fila(Jogador* fila) {
    Jogador* atual = fila;
    while (atual) {
        Jogador* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Jogador* fila = NULL;
    int opcao;

    do {
        printf("1: Adicionar jogador ao fim\n");
        printf("2: Iniciar partida\n");
        printf("3: Mostrar fila de espera\n");
        printf("4: Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nome[50];
            printf("ID do jogador: ");
            scanf("%d", &id);
            printf("Nome do jogador: ");
            scanf("%s", nome);
            fila = adicionar_jogador_fim(fila, id, nome);
        } else if (opcao == 2) {
            fila = iniciar_partida(fila);
        } else if (opcao == 3) {
            mostrar_fila(fila);
        }
    } while (opcao != 4);

    liberar_fila(fila);
    return 0;
}