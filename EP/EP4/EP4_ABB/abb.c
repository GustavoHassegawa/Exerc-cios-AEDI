#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

typedef struct arv {
    char info;
    struct arv * dir;
    struct arv * esq;
} Arv;

// Raiz apontando para NULL
Arv* criavazia (void) {
    return NULL;
}

// Função recursiva para liberar os nós a partir da raiz r
void libera (Arv* r) {
    if (r != NULL) {
        libera(r->dir);
        libera(r->esq);
        free(r);
    }
}

// Busca de acordo com a ordenação da árvore
Arv* busca (Arv* r, char v) {
    if (v < r->info)
        busca(r->esq, v);
    else if (v > r->info)
        busca(r->dir, v);
    else
        return r;
}

// Função de inserção
Arv* insere (Arv* r, char v) {
    if (r == NULL) {
        r = (Arv *) malloc(sizeof(Arv));
        r->info = v;
        r->esq = r->dir = NULL;
    } else if (v < r->info)
        r->esq = insere(r->esq, v);
    else if (v >= r->info)
        r->dir = insere(r->dir, v);
    
    return r;
}

// Função de remoção
Arv* retira (Arv* r, char c) {
    if (r == NULL)
        return NULL;
    else if (r->info > c)
        r->esq = retira(r->esq, c);
    else if (r->info < c)
        r->dir = retira(r->dir, c);
    else {
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        } else if (r->esq == NULL) {
            Arv* t = r;
            r = r->dir;
            free(t);
        } else if (r->dir == NULL) {
            Arv* t = r;
            r = r->esq;
            free(t);
        } else {
            Arv* f = r->esq;
            while (f->dir != NULL) {
                f = f->dir;
            }
            r->info = f->info;
            f->info = c;
            r->esq = retira(r->esq, c);
        }
    }
    return r;
}

/*Pré-ordem: Exibir o valor atual, depois visitar a subárvore esquerda e a subárvore direita.*/

void preOrdem(Arv* r) {
    if (r != NULL) {
        printf("%c ", r->info);
        preOrdem(r->esq);
        preOrdem(r->dir);
    }
}

/*Em ordem: Visitar a subárvore esquerda, exibir o valor atual e visitar a subárvore direita.*/
void emOrdem(Arv* r) {
    if (r != NULL) {
        emOrdem(r->esq);
        printf("%c ", r->info);
        emOrdem(r->dir);
    }
}

/*Pós-ordem: Visitar a subárvore esquerda, depois a direita, e só então exibir o valor atual.*/
void posOrdem(Arv* r) {
    if (r != NULL) {
        posOrdem(r->esq);
        posOrdem(r->dir);
        printf("%c ", r->info);
    }
}

