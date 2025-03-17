#include <stdio.h>
#include "pilha.h"

int main (void) {
    int sizeP1, sizeP2;
    float number;
    Pilha *p1 = pilha_cria(), *p2 = pilha_cria();

    printf("Insira o tamanho da pilha P1: ");
    scanf("%d", &sizeP1);
    printf("Insira o tamanho da pilha P2: ");
    scanf("%d", &sizeP2);

    printf("Insira os valores da pilha P1:\n");

    for (int i = 0; i < sizeP1; i++) {
        scanf("%f", &number);
        pilha_push(p1, number);
    }

    printf("Insira os valores da pilha P2:\n");

    for (int i = 0; i < sizeP2; i++) {
        scanf("%f", &number);
        pilha_push(p2, number);
    }
    
    concatena_pilhas(p1, p2);

    printf("PILHAS CONCATENADAS:\n");
    while (!pilha_vazia(p1)) {
        number = pilha_pop(p1);
        printf("%.1f\n", number);
    }

    pilha_libera(p1);
    pilha_libera(p2);

    return 0;
}