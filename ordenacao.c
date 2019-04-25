#include <stdio.h>
#include <stdlib.h>

void inserir(int v[], int n);
void imprimir(int v[], int n);
void bolhas(int v[], int n);
void selecao(int v[], int n);

int main() {
    int n=5; //capacidade do vetor
    int v[n];
    inserir(v,n);
    imprimir(v,n);

    bolhas(v,n);
    imprimir(v,n);

    inserir(v,n);
    imprimir(v,n);

    selecao(v,n);
    imprimir(v,n);

    return 0;
}

void inserir(int v[], int n) {
    int i;
    printf("\n");
    for(i=0; i<n; i++) {
        printf("Digite o %d. valor: ", (i+1));
        scanf("%d",&v[i]);
    }
    printf("\n");
}


void imprimir(int v[], int n) {
    int i;
    printf("\n");
    for(i=0; i<n; i++) {
        printf("%d, ", v[i]);
    }
    printf("\n");
}


void bolhas(int v[], int n) { //Ordenação por trocas
    int i, j;
    for(i=1; i<n; i++) {
        for(j=0; j<n-i; j++) {
            if( v[j]>v[j+1] ) {
                int x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
            }
        }
    }
}

int selmin(int v[], int i, int n) {//Selecionando um item mínimo
    int j, k=i;
    for(j=i+1; j<n; j++) {
        if( v[k]>v[j] ) {
            k=j;
        }
    }
    return k;
}
void selecao(int v[], int n) { //Ordenação por seleção
    int i, k, x;
    for(i=0; i<n-1; i++) {
        k = selmin(v,i,n);
        x = v[i];
        v[i] = v[k];
        v[k] = x;
    }
}

