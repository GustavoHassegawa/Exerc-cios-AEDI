typedef struct avl Avl;

// Raiz apontando para NULL
Avl* Avl_criavazia (void);

Avl* Avl_cria (char c);

// Fun��o recursiva para liberar os n�s a partir da raiz r
void Avl_libera (Avl* r);

// Busca de acordo com a ordena��o da �rvore
Avl* Avl_busca (Avl* r, char c);

// Fun��o de insercao
Avl* Avl_insere (Avl* r, char c);

// Fun��o de remo��o
Avl* Avl_retira (Avl* r, int c);

void Avl_imprime (Avl* r);

// Fun��o para rota��o simples � esquerda na �rvore AVL
Avl* rotacaoEsquerda(Avl* a);

// Fun��o para rota��o simples � direita na �rvore AVL
Avl* rotacaoDireita(Avl* a);

void Avl_imprime_ordem (Avl* r);
