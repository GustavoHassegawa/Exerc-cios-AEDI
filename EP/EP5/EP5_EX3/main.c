#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(void) {
    int valor;
    Heap *pri = heap_cria(10);

    while (scanf("%d", &valor) == 1) {
        inserir(pri, valor);
    }
    
    esvazia_heap(pri);
    heap_libera(pri);

    return 0;
}