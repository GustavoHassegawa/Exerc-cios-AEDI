#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

#define V NULL

int main() {
    int alturaArv1, custoArv1, alturaArv2, custoArv2;
    Arv* arvore1 = criavazia();
    Arv* arvore1Esq = criavazia();
    Arv* arvore1Dir = criavazia();

    Arv* arvore2 = criavazia();
    Arv* arvore2Esq = criavazia();
    Arv* arvore2Dir = criavazia();

    arvore1Esq = cria(11, cria(5, V, V), V);
    arvore1Esq = cria(24, arvore1Esq, cria(19, V, V));
    arvore1Dir = cria(17, cria(7, V, V), cria(9, V, V));
    arvore1 = cria(34, arvore1Esq, arvore1Dir);

    arvore2Esq = cria(4, cria(3, cria(1, V, V),cria(1, V, V)), cria(3, cria(1, V, V), V));
    arvore2Dir = cria(3, cria(1, V, V), cria(1, V, V));
    arvore2 = cria(4, arvore2Esq, arvore2Dir);



    alturaArv1 = altura_arv(arvore1);
    custoArv1 = custo(arvore1);
    alturaArv2 = altura_arv(arvore2);
    custoArv2 = custo(arvore2);

    printf("Arvore 1:\n");
    printf("altura = %d\n", alturaArv1);
    printf("soma dos pesos do maior caminho = %d\n", custoArv1);
    
    printf("Arvore 2:\n");
    printf("altura = %d\n", alturaArv2);
    printf("soma dos pesos do maior caminho = %d\n", custoArv2);
    

    libera(arvore1);
    libera(arvore2);
    return 0;
}