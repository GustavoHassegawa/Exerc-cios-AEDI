#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    struct lista * next;
    float number;
} Lista;

typedef struct fila {
    Lista *begin;
    Lista * end;
} Fila;

Fila* fila_cria(void ) {
    Fila * line = (Fila *)malloc(sizeof(Fila));
    line->begin = NULL;
    line->end = NULL;
    return line;
}

void fila_insere (Fila* f, float v) {
    Lista * newNode = (Lista * )malloc(sizeof(Lista));
    
    newNode->number = v;

    if (f->begin == NULL) {
        f->begin = newNode;
        f->end = newNode;
        newNode->next = NULL;
    } else {
        f->end->next = newNode;
        f->end = newNode;
    }
}

float fila_retira (Fila* f) {
    float firstNumber;
    Lista * temp;

    if (fila_vazia) {
        printf("Lista vazia!");
        exit(1);
    }

    firstNumber = f->begin->number;

    if (f->begin->next != NULL) {
        temp = f->begin->next;
        free(f->begin);
        f->begin = temp;
    } else {
        free(f->begin);
        free(f->end);
    }

    return firstNumber;
}

int fila_vazia (Fila* f) {
    if (f->begin == NULL)
        return 0;
    else 
        return 1;
}

void fila_libera (Fila* f) {
    Lista * currentNode = f->begin;

    while(currentNode != NULL) {
        free(currentNode);
        currentNode = currentNode->next;
    }

    free(f);
}

void combina_filas(Fila * f_res, Fila * f1, Fila * f2) {
    Lista * currentNode1 = f1->begin, * currentNode2 = f2->begin;
    int counter = 0;

    while (currentNode1 != NULL && currentNode2 != NULL) {
        if (currentNode1 != NULL && currentNode2 == NULL) {
            //FIM DA FILA 1 E FILA 2 COM OBJETOS

        } else if (currentNode1 == NULL && currentNode2 != NULL) {
            // FIMA DA FILA 2 E FILA 1 COM OBJETOS 
            
        } else if (counter % 2 != 0) {
            //ADICIONA DA FILA 1

        } else {
            //ADICIONA DA FILA 2

        }
    }
}
