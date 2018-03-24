#include <stdio.h>
#include <stdlib.h>

#define MAX 3

void main(void) {
    typedef struct funcionario{
        char nome[21];
        float salario;
    }Func;

    Func *f[MAX];
    int i;
   for(i=0; i<MAX; i++) {
        f[i] = malloc(sizeof(Func));
        printf("\nNome: ");
        scanf("%s",f[i]->nome);
        scanf("%f", &f[i]->salario);
    }

   for(i=0; i<MAX; i++) {
        printf("\nNome: %s ", f[i]->nome);
        printf("\nSalario: %f ", f[i]->salario);
        printf("\n");
    }
}
