#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct avl {
    char info;
    struct avl* esq;
    struct avl* dir;
    int altura;
};

// Raiz apontando para NULL
Avl* Avl_criavazia (void) {
    return NULL;
}

Avl* Avl_cria (char c) {
    printf("Insercao do no: %c\n", c); 

    Avl * tree = (Avl *) malloc(sizeof(Avl));
    
    tree->info = c;
    tree->esq = NULL;
    tree->dir = NULL;
    tree->altura = 1;
    
    return tree;
}

// Fun��o recursiva para liberar os n�s a partir da raiz r
void Avl_libera (Avl* r) {
    if (r != NULL) {
        Avl_libera(r->esq);
        Avl_libera(r->dir);
        free(r);
    }
}

// Busca de acordo com a ordena��o da �rvore
Avl* Avl_busca (Avl* r, char c) {
    if (r == NULL)
        return NULL;
    else if (c < r->info)
        return Avl_busca(r->esq, c);
    else if (c > r->info)
        return Avl_busca(r->dir, c);
    else
        return r;
}

// Fun��o para retornar o maior valor entre dois inteiros
static int maximo (int a, int b) {
    return (a > b) ? a : b;
}

// Fun��o para obter a altura de um n� Avl
static int altura (Avl* a) {
    if (a == NULL) {
        return 0;
    }
    return a->altura;
}

// Fun��o para atualizar a altura de um n� Avl
static void atualizaAltura(Avl* a) {
    if (a != NULL) {
        a->altura = 1 + maximo(altura(a->esq), altura(a->dir));
    }
}

//Retorna o valor balanceamento de um determinado no
int fatorBalanceamento(Avl* tree) {
    if (tree == NULL) 
        return 0;
    
    return altura(tree->esq) - altura(tree->dir);
}

// Fun��o para rota��o simples � esquerda na �rvore AVL
Avl* rotacaoEsquerda(Avl* a) {
    printf("Rotacao a esquerda em %c\n", a->info);

    if (a == NULL || a->dir == NULL)
        return a;

    Avl* pivot = a->dir;
    a->dir = pivot->esq;
    pivot->esq = a;

    atualizaAltura(a);
    atualizaAltura(pivot);

    return pivot;
}

// Fun��o para rota��o simples � direita na �rvore AVL
Avl* rotacaoDireita(Avl* a) {
    printf("Rotacao a direita em %c\n", a->info);

    if (a == NULL || a->esq == NULL)
        return a;

    Avl* pivot = a->esq;
    a->esq = pivot->dir;
    pivot->dir = a;

    atualizaAltura(a);
    atualizaAltura(pivot);

    return pivot;
}

Avl* rotacaoEsquerdaDireita(Avl* a) {
    if (a == NULL || a->esq == NULL)
        return a; 
    
    a->esq = rotacaoEsquerda(a->esq);
    return rotacaoDireita(a);
}

Avl* rotacaoDireitaEsquerda(Avl* a) {
    if (a == NULL || a->dir == NULL)
        return a;
    
    a->dir = rotacaoDireita(a->dir);
    return rotacaoEsquerda(a);
}

Avl* reequilibrar(Avl * a) {
    if (a == NULL) 
        return NULL;
    
    atualizaAltura(a);

    int balance_factor = fatorBalanceamento(a);
    
    if (balance_factor < -1) {
        if (fatorBalanceamento(a->dir) > 0) {
            printf("Rotacao dupla a direita-esquerda\n");
            return rotacaoDireitaEsquerda(a);
        }
        printf("Rotacao simples a esquerda\n");
        return rotacaoEsquerda(a);
    }

    if (balance_factor > 1) {
        if (fatorBalanceamento(a->esq) < 0){
            printf("Rotacao dupla a esquerda-direita\n");
            return rotacaoEsquerdaDireita(a);
        }
        printf("Rotacao simples a direita\n");
        return rotacaoDireita(a);
    }

    return a;
}

// Fun��o de insercao
Avl* Avl_insere (Avl* r, char c) {
    if (r == NULL)
        return Avl_cria(c);

    if (c < r->info) {
        r->esq = Avl_insere(r->esq, c);
    } else if (c > r->info) {
        r->dir = Avl_insere(r->dir, c);
    }

    return reequilibrar(r);
}

// Fun��o de remo��o
Avl* Avl_retira (Avl* r, int c) {
    if (r == NULL)
        return NULL;
    else if (c < r->info)
        r->esq = Avl_retira(r->esq, c);
    else if (c > r->info)
        r->dir = Avl_retira(r->dir, c);
    else {
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        } else if (r->esq == NULL) {
            Avl* temp = r;
            r = r->dir;
            free(temp);
        } else if (r->dir == NULL) {
            Avl* temp = r;
            r = r->esq;
            free(temp);
        } else {
            Avl* temp = r->esq;
            while (temp->dir != NULL) {
                temp = temp->dir;
            } 
            r->info = temp->info;
            temp->info = c;
            r->esq = Avl_retira(r->esq, c);
        }
        printf("Remocao do no: %c\n", c);
    }
    r = reequilibrar(r);
    return r;
}

void Avl_imprime (Avl* r) {
    printf("<");
    if (r != NULL) {
        printf("%c", r->info);
        Avl_imprime(r->esq);
        Avl_imprime(r->dir);
    }
    printf(">");
}

void Avl_imprime_ordem (Avl* r) {
    if (r != NULL) {
        Avl_imprime_ordem(r->esq);
        printf(" %c", r->info);
        Avl_imprime_ordem(r->dir);
    }
}


