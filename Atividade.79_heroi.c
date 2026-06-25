#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heroi.h"

struct Heroi {
    char nome[50];
    int hp;
    int ataque;
};

Heroi* alocar_herois(int num_herois) {
    return (Heroi*) malloc(num_herois * sizeof(Heroi));
}

void ler_herois(Heroi* herois, int num_herois) {
    for (int i = 0; i < num_herois; i++) {
        printf("Nome do herói %d: ", i + 1);
        scanf("%s", herois[i].nome);
        printf("HP do herói %d: ", i + 1);
        scanf("%d", &herois[i].hp);
        printf("Ataque do herói %d: ", i + 1);
        scanf("%d", &herois[i].ataque);
    }
}

void imprimir_herois(const Heroi* herois, int num_herois) {
    for (int i = 0; i < num_herois; i++) {
        printf("Herói %d: %s, HP: %d, Ataque: %d\n", i + 1, herois[i].nome, herois[i].hp, herois[i].ataque);
    }
}
