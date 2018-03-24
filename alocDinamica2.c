#include <stdio.h>
#include <stdlib.h>

#define MAX 3

void main(void) {
    int *p2;
    int i, n=5;
    p2 = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++)  {
          *(p2+i) = i;
    }
    for(i=n-1; i>=0; i--) {
        printf("%d ",p2[i]);
    }

    int *v, n;
    printf("\nTamanho do vetor? ");
    scanf("%d",&n);
    v = malloc( n *sizeof(int) );
    if( v!=NULL ){
        int i;
        for(i=0; i<n; i++) {
            printf("\nValor: ");
            scanf("%d",&v[i]);
        }

        for(i=n-1; i>=0; i--) {
            printf("%d ",v[i]);
        }
    }

 }
