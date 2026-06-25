#include <stdio.h>
#include "personagem.h"

int main() {
    int num_membros;

    printf("Quantos membros a equipe terá? ");
    scanf("%d", &num_membros);

    Personagem* party = cria_party(num_membros);
    registra_membros(party, num_membros);
    exibe_relatorio(party, num_membros);
    libera_party(party);

    return 0;
}
