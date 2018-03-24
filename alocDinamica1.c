#include <stdio.h>
#include <stdlib.h>

#define MAX 3

void main(void) {
    char *p;
    p = malloc(2*sizeof(char));
    *p = 'A';
    p++;
    *p = 'B';
    p--;
    printf("valor de A:%c ", *p);
    printf("\tvalor de B:%c: ", *++p);
    p--;
    printf("\n\n");
    int i;
    for (i=0; i<2;i++) {
        printf("%c ", *(p+i));
    }
    free(p);
}
