#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ward {
    int id;
    char nome[100];
    struct Ward* proximo;
} Ward;

Ward* adicionar_ward(Ward* lista, int id, const char* nome) {
    Ward* novo = (Ward*) malloc(sizeof(Ward));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->proximo = NULL;

    if (!lista) {
        return novo;
    }

    Ward* atual = lista;
    while (atual->proximo) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return lista;
}

Ward* deletar_apos(Ward* lista, int id_referencia) {
    Ward* atual = lista;
    while (atual) {
        if (atual->id == id_referencia) {
            if (atual->proximo) {
                Ward* a_deletar = atual->proximo;
                atual->proximo = a_deletar->proximo;
                free(a_deletar);
                return lista;
            } else {
                printf("Não há ward 'após' o ward de referência.\n");
                return lista;
            }
        }
        atual = atual->proximo;
    }
    printf("Ward de referência com ID %d não encontrado.\n", id_referencia);
    return lista;
}

void mostrar_wards(Ward* lista) {
    Ward* atual = lista;
    while (atual) {
        printf("ID: %d, Nome: %s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
}

void liberar_wards(Ward* lista) {
    Ward* atual = lista;
    while (atual) {
        Ward* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Ward* lista = NULL;
    int opcao;

    do {
        printf("1. Adicionar Ward\n");
        printf("2. Lançar 'Ward Shatter'\n");
        printf("3. Mostrar Wards Ativos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nome[100];
            printf("ID do ward: ");
            scanf("%d", &id);
            printf("Nome do ward: ");
            scanf("%s", nome);
            lista = adicionar_ward(lista, id, nome);
        } else if (opcao == 2) {
            int id_referencia;
            printf("ID do ward de referência: ");
            scanf("%d", &id_referencia);
            lista = deletar_apos(lista, id_referencia);
        } else if (opcao == 3) {
            mostrar_wards(lista);
        }
    } while (opcao != 4);

    liberar_wards(lista);
    return 0;
}