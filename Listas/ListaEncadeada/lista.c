#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
    int info;
    struct lista * prox;
};

Lista* insere_ultimo (Lista *L) {
    Lista * currentNode = L;
    Lista * newNode = malloc(sizeof(Lista));

    printf("Insira o valor do novo nó: ");
    scanf('%d',&newNode->info);

    while (currentNode->prox != NULL)
        currentNode = currentNode->prox;
    
    currentNode->prox = newNode;
    return L;
}   

Lista* concatena (Lista *L1, Lista *L2) {
    Lista* currentNode = L1;

    while (currentNode->prox != NULL)
        currentNode = currentNode->prox;

    currentNode->prox = L2;

    return L1;
}

Lista* inverte (Lista *L) {
    Lista * currentNode = L;
    Lista * previousNode = NULL;
    Lista * temp;

    while (currentNode->prox != NULL) {
        if (previousNode == NULL) {
            previousNode = currentNode;
            currentNode = currentNode->prox;
            previousNode->prox == NULL;
        } else {
            temp = previousNode;
            previousNode = currentNode;
            currentNode = currentNode->prox;
            previousNode->prox == temp;
        }
    }

    currentNode->prox = previousNode;
    L = currentNode;

    return L;
}

Lista* retira_n (Lista *L, int n); 

Lista*concatena_ord (Lista *L1, Lista *L2);

Lista* uniao (Lista *L1, Lista *L2);

Lista* intersecao (Lista *L1, Lista *L2);

int maiores (Lista* l, int x);
