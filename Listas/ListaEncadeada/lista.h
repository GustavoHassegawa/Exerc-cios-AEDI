#ifndef LISTA_H

#define LISTA_H

typedef struct lista Lista;

//Incluir um elemento ao final da lista. 
Lista* insere_ultimo (Lista *L);

//Concatenar duas listas.
Lista* concatena (Lista *L1, Lista *L2);

/* Inverter uma lista de modo que o último elemento se torne o primeiro e assim 
 * por diante. */
Lista* inverte (Lista *L);

/* Eliminar o elemento de posição n de uma lista. Considere que o primeiro 
 * elemento da lista está na posição 0 e que a lista deve permanecer inalterada 
 * se a n-ésima posição não existir. */ 
Lista* retira_n (Lista *L, int n); 

//Combinar duas listas ordenadas em uma lista resultante também  ordenada. 
Lista*concatena_ord (Lista *L1, Lista *L2);

//Criar uma lista resultante da união dos elementos de duas listas. 
Lista* uniao (Lista *L1, Lista *L2);

//Criar uma lista resultante da interseção dos elementos de duas listas. 
Lista* intersecao (Lista *L1, Lista *L2);

/* Considerando listas encadeadas de valores inteiros, implemente uma função que 
 * retorne o número de nós da lista que possuem o campo info com valores maiores
 * do que x. */
int maiores (Lista* l, int x);


#endif