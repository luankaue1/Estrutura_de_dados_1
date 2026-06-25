#include <stdio.h>
#include "combate.h"

int main() {
    int ataque_base, bonus_arma, vida_inimigo;

    printf("Ataque base do herói: ");
    scanf("%d", &ataque_base);
    printf("Bônus da espada: ");
    scanf("%d", &bonus_arma);
    printf("Vida inicial do inimigo: ");
    scanf("%d", &vida_inimigo);

    int ataque_total = calcular_ataque_total(ataque_base, bonus_arma);
    vida_inimigo = aplicar_dano(vida_inimigo, ataque_total);

    printf("Poder de ataque total: %d\n", ataque_total);
    printf("Vida restante do inimigo: %d\n", vida_inimigo);

    return 0;
}
