#include <stdio.h>
#include "spellbook.h"

int main() {
    Spellbook* grimorio = create_spellbook();

    add_spell(grimorio, 1, "Bola de Fogo", 30);
    add_spell(grimorio, 2, "Cura", 20);
    add_spell(grimorio, 3, "Relâmpago", 40);

    printf("Grimório:\n");
    display_spellbook(grimorio);

    destroy_spellbook(grimorio);
    return 0;
}