#include <stdio.h>
#include "vetor.h"

int main() {
    double x1, y1, z1, x2, y2, z2, prodInt;
    Vetor v1, v2, prodVet, sum;

    scanf("%lf", & x1);
    scanf("%lf", & y1);
    scanf("%lf", & z1);
    scanf("%lf", & x2);
    scanf("%lf", & y2);
    scanf("%lf", & z2);
    
    v1 = cria(x1, y1, z1);
    v2 = cria(x2, y2, z2);

    prodInt = prodint(v1, v2);
    prodVet = prodvet(v1, v2);
    sum = soma(v1, v2);

    printf("%lf\n", prodInt);

    printf("\n%lf\n", prodVet->x);
    printf("%lf\n", prodVet->y);
    printf("%lf\n", prodVet->z);
    
    printf("\n%lf\n", sum->x);
    printf("%lf\n", sum->y);
    printf("%lf\n", sum->z);

    libera(v1);
    libera(v2);
    libera(prodVet);
    libera(sum);

    return 0;
}