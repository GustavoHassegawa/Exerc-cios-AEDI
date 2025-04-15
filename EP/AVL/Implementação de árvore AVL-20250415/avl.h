typedef struct avl Avl;

// Raiz apontando para NULL
Avl* Avl_criavazia (void);

Avl* Avl_cria (char c);

// Função recursiva para liberar os nós a partir da raiz r
void Avl_libera (Avl* r);

// Busca de acordo com a ordenação da árvore
Avl* Avl_busca (Avl* r, char c);

// Função de insercao
Avl* Avl_insere (Avl* r, char c);

// Função de remoção
Avl* Avl_retira (Avl* r, int c);

void Avl_imprime (Avl* r);

// Função para rotação simples à esquerda na árvore AVL
Avl* rotacaoEsquerda(Avl* a);

// Função para rotação simples à direita na árvore AVL
Avl* rotacaoDireita(Avl* a);

