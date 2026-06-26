#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heroi {
    int id;
    char nome[50];
    struct Heroi* proximo;
} Heroi;

Heroi* adicionar_heroi_fim(Heroi* formacao, int id, const char* nome) {
    Heroi* novo = (Heroi*) malloc(sizeof(Heroi));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->proximo = NULL;

    if (!formacao) {
        return novo;
    }

    Heroi* atual = formacao;
    while (atual->proximo) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return formacao;
}

Heroi* inserir_antes(Heroi* formacao, int id_vip, int id_guarda, const char* nome_guarda) {
    Heroi* novo = (Heroi*) malloc(sizeof(Heroi));
    novo->id = id_guarda;
    strcpy(novo->nome, nome_guarda);

    if (!formacao) {
        free(novo);
        printf("A lista está vazia.\n");
        return NULL;
    }

    if (formacao->id == id_vip) {
        novo->proximo = formacao;
        return novo;
    }

    Heroi* atual = formacao;
    while (atual->proximo && atual->proximo->id != id_vip) {
        atual = atual->proximo;
    }

    if (!atual->proximo) {
        free(novo);
        printf("VIP com ID %d não encontrado.\n", id_vip);
        return formacao;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
    return formacao;
}

void mostrar_formacao(Heroi* formacao) {
    Heroi* atual = formacao;
    while (atual) {
        printf("ID: %d, Nome: %s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
}

void liberar_formacao(Heroi* formacao) {
    Heroi* atual = formacao;
    while (atual) {
        Heroi* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Heroi* formacao = NULL;
    int opcao;

    do {
        printf("1 - Adicionar Herói no Fim\n");
        printf("2 - Adicionar Guarda-Costas (Inserir Antes)\n");
        printf("3 - Mostrar Formação\n");
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
            formacao = adicionar_heroi_fim(formacao, id, nome);
        } else if (opcao == 2) {
            int id_vip, id_guarda;
            char nome_guarda[50];
            printf("ID do guarda-costas: ");
            scanf("%d", &id_guarda);
            printf("Nome do guarda-costas: ");
            scanf("%s", nome_guarda);
            printf("ID do VIP: ");
            scanf("%d", &id_vip);
            formacao = inserir_antes(formacao, id_vip, id_guarda, nome_guarda);
        } else if (opcao == 3) {
            mostrar_formacao(formacao);
        }
    } while (opcao != 4);

    liberar_formacao(formacao);
    return 0;
}