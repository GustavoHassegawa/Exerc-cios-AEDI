#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main(void) {
    Arv * tree1= criavazia();
    Arv * tree2= criavazia();
    Arv * tree3= criavazia();
    
    tree1 = insere(tree1, 'D');
    tree1 = insere(tree1, 'B');
    tree1 = insere(tree1, 'F');
    tree1 = insere(tree1, 'A');
    tree1 = insere(tree1, 'C');
    tree1 = insere(tree1, 'E');
    tree1 = insere(tree1, 'G');
    
    tree2 = insere(tree2, 'C');
    tree2 = insere(tree2, 'B');
    tree2 = insere(tree2, 'D');
    tree2 = insere(tree2, 'A');
    tree2 = insere(tree2, 'E');
    
    tree3 = insere(tree3, 'E');
    tree3 = insere(tree3, 'C');
    tree3 = insere(tree3, 'H');
    tree3 = insere(tree3, 'B');
    tree3 = insere(tree3, 'D');
    tree3 = insere(tree3, 'F');
    tree3 = insere(tree3, 'I');
    tree3 = insere(tree3, 'A');
    tree3 = insere(tree3, 'G');
    
    printf("Arvore 1\n");
    printf("Pre-ordem\n");
    preOrdem(tree1);
    printf("\nEm-ordem\n");
    emOrdem(tree1);
    printf("\nPos-ordem\n");
    posOrdem(tree1);
    
    printf("Arvore 2\n");
    printf("Pre-ordem\n");
    preOrdem(tree2);
    printf("\nEm-ordem\n");
    emOrdem(tree2);
    printf("\nPos-ordem\n");
    posOrdem(tree2);
    
    printf("Arvore 3\n");
    printf("Pre-ordem\n");
    preOrdem(tree3);
    printf("\nEm-ordem\n");
    emOrdem(tree3);
    printf("\nPos-ordem\n");
    posOrdem(tree3);
    
    libera(tree1);
    libera(tree2);
    libera(tree3);
    
    return 0;
}
