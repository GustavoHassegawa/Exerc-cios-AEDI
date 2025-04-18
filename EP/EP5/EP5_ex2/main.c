#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(void) {
    int *vetor, size;
    Heap *pri;

    scanf("%d", &size);
    vetor = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) 
        scanf("%d", &vetor[i]);
    
    pri = heap_constroi(size, vetor);
    
    heap_imprime(pri);

    heap_libera(pri);
    free(vetor);

    return 0;
}