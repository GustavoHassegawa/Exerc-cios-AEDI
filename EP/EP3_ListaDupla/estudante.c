//////////////////////////////////////
// Implementação do TAD Estudante   //
//////////////////////////////////////


#include "estudante.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct estudante{
    char nome[50];
    int idade;
    float coef_rendimento;
};

Estudante* criaEstudante(const char *nome, int idade, float coef_rendimento) {
    Estudante *e = (Estudante*) malloc(sizeof(Estudante));
    if (e == NULL) {
        printf("Sem memoria\n");
        exit(1);
    }
    strcpy(e->nome, nome);
    e->idade = idade;
    e->coef_rendimento = coef_rendimento;
    
    return e;
}

void destroiEstudante(Estudante *e) {
    free(e);
}

char* getNome(Estudante *e) {
    return e->nome;
}

// Funcao para retornar a idade de um estudante
int getIdade(Estudante *e) {
    return e->idade;
}

// Funcao para retornar o CR de um estudante
float getCoeficiente(Estudante *e) {
    return e->coef_rendimento;
}

//-----------------Novas funções-------------------
// Funcao imprime estudante - implementar
void imprimeEstudante(Estudante *e) {
    printf("Nome: %s, idade: %d, CR: %.1f\n", e->nome, e->idade, 
    e->coef_rendimento);
}
