#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etapa {
    int id;
    char descricao[100];
    struct Etapa* proximo;
} Etapa;

Etapa* adicionar_etapa(Etapa* lista, int id, const char* descricao) {
    Etapa* nova = (Etapa*) malloc(sizeof(Etapa));
    nova->id = id;
    strcpy(nova->descricao, descricao);
    nova->proximo = NULL;

    if (!lista) {
        return nova;
    }

    Etapa* atual = lista;
    while (atual->proximo) {
        atual = atual->proximo;
    }
    atual->proximo = nova;
    return lista;
}

Etapa* deletar_antes(Etapa* lista, int id_referencia) {
    if (!lista || lista->id == id_referencia) {
        printf("Não há etapa antes do ID %d.\n", id_referencia);
        return lista;
    }

    Etapa* atual = lista;
    Etapa* anterior = NULL;

    while (atual && atual->proximo && atual->proximo->id != id_referencia) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (!atual || !atual->proximo) {
        printf("Etapa com ID %d não encontrada.\n", id_referencia);
        return lista;
    }

    Etapa* a_deletar = atual->proximo;
    atual->proximo = a_deletar->proximo;
    free(a_deletar);
    return lista;
}

void mostrar_etapas(Etapa* lista) {
    Etapa* atual = lista;
    while (atual) {
        printf("ID: %d, Descrição: %s\n", atual->id, atual->descricao);
        atual = atual->proximo;
    }
}

void liberar_etapas(Etapa* lista) {
    Etapa* atual = lista;
    while (atual) {
        Etapa* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Etapa* lista = NULL;
    int opcao;

    do {
        printf("1 - Inserir etapa no fim da lista\n");
        printf("2 - Mostrar todas as etapas da missão\n");
        printf("3 - Deletar etapa ANTES de um ID específico\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char descricao[100];
            printf("ID da etapa: ");
            scanf("%d", &id);
            printf("Descrição da etapa: ");
            scanf("%s", descricao);
            lista = adicionar_etapa(lista, id, descricao);
        } else if (opcao == 2) {
            mostrar_etapas(lista);
        } else if (opcao == 3) {
            int id_referencia;
            printf("ID da etapa de referência: ");
            scanf("%d", &id_referencia);
            lista = deletar_antes(lista, id_referencia);
        }
    } while (opcao != 4);

    liberar_etapas(lista);
    return 0;
}