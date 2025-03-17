#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct lista {
    float number;
    struct lista * below;
} Lista;

typedef struct pilha {
    Lista * first;
} Pilha;

Pilha* pilha_cria(void) {
    Pilha * pile = (Pilha *)malloc(sizeof(Pilha));
    pile->first = NULL;
    return pile;
}

void pilha_push (Pilha* p, float v) {
    Lista * newNode = (Lista *)malloc(sizeof(Lista));
    
    newNode->number = v;
    newNode->below = p->first;

    p->first = newNode;
    
}

float pilha_pop (Pilha* p) {
    Lista * retira;
    float number;

    if (pilha_vazia(p)) {
        printf("Pilha vazia\n");
        exit(1);
    }

    retira = p->first;
    number = retira->number;
    p->first = p->first->below;

    free(retira);
    return number;
} 

int pilha_vazia (Pilha* p) {
    int empty = p->first == NULL ? 1 : 0;
    return empty;
} 

void pilha_libera (Pilha* p) {
    Lista *currentNode, *temp;

    currentNode = p->first;

    while (currentNode != NULL) {
        temp = currentNode->below;
        free(currentNode);
        currentNode = temp;
    }
    free(p);
}

float topo (Pilha* p) {
    return p->first->number;
}

void concatena_pilhas (Pilha* p1, Pilha* p2) {
    float numberToAdd;
    
    if (p2->first != NULL) {
        numberToAdd = pilha_pop(p2);
        concatena_pilhas(p1, p2);
        pilha_push(p1,numberToAdd);
    }
}