#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    int id;
    char nome[50];
    struct Item* proximo;
} Item;

Item* inserir_item_inicio(Item* inventario, int id, const char* nome) {
    Item* novo = (Item*) malloc(sizeof(Item));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->proximo = inventario;
    return novo;
}

Item* inserir_item_fim(Item* inventario, int id, const char* nome) {
    Item* novo = (Item*) malloc(sizeof(Item));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->proximo = NULL;

    if (!inventario) {
        return novo;
    }

    Item* atual = inventario;
    while (atual->proximo) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return inventario;
}

Item* inserir_catalisador(Item* inventario, int id_fragmento, int id_catalisador, const char* nome_catalisador) {
    Item* atual = inventario;
    while (atual) {
        if (atual->id == id_fragmento) {
            Item* novo = (Item*) malloc(sizeof(Item));
            novo->id = id_catalisador;
            strcpy(novo->nome, nome_catalisador);
            novo->proximo = atual->proximo;
            atual->proximo = novo;
            return inventario;
        }
        atual = atual->proximo;
    }
    printf("Fragmento de Poder com ID %d não encontrado.\n", id_fragmento);
    return inventario;
}

void mostrar_inventario(Item* inventario) {
    Item* atual = inventario;
    while (atual) {
        printf("ID: %d, Nome: %s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
}

void liberar_inventario(Item* inventario) {
    Item* atual = inventario;
    while (atual) {
        Item* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Item* inventario = NULL;
    int opcao;

    do {
        printf("1 - Inserir item no início\n");
        printf("2 - Inserir item no fim\n");
        printf("3 - Inserir catalisador após um fragmento\n");
        printf("4 - Mostrar inventário\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nome[50];
            printf("ID do item: ");
            scanf("%d", &id);
            printf("Nome do item: ");
            scanf("%s", nome);
            inventario = inserir_item_inicio(inventario, id, nome);
        } else if (opcao == 2) {
            int id;
            char nome[50];
            printf("ID do item: ");
            scanf("%d", &id);
            printf("Nome do item: ");
            scanf("%s", nome);
            inventario = inserir_item_fim(inventario, id, nome);
        } else if (opcao == 3) {
            int id_fragmento, id_catalisador;
            char nome_catalisador[50];
            printf("ID do fragmento: ");
            scanf("%d", &id_fragmento);
            printf("ID do catalisador: ");
            scanf("%d", &id_catalisador);
            printf("Nome do catalisador: ");
            scanf("%s", nome_catalisador);
            inventario = inserir_catalisador(inventario, id_fragmento, id_catalisador, nome_catalisador);
        } else if (opcao == 4) {
            mostrar_inventario(inventario);
        }
    } while (opcao != 5);

    liberar_inventario(inventario);
    return 0;
}