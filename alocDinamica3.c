#include <stdio.h>
#include <stdlib.h>

#define MAX 3
void ler(int *v,int n);
void imprimir(int *v,int n);

void main(void) {
    int *v, n;
    printf("\nTamanho do vetor? ");
    scanf("%d",&n);
    v = malloc( n *sizeof(int) );
    if( v!=NULL ){
        ler(v,n);
        imprimir(v,n);
        free(v);
    } else {
        printf("Memoria Insuficiente!");
    }

    printf("\n-----------------------------------------\n");

    int *p1, *p2, n1=3, n2=6;
    p1 = malloc( n1 *sizeof(int) );
    p2 = malloc( n2 *sizeof(int) );

    ler(p1, n1);
    imprimir(p1, n1);

    ler(p2, n2);
    imprimir(p2, n2);

    *(p2+2)=555;
    imprimir(p2, n2);
}

void ler(int *v,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("\nValor: ");
        scanf("%d",&*(v+i));
    }
}
void imprimir(int *v,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d ",v[i]);
    }

}
