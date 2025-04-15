#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main()
{
    Avl* a = Avl_criavazia();
    char nos[10] = {'e', 's', 't', 'r', 'u', 't', 'u', 'r', 'a', 's'}; //10 nós
    for (int i=0;i < 10;i++)
        a = Avl_insere(a, nos[i]);
    Avl_imprime_sim (a);
    printf("\n");
    Avl_imprime_sim (a);
    Avl_libera(a);
    return 0;
}

