#include <stdio.h>
#include "avl.h"
#define MAX 100

int main(void) {
    char vetorEntradas[MAX], vetorRemove[MAX], c;
    Avl* arvore = Avl_criavazia();
    int nEntry = 0, nRemove = 0;

    c = getchar();

    while (c != '0') {
        getchar();
        vetorEntradas[nEntry] = c;
        nEntry++;
        c = getchar();
    }
    getchar();

    for (int i = 0; i < nEntry; i++) {
        arvore = Avl_insere(arvore, vetorEntradas[i]);
        printf("Arvore em ordem:");
        Avl_imprime_ordem(arvore);
        printf("\n\n");
    }

    c = getchar();
    while (c != '0') {
        getchar();
        vetorRemove[nRemove] = c;
        nRemove++;
        c = getchar();
    }
    for (int i = 0; i < nRemove; i++) {
        arvore = Avl_retira(arvore, vetorRemove[i]);
        printf("Arvore em ordem:");
        Avl_imprime_ordem(arvore);
        printf("\n\n");
    }

    Avl_libera(arvore);

    return 0;
}