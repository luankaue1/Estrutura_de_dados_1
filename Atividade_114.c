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

void carregarFila(Fila *fila, const char *nomeArquivo) {
FILE *arquivo = fopen(nomeArquivo, "rb");
if (arquivo == NULL) {
printf("Nenhum arquivo encontrado. Iniciando com uma fila vazia.\n");
return;
}

Jogador temp;
while (fread(&temp, sizeof(Jogador), 1, arquivo) == 1) {
inserir(fila, temp.id, temp.nickname);
}

fclose(arquivo);
printf("Fila carregada com sucesso.\n");
}

void mostrar(Fila *fila) {
if (fila->inicio == NULL) {
printf("A fila de matchmaking está vazia.\n");
return;
}

Jogador *atual = fila->inicio;
while (atual != NULL) {
printf("ID: %d, Nickname: %s\n", atual->id, atual->nickname);
atual = atual->proximo;
}
}

int main() {
Fila *fila = criar_fila();
carregarFila(fila, "matchmaking_queue.bin");

int opcao;

while (1) {
printf("Menu:\n");
printf("1. Adicionar Jogador na Fila\n");
printf("2. Mostrar Fila\n");
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
mostrar(fila);
} else if (opcao == 3) {
break;
} else {
printf("Opção inválida. Tente novamente.\n");
}
}
free(fila);
return 0;
}