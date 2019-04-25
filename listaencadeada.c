#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int info;
   struct no *prox;
}Lista;

Lista* crialista() {
    return NULL;
}

Lista* insere(Lista *list, int valor) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = list;
    return novo;
}

void imprime (Lista *list) {
    Lista *p;
    for (p = list; p != NULL; p = p->prox) {
        printf("info = %d\n", p->info);
    }
}

int estavazia(Lista *list) {
    return (list == NULL);
}

Lista* busca (Lista *list, int valor) {
    Lista* p;
    for (p=list; p!=NULL; p=p->prox) {
        if (p->info == valor) {
            return p;
        }
    }
    return NULL; /* não achou o elemento */
}

Lista *retira(Lista *lista, int v) {
    Lista *ant = NULL;
    Lista *p = lista;

    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    if (p==NULL) {
        return lista;
    }

    if (ant==NULL) {
            lista = p->prox;
    } else {
        ant->prox = p->prox;
    }
	free(p);
	return lista;
}

Lista* libera(Lista* lista) {
    Lista *p = lista;
    while (p != NULL) {
        p = lista->prox;
        free(lista);
        lista = p;
    }
    return NULL;
}

int contaIte(Lista *lista) {
    int x=0;
    Lista *p = lista;
    while (p != NULL) {
        p = p->prox;
        x++;
    }
    return x;
}

Lista* insereOrdenado(Lista *l, int v) {
    Lista *ant=NULL;
    Lista *p=l;
    while(p!=NULL && p->info<v) {
        ant=p;
        p=p->prox;
    }
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info=v;
    if (ant==NULL) { //quando a lista está vazia, ou seja, o 1º nó é inserido
        novo->prox=l;
        l=novo;
    } else { //para os demais nós
        novo->prox=ant->prox;
        ant->prox=novo;
    }
    return l;
}

int contaR(Lista *l) {
    if (l==NULL) return 0;
    return 1+contaR(l->prox);
}

int distancia (Lista *l, int v) {
    Lista *p = busca(l,v);
    if (p!=NULL) {
        return contaR(p)-1;
    }
    return -1;
}

int main() {
    Lista *minhalista;

    minhalista = crialista();
    minhalista = insere(minhalista, 12);
    minhalista = insere(minhalista, 45);
    minhalista = insere(minhalista, 10);
    minhalista = insere(minhalista, 20);

    imprime(minhalista);

    Lista *r  = busca(minhalista, 45);

    if (r!=NULL) {
        printf("NO com o valor %d encontrado.", r->info);
    }

    minhalista = retira(minhalista,45);
    minhalista = retira(minhalista,12);

    printf("\n\n");
    imprime(minhalista);

    minhalista = libera(minhalista);
    printf("\n\n todos os nos foram retirados!");

    imprime(minhalista);

    minhalista = insere(minhalista, 600);
    minhalista = insere(minhalista, 510);
    minhalista = insere(minhalista, 420);
    minhalista = insere(minhalista, 100);
    minhalista = insere(minhalista, 310);
    minhalista = insere(minhalista, 220);

    printf("\n\n");
    imprime(minhalista);

    printf("\n\ntam1: %d, tam2: %d ", contaIte(minhalista), contaR(minhalista));

    printf("\n\naltura1: %d", distancia(minhalista,600));
    printf("\n\naltura2: %d", distancia(minhalista,310));
    printf("\n\naltura3: %d", distancia(minhalista,3101));
    printf("\n\naltura4: %d", distancia(minhalista,420));

    Lista *myListaOrd = crialista();
    myListaOrd = insereOrdenado(myListaOrd, 8);
    myListaOrd = insereOrdenado(myListaOrd, 10);
    myListaOrd = insereOrdenado(myListaOrd, 9);
    myListaOrd = insereOrdenado(myListaOrd, 11);

    printf("\n\nInsere elemento em ordem:\n");
    imprime(myListaOrd);

    return 0;
}

