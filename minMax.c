#include <stdio.h>
#include <stdlib.h>

int main() {
    int vet[] = {4,2,9,12,120,8,11,71,13,14};
    int n=10;
    int min, max;

    minMax(vet, n, &min,&max);
    printf("%d %d", min, max);
}
void minMax(int *v, int n, int *menor, int *maior) {
    int i;
    *menor = *maior = v[0];
    for (i=1; i<n;i++) {
        if (*menor > *(v+i)) {
            *menor = v[i];
        } else if (*maior < v[i]) {
            *maior = v[i];
        }
    }
}
