#include<stdio.h>
#include<stdlib.h>
#include "Avl.h"

struct avl {
    char info;
    struct avl* esq;
    struct avl* dir;
    int altura;
};

// Fun��o para criar um novo n� Avl
Avl* Avl_cria (char c) {
    Avl* p = (Avl*)malloc(sizeof(Avl));
    if (p == NULL) {
        printf("Erro de aloca��o de mem�ria.\n");
        return NULL;
    }
    p->info = c;
    p->esq = NULL;
    p->dir = NULL;
    p->altura = 1; // Um novo n� come�a com altura 1
    return p;
}


// Raiz apontando para NULL
Avl* Avl_criavazia (void){

    return NULL;
}


// ordem crescente, sim�trica
void Avl_imprime (Avl* r){
    printf("<"); //mostra informa��o /
    if (r != NULL ){
        printf("%c", r-> info); //mostra informa��o /
        Avl_imprime_sim(r-> esq); // imprime sae /
        Avl_imprime_sim(r-> dir); // imprime sad /

    }
    printf(">"); //mostra informa��o /
}

// Fun��o recursiva para liberar os n�s a partir da raiz r
void Avl_libera (Avl* r){
    if (r != NULL) {
        Avl_libera(r-> esq); //libera das folhas
        Avl_libera(r-> dir); // at� chegar a
        free(r);         //raiz r
    }
}


// Busca de acordo com a ordena��o da �rvore - O(log n) arvore balanceada
Avl* Avl_busca (Avl* r, char c){
    if (r == NULL) return NULL; // �rvore vazia, n�o encontrou
    else if (c == r-> info) return r;
    else if (c < r->info) return Avl_busca(r->esq, c);
    else return Avl_busca(r->dir,c);
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

// Fun��o para calcular o fator de balanceamento de um n� Avl
int fatorBalanceamento(Avl* a) {
    if (a == NULL) {
        return 0;
    }

    return altura(a->esq) - altura(a->dir);
}

// Fun��o para rota��o simples � esquerda na �rvore Avl
Avl* rotacaoEsquerda(Avl* a) {
    if (a == NULL || a->dir == NULL) {
        return a; // Nenhuma rota��o necess�ria
    }
    Avl* pivo = a->dir;
    a->dir = pivo->esq;
    pivo->esq = a;
    // Atualiza alturas
    atualizaAltura(a);
    atualizaAltura(pivo);
    return pivo; // Novo n� raiz ap�s a rota��o
}

// Fun��o para rota��o simples � direita na �rvore Avl
Avl* rotacaoDireita(Avl* a) {
    if (a == NULL || a->esq == NULL) {
        return a; // Nenhuma rota��o necess�ria
    }

    Avl* pivo = a->esq;
    a->esq = pivo->dir;
    pivo->dir = a;

    // Atualiza alturas
    atualizaAltura(a);
    atualizaAltura(pivo);

    return pivo; // Novo n� raiz ap�s a rota��o
}

// Fun��o para rota��o dupla � direita (rota��o esquerda-direita)
Avl* rotacaoEsquerdaDireita(Avl* a) {
    if (a == NULL || a->esq == NULL) {
        return a; // Nenhuma rota��o necess�ria
    }
    a->esq = rotacaoEsquerda(a->esq);
    return rotacaoDireita(a);
}

// Fun��o para rota��o dupla � esquerda (rota��o direita-esquerda)
Avl* rotacaoDireitaEsquerda(Avl* a) {
    if (a == NULL || a->dir == NULL) {
        return a; // Nenhuma rota��o necess�ria
    }
    a->dir = rotacaoDireita(a->dir);
    return rotacaoEsquerda(a);
}

// Fun��o para rebalancear um n� AVL ap�s inser��o ou remo��o
Avl* reequilibrar(Avl* a) {
    if (a == NULL) {
        return NULL;
    }
    // Atualiza a altura do n� atual
    atualizaAltura(a);
    // Verifica o fator de balanceamento
    int fb = fatorBalanceamento(a);
    // Caso 1: Desbalanceamento para a direita (Rota��o Esquerda)
    if (fb < -1) {
        if (fatorBalanceamento(a->dir) > 0) {
            a->dir = rotacaoDireita(a->dir);
        }
        return rotacaoEsquerda(a);
    }
    // Caso 2: Desbalanceamento para a esquerda (Rota��o Direita)
    if (fb > 1) {
        if (fatorBalanceamento(a->esq) < 0) {
            a->esq = rotacaoEsquerda(a->esq);
        }
        return rotacaoDireita(a);
    }
    return a; // Nenhum rebalanceamento necess�rio
}


// Fun��o de insercao
Avl* Avl_insere (Avl* a, char info){
// Caso base: se o n� for NULL, cria um novo n� com a chave
    if (a == NULL) {
        return Avl_cria(info);
    }

    if (info < a->info) {
        a->esq = Avl_insere(a->esq, info);
    } else if (info > a->info) {
        a->dir = Avl_insere(a->dir, info);
    }

    // Rebalanceia a �rvore AVL ap�s a inser��o
    return reequilibrar(a);
}

// Fun��o de remo��o
Avl* Avl_retira (Avl* r, int c){

    // �rvore vazia
    if (r == NULL)
        return NULL;

    else if (r-> info > c)
        r-> esq = Avl_retira(r->esq , c);
    else if (r-> info < c)
        r-> dir = Avl_retira(r->dir, c);
    else {//achou o elemento

        // Caso 1: basta liberar a mem�ria alocada pelo elemento e ter como valor de retorno a raiz atualizada, que passa a ser NULL.
        if (r-> esq == NULL && r-> dir == NULL) {
            free (r);
            r = NULL;
        }
        // Caso 2: s� um filho a direita
        else if (r-> esq == NULL) {
            Avl* t = r;
            r = r-> dir;
            free (t);
        }
        // s� tem um filho a esquerda
        else if (r-> dir == NULL) {
            Avl* t = r;
            r = r-> esq;
            free (t);
        }
        // Caso 3:
        else {
            Avl* f = r-> esq;
            while (f-> dir != NULL) {
                f = f-> dir;
            }
            r-> info = f-> info;
            f-> info = c;
            r-> esq = Avl_retira(r->esq ,c);
        }
       }

        return r;
}
