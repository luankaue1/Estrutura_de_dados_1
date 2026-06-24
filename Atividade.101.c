#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Feitico {
    char nome[50];
    int custo_mana;
    struct Feitico* proximo;
} Feitico;

typedef struct Pilha {
    Feitico* topo;
} Pilha;

Pilha* criar_pilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha* p, const char* nome, int custo_mana) {
    Feitico* novo = (Feitico*)malloc(sizeof(Feitico));
    strcpy(novo->nome, nome);
    novo->custo_mana = custo_mana;
    novo->proximo = p->topo;
    p->topo = novo;
}

void mostrar_pilha(Pilha* p) {
    if (p->topo == NULL) {
        printf("A pilha de comandos está vazia.\n");
        return;
    }
    Feitico* atual = p->topo;
    while (atual != NULL) {
        printf("Feitiço: %s, Custo de Mana: %d\n", atual->nome, atual->custo_mana);
        atual = atual->proximo;
    }
}

void liberar_pilha(Pilha* p) {
    while (p->topo != NULL) {
        Feitico* temp = p->topo;
        p->topo = p->topo->proximo;
        free(temp);
    }
}

int main() {
    Pilha* pilha = criar_pilha();
    int opcao;

    while (1) {
        printf("Menu:\n");
        printf("1: Adicionar um novo feitiço à pilha de comandos.\n");
        printf("2: Mostrar Pilha de Comandos.\n");
        printf("3: Finalizar a sequência de comandos e sair.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            char nome[50];
            int custo_mana;
            printf("Digite o nome do feitiço e o custo de mana: ");
            scanf("%s %d", nome, &custo_mana);
            push(pilha, nome, custo_mana);
        } else if (opcao == 2) {
            mostrar_pilha(pilha);
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    liberar_pilha(pilha);
    free(pilha);
    return 0;
}