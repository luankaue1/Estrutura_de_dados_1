#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int matricula;
    char nome[50];
    struct Jogador* proximo;
} Jogador;

typedef struct Lista {
    Jogador* inicio;
} Lista;

void deletar_fim(Lista* plista) {
    if (!plista->inicio) {
        printf("Não é possível remover jogadores. A lista está vazia.\n");
        return;
    }

    if (!plista->inicio->proximo) {
        free(plista->inicio);
        plista->inicio = NULL;
        return;
    }

    Jogador* atual = plista->inicio;
    while (atual->proximo->proximo) {
        atual = atual->proximo;
    }

    free(atual->proximo);
    atual->proximo = NULL;
}

void adicionar_jogador(Lista* plista, int matricula, const char* nome) {
    Jogador* novo = (Jogador*) malloc(sizeof(Jogador));
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    novo->proximo = plista->inicio;
    plista->inicio = novo;
}

void mostrar_lista(Lista* plista) {
    Jogador* atual = plista->inicio;
    while (atual) {
        printf("Matrícula: %d, Nome: %s\n", atual->matricula, atual->nome);
        atual = atual->proximo;
    }
}

int main() {
    Lista lista = { NULL };
    int opcao;

    do {
        printf("1 - Adicionar jogador\n");
        printf("2 - Mostrar jogadores\n");
        printf("3 - Deletar do fim\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int matricula;
            char nome[50];
            printf("Matrícula do jogador: ");
            scanf("%d", &matricula);
            printf("Nome do jogador: ");
            scanf("%s", nome);
            adicionar_jogador(&lista, matricula, nome);
        } else if (opcao == 2) {
            mostrar_lista(&lista);
        } else if (opcao == 3) {
            deletar_fim(&lista);
        }
    } while (opcao != 4);

    return 0;
}