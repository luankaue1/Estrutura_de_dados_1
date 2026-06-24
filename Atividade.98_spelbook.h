#ifndef SPELLBOOK_H
#define SPELLBOOK_H

typedef struct Spell {
    int id;
    char name[50];
    int mana_cost;
    struct Spell *proximo;
} Spell;

typedef struct Spellbook {
    Spell *inicio;
} Spellbook;

Spellbook* create_spellbook();
void add_spell(Spellbook* book, int id, const char* name, int mana_cost);
void display_spellbook(Spellbook* book);
void destroy_spellbook(Spellbook* book);

#endif