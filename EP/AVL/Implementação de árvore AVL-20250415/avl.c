#include<stdio.h>
#include<stdlib.h>
#include "Avl.h"

struct avl {
    char info;
    struct avl* esq;
    struct avl* dir;
    int altura;
};

// Função para criar um novo nó Avl
Avl* Avl_cria (char c) {
    Avl* p = (Avl*)malloc(sizeof(Avl));
    if (p == NULL) {
        printf("Erro de alocação de memória.\n");
        return NULL;
    }
    p->info = c;
    p->esq = NULL;
    p->dir = NULL;
    p->altura = 1; // Um novo nó começa com altura 1
    return p;
}


// Raiz apontando para NULL
Avl* Avl_criavazia (void){

    return NULL;
}


// ordem crescente, simétrica
void Avl_imprime (Avl* r){
    printf("<"); //mostra informação /
    if (r != NULL ){
        printf("%c", r-> info); //mostra informação /
        Avl_imprime_sim(r-> esq); // imprime sae /
        Avl_imprime_sim(r-> dir); // imprime sad /

    }
    printf(">"); //mostra informação /
}

// Função recursiva para liberar os nós a partir da raiz r
void Avl_libera (Avl* r){
    if (r != NULL) {
        Avl_libera(r-> esq); //libera das folhas
        Avl_libera(r-> dir); // até chegar a
        free(r);         //raiz r
    }
}


// Busca de acordo com a ordenação da árvore - O(log n) arvore balanceada
Avl* Avl_busca (Avl* r, char c){
    if (r == NULL) return NULL; // árvore vazia, não encontrou
    else if (c == r-> info) return r;
    else if (c < r->info) return Avl_busca(r->esq, c);
    else return Avl_busca(r->dir,c);
}

// Função para retornar o maior valor entre dois inteiros
static int maximo (int a, int b) {
    return (a > b) ? a : b;
}

// Função para obter a altura de um nó Avl
static int altura (Avl* a) {
    if (a == NULL) {
        return 0;
    }
    return a->altura;
}

// Função para atualizar a altura de um nó Avl
static void atualizaAltura(Avl* a) {
    if (a != NULL) {
        a->altura = 1 + maximo(altura(a->esq), altura(a->dir));
    }
}

// Função para calcular o fator de balanceamento de um nó Avl
int fatorBalanceamento(Avl* a) {
    if (a == NULL) {
        return 0;
    }

    return altura(a->esq) - altura(a->dir);
}

// Função para rotação simples à esquerda na árvore Avl
Avl* rotacaoEsquerda(Avl* a) {
    if (a == NULL || a->dir == NULL) {
        return a; // Nenhuma rotação necessária
    }
    Avl* pivo = a->dir;
    a->dir = pivo->esq;
    pivo->esq = a;
    // Atualiza alturas
    atualizaAltura(a);
    atualizaAltura(pivo);
    return pivo; // Novo nó raiz após a rotação
}

// Função para rotação simples à direita na árvore Avl
Avl* rotacaoDireita(Avl* a) {
    if (a == NULL || a->esq == NULL) {
        return a; // Nenhuma rotação necessária
    }

    Avl* pivo = a->esq;
    a->esq = pivo->dir;
    pivo->dir = a;

    // Atualiza alturas
    atualizaAltura(a);
    atualizaAltura(pivo);

    return pivo; // Novo nó raiz após a rotação
}

// Função para rotação dupla à direita (rotação esquerda-direita)
Avl* rotacaoEsquerdaDireita(Avl* a) {
    if (a == NULL || a->esq == NULL) {
        return a; // Nenhuma rotação necessária
    }
    a->esq = rotacaoEsquerda(a->esq);
    return rotacaoDireita(a);
}

// Função para rotação dupla à esquerda (rotação direita-esquerda)
Avl* rotacaoDireitaEsquerda(Avl* a) {
    if (a == NULL || a->dir == NULL) {
        return a; // Nenhuma rotação necessária
    }
    a->dir = rotacaoDireita(a->dir);
    return rotacaoEsquerda(a);
}

// Função para rebalancear um nó AVL após inserção ou remoção
Avl* reequilibrar(Avl* a) {
    if (a == NULL) {
        return NULL;
    }
    // Atualiza a altura do nó atual
    atualizaAltura(a);
    // Verifica o fator de balanceamento
    int fb = fatorBalanceamento(a);
    // Caso 1: Desbalanceamento para a direita (Rotação Esquerda)
    if (fb < -1) {
        if (fatorBalanceamento(a->dir) > 0) {
            a->dir = rotacaoDireita(a->dir);
        }
        return rotacaoEsquerda(a);
    }
    // Caso 2: Desbalanceamento para a esquerda (Rotação Direita)
    if (fb > 1) {
        if (fatorBalanceamento(a->esq) < 0) {
            a->esq = rotacaoEsquerda(a->esq);
        }
        return rotacaoDireita(a);
    }
    return a; // Nenhum rebalanceamento necessário
}


// Função de insercao
Avl* Avl_insere (Avl* a, char info){
// Caso base: se o nó for NULL, cria um novo nó com a chave
    if (a == NULL) {
        return Avl_cria(info);
    }

    if (info < a->info) {
        a->esq = Avl_insere(a->esq, info);
    } else if (info > a->info) {
        a->dir = Avl_insere(a->dir, info);
    }

    // Rebalanceia a árvore AVL após a inserção
    return reequilibrar(a);
}

// Função de remoção
Avl* Avl_retira (Avl* r, int c){

    // árvore vazia
    if (r == NULL)
        return NULL;

    else if (r-> info > c)
        r-> esq = Avl_retira(r->esq , c);
    else if (r-> info < c)
        r-> dir = Avl_retira(r->dir, c);
    else {//achou o elemento

        // Caso 1: basta liberar a memória alocada pelo elemento e ter como valor de retorno a raiz atualizada, que passa a ser NULL.
        if (r-> esq == NULL && r-> dir == NULL) {
            free (r);
            r = NULL;
        }
        // Caso 2: só um filho a direita
        else if (r-> esq == NULL) {
            Avl* t = r;
            r = r-> dir;
            free (t);
        }
        // só tem um filho a esquerda
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
