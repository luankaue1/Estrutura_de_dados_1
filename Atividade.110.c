#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int id;
    char nickname[50];
    struct Jogador *proximo;
} Jogador;

typedef struct Fila {
    Jogador *inicio;
    Jogador *fim;
} Fila;

Fila* criar_fila() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void inserir(Fila *fila, int id, const char *nickname) {
    Jogador *novo = (Jogador *)malloc(sizeof(Jogador));
    novo->id = id;
    strcpy(novo->nickname, nickname);
    novo->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

Jogador remover(Fila *fila) {
    Jogador jogador = {-1, ""};
    if (fila->inicio == NULL) {
        printf("A fila de matchmaking está vazia!\n");
        return jogador;
    }
    
    Jogador *temp = fila->inicio;
    jogador = *temp;
    fila->inicio = fila->inicio->proximo;
    free(temp);
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    return jogador;
}

int main() {
    Fila *fila = criar_fila();
    int opcao;

    while (1) {
        printf("Menu:\n");
        printf("1. Adicionar Jogador na Fila\n");
        printf("2. Remover Jogador da Fila\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nickname[50];
            printf("Digite o ID e o nickname do jogador: ");
            scanf("%d %s", &id, nickname);
            inserir(fila, id, nickname);
        } else if (opcao == 2) {
            Jogador jogador = remover(fila);
            if (jogador.id != -1) {
                printf("O jogador %s (ID: %d) foi removido da fila e entrou em uma partida.\n", jogador.nickname, jogador.id);
            }
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
    free(fila);
    return 0;
}