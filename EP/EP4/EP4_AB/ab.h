typedef struct arv Arv;

// Raiz apontando para NULL
Arv* criavazia (void);

/*Função para criar um novo nó da árvore, recebendo como parâmetros a informação
 *e as duas subárvores (que podem ser vazias, isto é, NULL)*/
Arv* cria (int v, Arv *esq, Arv *dir);

//Função recursiva para liberar os nós a partir da raiz r
void libera (Arv* r);

/* A altura de uma árvore é equivalente ao comprimento do caminho mais longo da 
 *raiz até uma das folhas. Considerando que: a altura de uma árvore com um único 
 *nó raiz é 1 e a altura de uma árvore vazia é 0, escreva uma função que retorne 
 *a altura de uma árvore binária. */
int altura_arv(Arv* a);

/* O custo de um caminho em uma árvore é a soma das chaves dos nós participantes
 * nesse caminho. Considere uma árvore binária de chaves inteiras. Escreva uma 
 * função que retorne o custo do caminho de maior valor da raiz para um nó folha
 * . */
int custo (Arv* a);