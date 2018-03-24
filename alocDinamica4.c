#include <stdio.h>
#include <stdlib.h>

#define MAX 3

void main(void) {
     int *v[3], linhas=3, n=2;
    int j;
    for (j=0; j < linhas; j++) {
        *(v+j) = malloc( n * sizeof(int) );
        int i;
        for(i=0; i<n; i++) {
            printf("Valor: ");
            //scanf("%d",&v[j][i]);
            scanf("%d", (*(v+j))+i );
        }
        printf("\n\n");
    }
    for (j=0; j < 3; j++) {
        int i;
        for(i=0; i<n; i++) {
          printf("%d ",v[j][i]);
        }
        printf("\n\n");
    }
}

