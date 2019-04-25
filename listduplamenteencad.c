#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int info;
   struct no *ant;   
   struct no *prox;
}Lista;

Lista* crialista() {
    return NULL;
}

Lista* insere(Lista *list, int valor) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = list;
	novo->ant = NULL;
	/* verifica se lista não estava vazia */
	if (list != NULL)
		list->ant = novo;	
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

Lista* retira (Lista* list, int val) {
	Lista* p = busca(list,val);
	if (p == NULL) {
		return list;/* não achou o elemento: retorna lista inalterada */
	}
	if (list == p) { /* testa se é o primeiro elemento */
		list = p->prox;
	}else{
		p->ant->prox = p->prox;
	}
	if (p->prox != NULL){ /* testa se não é o último elemento */
		p->prox->ant = p->ant;
	}
	free(p);
	return list;
}

Lista *retiraT(Lista *lista, int v) {
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

int main() {
    Lista *minhalista;

    minhalista = crialista();
    minhalista = insere(minhalista, 12);
    minhalista = insere(minhalista, 45);
    minhalista = insere(minhalista, 10);
    minhalista = insere(minhalista, 20);

    imprime(minhalista);

    minhalista = retira(minhalista,45);
    minhalista = retira(minhalista,10);

    printf("\n\n");
    imprime(minhalista);

    return 0;
}

