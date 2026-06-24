#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spellbook.h"

Spellbook* create_spellbook() {
    Spellbook *book = (Spellbook *)malloc(sizeof(Spellbook));
    book->inicio = NULL;
    return book;
}

void add_spell(Spellbook* book, int id, const char* name, int mana_cost) {
    Spell *novo = (Spell *)malloc(sizeof(Spell));
    novo->id = id;
    strcpy(novo->name, name);
    novo->mana_cost = mana_cost;
    novo->proximo = NULL;

    if (book->inicio == NULL) {
        book->inicio = novo;
    } else {
        Spell *atual = book->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void display_spellbook(Spellbook* book) {
    Spell *atual = book->inicio;
    while (atual != NULL) {
        printf("ID: %d, Feitiço: %s, Custo de Mana: %d\n", atual->id, atual->name, atual->mana_cost);
        atual = atual->proximo;
    }
}

void destroy_spellbook(Spellbook* book) {
    Spell *atual = book->inicio;
    while (atual != NULL) {
        Spell *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(book);
}