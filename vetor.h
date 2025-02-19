#ifndef VETOR_H
#define VETOR_H

typedef struct vetor {
    double x;
    double y;
    double z;
} *Vetor;

Vetor cria(double x, double y, double z);

void libera(Vetor v);

Vetor soma(Vetor v1, Vetor v2);

double prodint(Vetor v1, Vetor v2);

Vetor prodvet(Vetor v1, Vetor v2);

#endif