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

Jogador verInicio(Fila *fila) {
Jogador jogador = {-1, ""};
if (fila->inicio != NULL) {
return *(fila->inicio);
}
printf("A fila de matchmaking está vazia!\n");
return jogador;
}

int main() {
Fila *fila = criar_fila();
int opcao;

while (1) {
printf("Menu:\n");
printf("1. Adicionar Jogador na Fila\n");
printf("2. Ver quem é o próximo da Fila\n");
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
Jogador jogador = verInicio(fila);
if (jogador.id != -1) {
printf("O próximo jogador a entrar na partida é: %s (ID: %d)\n", jogador.nickname, jogador.id);
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