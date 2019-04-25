#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int value;
    struct no *prox;
}Lista;

typedef struct f {
    Lista *inicio;
    Lista *fim;
    int tam;
}Fila;

Fila* criaFila() {
    Fila *f=(Fila*)malloc(sizeof(Fila));
    f->inicio=NULL;
    f->fim=NULL;
    f->tam=0;
    return f;
}

void insere(Fila *f, int v) {
    Lista *novo=(Lista*)malloc(sizeof(Lista));
    novo->value=v;
    novo->prox=NULL;
    if (f->fim!=NULL) {
        f->fim->prox=novo;
    } else {
        f->inicio=novo;
    }
    f->fim=novo;
    f->tam++;
}
int retira(Fila *f) {
    Lista *elem=f->inicio;
    int v=elem->value;
    f->inicio = elem->prox;
    if (f->inicio == NULL) /* verifica se fila ficou vazia */
		f->fim = NULL;
    f->tam--;
    free(elem);
    return v;
}

int main() {
    Fila *myfila=criaFila();

    int i;
    for (i=0; i<600; i++) {
        insere(myfila,rand());
    }

    printf("%d \n", retira(myfila));
    printf("\ntamanho: %d \n", myfila->tam);
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("%d \n", retira(myfila));
    printf("\ntamanho: %d \n", myfila->tam);

    return 0;
}
