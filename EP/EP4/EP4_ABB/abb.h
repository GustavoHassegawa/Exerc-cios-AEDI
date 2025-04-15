typedef struct arv Arv;

// Raiz apontando para NULL
Arv* criavazia (void);

// Função recursiva para liberar os nós a partir da raiz r
void libera (Arv* r);

// Busca de acordo com a ordenação da árvore
Arv* busca (Arv* r, int v);

// Função de inserção
Arv* insere (Arv* r, int v);

// Função de remoção
Arv* retira (Arv* r, int c);

/*Pré-ordem: Exibir o valor atual, depois visitar a subárvore esquerda e a 
 *subárvore direita.*/
void preOrdem(Arv* r);

/*Em ordem: Visitar a subárvore esquerda, exibir o valor atual e visitar a 
 *subárvore direita.*/
void emOrdem(Arv* r);

/*Pós-ordem: Visitar a subárvore esquerda, depois a direita, e só então exibir 
 *o valor atual.*/
void posOrdem(Arv* r);