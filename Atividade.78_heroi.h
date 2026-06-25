#ifndef HEROI_H
#define HEROI_H

typedef struct Heroi Heroi;

Heroi* alocar_herois(int num_herois);
void ler_herois(Heroi* herois, int num_herois);
void imprimir_herois(const Heroi* herois, int num_herois);

#endif
