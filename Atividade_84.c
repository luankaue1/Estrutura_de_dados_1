#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Missao {
    int id;
    char titulo[50];
    char status[20];
    struct Missao* proximo;
} Missao;

Missao* adicionar_missao(Missao* diario, int id, const char* titulo, const char* status) {
    Missao* nova = (Missao*) malloc(sizeof(Missao));
    nova->id = id;
    strcpy(nova->titulo, titulo);
    strcpy(nova->status, status);
    nova->proximo = diario;
    return nova;
}

void mostrar_missoes(Missao* diario) {
    Missao* atual = diario;
    while (atual) {
        printf("ID: %d, Título: %s, Status: %s\n", atual->id, atual->titulo, atual->status);
        atual = atual->proximo;
    }
}

Missao* pesquisar_missao(Missao* diario, int id) {
    Missao* atual = diario;
    while (atual) {
        if (atual->id == id) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void liberar_diario(Missao* diario) {
    Missao* atual = diario;
    while (atual) {
        Missao* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Missao* diario = NULL;
    int opcao;

    do {
        printf("1 - Adicionar Missão\n");
        printf("2 - Mostrar Missões\n");
        printf("3 - Buscar Missão por ID\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char titulo[50], status[20];
            printf("ID da missão: ");
            scanf("%d", &id);
            printf("Título da missão: ");
            scanf("%s", titulo);
            printf("Status da missão: ");
            scanf("%s", status);
            diario = adicionar_missao(diario, id, titulo, status);
        } else if (opcao == 2) {
            mostrar_missoes(diario);
        } else if (opcao == 3) {
            int id;
            printf("Digite o ID da missão: ");
            scanf("%d", &id);
            Missao* encontrada = pesquisar_missao(diario, id);
            if (encontrada) {
                printf("Missão encontrada: ID: %d, Título: %s, Status: %s\n", 
                       encontrada->id, encontrada->titulo, encontrada->status);
            } else {
                printf("Missão não encontrada!\n");
            }
        }
    } while (opcao != 4);

    liberar_diario(diario);
    return 0;
}
