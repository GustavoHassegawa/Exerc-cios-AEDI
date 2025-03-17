#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct produto {
    int codigoId;
    char nome[50];
    int quantidade;
    double preco;
} *Produto;

struct produto* cria (int cod, char* nome, int quant, double preco) {
    Produto prod = malloc(sizeof(Produto));

    prod->codigoId = cod;
    strcpy(prod->nome, nome);
    prod->quantidade = quant;
    prod->preco = preco;

    return prod;
}

int main() {
    int code, quant;
    char nome[50];
    double preco;
    Produto prod;

    printf("Nome:\n");
    fgets(nome, 50, stdin);
    printf("Código:\n");
    scanf("%d", &code);
    printf("Quantidade:\n");
    scanf("%d", &quant);
    printf("Preco:\n");
    scanf("%lf", &preco);

    prod = cria(code, nome, quant, preco);

    printf("%s", prod->nome);
    printf("%d\n", prod->codigoId);
    printf("%d\n", prod->quantidade);
    printf("%.2lf\n", prod->preco);

    free(prod);

    return 0;
}