typedef struct heap Heap;

Heap* heap_cria (int nmax);

void heap_libera (Heap* h);

int heap_vazia (Heap* h);

void heap_insere (Heap* h, int value);

int heap_retira (Heap* h);

int heap_verifica (Heap* h);

Heap* heap_constroi(int nEntry, int* vector);

void heap_imprime(Heap * h);

void inserir(Heap * prioridades, int valor);

void esvazia_heap(Heap * priori);