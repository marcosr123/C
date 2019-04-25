#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int value;
    struct no *prox;
}Lista;

typedef struct p {
    Lista *topo;
    int tam;
}Pilha;

Pilha* criaPilha() {
    Pilha *pilha=(Pilha*)malloc(sizeof(Pilha));
    pilha->topo=NULL;
    pilha->tam=0;
    return pilha;
}

void push(Pilha *pilha, int v) {
    Lista *lista=(Lista*)malloc(sizeof(Lista));
    lista->value=v;

    lista->prox=pilha->topo;
    pilha->topo=lista;
    pilha->tam++;
}

int pop(Pilha *pilha) {
    Lista *elem=pilha->topo;
    int v=elem->value;
    pilha->topo = elem->prox;
    free(elem);
    pilha->tam--;
    return v;
}

int main() {
    Pilha *mypilha=criaPilha();

    int i;
    for (i=0; i<1200; i++) {
        push(mypilha,rand());
    }

    push(mypilha,12);
    push(mypilha,72);


    printf("%d \n", pop(mypilha));

    printf("\ntamanho: %d \n", mypilha->tam);

    printf("%d \n", pop(mypilha));

    printf("\ntamanho: %d \n", mypilha->tam);

    printf("%d \n", pop(mypilha));

    return 0;
}
