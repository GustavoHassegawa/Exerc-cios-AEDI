#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

Vetor cria(double x, double y, double z) {
    Vetor v = malloc(sizeof(Vetor));
    
    v->x = x;
    v->y = y;
    v->z = z;
    
    return v;
}

void libera(Vetor v) {
    free(v);
}

Vetor soma(Vetor v1, Vetor v2) {
    Vetor resposta = malloc(sizeof(Vetor));

    resposta->x = v1->x + v2->x;
    resposta->y = v1->y + v2->y;
    resposta->z = v1->z + v2->z;

    return resposta;
}

double prodint(Vetor v1, Vetor v2) {
    double resposta = 0; 

    resposta += v1->x * v2->x;
    resposta += v1->y * v2->y;
    resposta += v1->z * v2->z;

    return resposta;
}

Vetor prodvet(Vetor v1, Vetor v2) {
    Vetor resposta = malloc(sizeof(Vetor));

    resposta->x = v1->y * v2->z - v1->z * v2->y;
    resposta->y = v1->z * v2->x - v1->x * v2->z;
    resposta->z = v1->x * v2->y - v1->y * v2->x;

    return resposta;
}
