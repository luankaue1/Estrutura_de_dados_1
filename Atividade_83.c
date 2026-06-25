#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int matricula;
    char nome[50];
    struct Jogador* proximo;
} Jogador;

typedef struct Fila {
    Jogador* inicio;
    Jogador* fim;
} Fila;

Fila* criar_fila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void adicionar_jogador_fim(Fila* fila, int matricula, const char* nome) {
    Jogador* novo = (Jogador*) malloc(sizeof(Jogador));
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    novo->proximo = NULL;

    if (fila->fim) {
        fila->fim->proximo = novo;
    } else {
        fila->inicio = novo;
    }
    fila->fim = novo;
}

void mostrar_fila(Fila* fila) {
    Jogador* atual = fila->inicio;
    while (atual) {
        printf("Matrícula: %d, Nome: %s\n", atual->matricula, atual->nome);
        atual = atual->proximo;
    }
}

void liberar_fila(Fila* fila) {
    Jogador* atual = fila->inicio;
    while (atual) {
        Jogador* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(fila);
}

int main() {
    Fila* fila = criar_fila();
    int opcao;

    do {
        printf("1 - Adicionar jogador no fim da fila\n");
        printf("2 - Mostrar fila\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int matricula;
            char nome[50];
            printf("Matrícula do jogador: ");
            scanf("%d", &matricula);
            printf("Nome do jogador: ");
            scanf("%s", nome);
            adicionar_jogador_fim(fila, matricula, nome);
        } else if (opcao == 2) {
            mostrar_fila(fila);
        }
    } while (opcao != 3);

    liberar_fila(fila);
    return 0;
}
