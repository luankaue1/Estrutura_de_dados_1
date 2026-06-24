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

int vazia(Pilha* p) {
    return p->topo == NULL;
}

void carregar_pilha_de_arquivo(Pilha* p, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Nenhum grimório encontrado, iniciando com uma pilha vazia.\n");
        return;
    }

    Feitico temp;
    while (fread(&temp, sizeof(Feitico), 1, arquivo) == 1) {
        push(p, temp.nome, temp.custo_mana);
    }
    fclose(arquivo);
    printf("Pilha carregada com sucesso.\n");
}

void mostrar_pilha(Pilha* p) {
    if (vazia(p)) {
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
    while (!vazia(p)) {
        pop(p);
    }
}

int main() {
    Pilha* pilha = criar_pilha();
    carregar_pilha_de_arquivo(pilha, "grimorio.bin");

    int opcao;

    while (1) {
        printf("Menu:\n");
        printf("1: Adicionar um novo feitiço à pilha de comandos.\n");
        printf("2: Lançar Próximo Feitiço.\n");
        printf("3: Mostrar Pilha de Comandos.\n");
        printf("4: Salvar Sequência no Grimório.\n");
        printf("5: Finalizar a sequência de comandos e sair.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            char nome[50];
            int custo_mana;
            printf("Digite o nome do feitiço e o custo de mana: ");
            scanf("%s %d", nome, &custo_mana);
            push(pilha, nome, custo_mana);
        } else if (opcao == 2) {
            Feitico feitico = pop(pilha);
            if (feitico.custo_mana != -1) {
                printf("Feitiço '%s' lançado com sucesso!\n", feitico.nome);
            }
        } else if (opcao == 3) {
            mostrar_pilha(pilha);
        } else if (opcao == 4) {
            salvar_pilha_em_arquivo(pilha, "grimorio.bin");
        } else if (opcao == 5) {
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    liberar_pilha(pilha);
    free(pilha);
    return 0;
}