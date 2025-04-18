#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

#define pai(i) (((i)-1)/2)
#define esq(i) (2*(i)+1)
#define dir(i) (2*(i)+2)

struct heap {
    int n;      // n�mero de elementos armazenados no heap
    int nmax;   // n�mero m�ximo de elementos no heap
    int * v;  // vetor de prioridades

};

Heap* heap_cria (int nmax){

    Heap* h = (Heap *) malloc( sizeof(Heap));
    h->n = 0;
    h-> nmax = nmax;
    h->v = (int *) malloc(h-> nmax*sizeof (int));
    return h;
}

void heap_libera (Heap* h){

    free(h->v);
    free(h);
}

int heap_vazia (Heap* h){

    return (h->n==0);

}

static void troca (Heap* h, int i, int j){

    int tmp = h->v[i]; h->v[i] = h->v[j];
    h->v[j] = tmp;
}

static void sobe (Heap* h, int i) {
    //a partir do n� i
    while (i > 0) {
        int p = pai(i); //p � a raiz de i
        if (h->v[p] > h->v[i]) break ; //se a raiz � maior que i est� em ordem, nada a fazer
        troca(h,p,i); //sen�o troca
        i = p; // e verifica n�vel acima o n�vel
    }
}

void heap_insere (Heap* h, int value){
    h->v[h->n++] = value;
    sobe(h,h->n-1);

}

static void desce (Heap* h, int i)
{
    // pai � o i
    int c = esq(i); //c � o filho esquerdo
    while (c < h->n) {
        int c2 = dir(i);    //c2 � o filho direito
        if (c2 < h->n && h->v[c2] > h->v[c])
            c = c2; //escolhe o maior e compara com o pai
        if (h->v[c] < h->v[i])
            break ; //se o pai � maior que o filho, mant�m

        troca(h,i,c);   //sen�o troca os valores
        i = c;
        c = esq(i);
    }
}


float heap_retira (Heap* h) {

    float r = h->v[0];
    h->v[0] = h->v[--h->n];
    desce(h,0);
    return r;
}


Heap* heap_constroi(int nEntry, int* vector) {
    int indexVector = 0;
    Heap* priorities = heap_cria(nEntry);

    priorities->n = nEntry;

    for (int i = nEntry/2; i < nEntry; i++) {
        priorities->v[i] = vector[indexVector++];
    }

    for (int i = nEntry/2 - 1; i >= 0; i--) {
        priorities->v[i] = vector[indexVector++];
        desce(priorities, i);
    }

    return priorities;
}

void heap_imprime(Heap * h) {
    printf("[");
    for (int i = 0; i < h->n; i++) {
        printf("%d", h->v[i]);
        if (i != h->n - 1) 
            printf(", ");
    }
    printf("]\n");
}
