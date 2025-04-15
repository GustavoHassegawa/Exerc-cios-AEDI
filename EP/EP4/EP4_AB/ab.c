#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
}Arv;

// Raiz apontando para NULL
Arv* criavazia (void) {
    return NULL;
}

/*Função para criar um novo nó da árvore, recebendo como parâmetros a informação
 *e as duas subárvores (que podem ser vazias, isto é, NULL)*/
Arv* cria (int v, Arv *esq, Arv *dir) {
    Arv * raiz =(Arv*)malloc(sizeof(Arv));
    raiz->info = v;
    raiz->esq = esq;
    raiz->dir = dir;
    return raiz;
}

//Função recursiva para liberar os nós a partir da raiz r
void libera (Arv* r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

/* A altura de uma árvore é equivalente ao comprimento do caminho mais longo da 
 *raiz até uma das folhas. Considerando que: a altura de uma árvore com um único 
 *nó raiz é 1 e a altura de uma árvore vazia é 0, escreva uma função que retorne 
 *a altura de uma árvore binária. */
int altura_arv(Arv* a) {
    if (a != NULL) {

        int alturaDir = altura_arv(a->dir);
        int alturaEsq = altura_arv(a->esq);

        if (alturaEsq > alturaDir) 
            return alturaEsq + 1;
        else 
            return alturaDir + 1;
    } else 
        return 0;
}

/* O custo de um caminho em uma árvore é a soma das chaves dos nós participantes
 * nesse caminho. Considere uma árvore binária de chaves inteiras. Escreva uma 
 * função que retorne o custo do caminho de maior valor da raiz para um nó folha
 * . */
int custo (Arv* a) {
    if (a != NULL) {

        int custoDir = custo(a->dir);
        int custoEsq = custo(a->esq);

        if (custoEsq > custoDir) 
            return custoEsq + a->info;
        else 
            return custoDir + a->info;
    } else 
        return 0;
}