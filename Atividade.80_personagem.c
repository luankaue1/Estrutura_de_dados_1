#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personagem.h"

struct personagem {
    char nome[50];
    char classe[50];
    int nivel;
    int hp;
};

Personagem* cria_party(int num_membros) {
    return (Personagem*) malloc(num_membros * sizeof(Personagem));
}

void registra_membros(Personagem* party, int num_membros) {
    for (int i = 0; i < num_membros; i++) {
        printf("Nome do membro %d: ", i + 1);
        scanf("%s", party[i].nome);
        printf("Classe do membro %d: ", i + 1);
        scanf("%s", party[i].classe);
        printf("Nível do membro %d: ", i + 1);
        scanf("%d", &party[i].nivel);
        printf("HP do membro %d: ", i + 1);
        scanf("%d", &party[i].hp);
    }
}

void exibe_relatorio(const Personagem* party, int num_membros) {
    for (int i = 0; i < num_membros; i++) {
        printf("Membro %d: %s, Classe: %s, Nível: %d, HP: %d\n", 
               i + 1, party[i].nome, party[i].classe, party[i].nivel, party[i].hp);
    }
}

void libera_party(Personagem* party) {
    free(party);
}
