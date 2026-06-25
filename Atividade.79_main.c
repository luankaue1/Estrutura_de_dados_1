#include <stdio.h>
#include "heroi.h"

int main() {
    int num_herois;

    printf("Quantos heróis na equipe? ");
    scanf("%d", &num_herois);

    Heroi* equipe = alocar_herois(num_herois);
    ler_herois(equipe, num_herois);
    imprimir_herois(equipe, num_herois);

    free(equipe);
    return 0;
}
