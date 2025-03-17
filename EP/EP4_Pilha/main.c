#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000 

// Retorna uma pilha com 
Pilha * fill_parenthesis (char *s) {
    Pilha * pile = pilha_cria();
    int expressionSize = strlen(s);

    for (int i = 0; i < expressionSize; i++) {
        if (s[i] == '(')
            pilha_push(pile, 1.0);
        else if (s[i] == ')')
            pilha_push(pile, -1.0);

    }

    return pile;
}

/*Protótipo da função */
int parenthesis_balance (char* s) {
    Pilha * pile = fill_parenthesis(s);
    float balance = 0;

    while (!pilha_vazia(pile)) {
        balance += pilha_pop(pile);

        if (balance > 0) {
            free(pile);
            return 0;
        }
    }

    free(pile);

    if (balance == 0)
        return 1;
    else 
        return 0;
}  

int main() {
    int numberOfExpressions;
    char expression[LENGTH];

    scanf("%d",&numberOfExpressions);
    getchar();

    for (int i = 0; i < numberOfExpressions; i++) {
        fgets(expression, LENGTH - 1, stdin);
        //printf("%s", expression);

        if (parenthesis_balance(expression) == 1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}