typedef struct heap Heap;

Heap* heap_cria (int nmax);

void heap_libera (Heap* h);

int heap_vazia (Heap* h);

void heap_insere (Heap* h, int value);

float heap_retira (Heap* h);

int heap_verifica (Heap* h);

Heap* heap_constroi(int nEntry, int* vector);

void heap_imprime(Heap * h);