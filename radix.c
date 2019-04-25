#include <stdio.h>
#include <stdlib.h>

#define TAM 8

int getMaior(int *a, int n);
void countSort(int *a, int n, int exp);
void radixsort(int *a, int n);
void printArray(int *a, int n);

int main() {
    int v[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = TAM;
    radixsort(v, n);
    printArray(v, n);
    return 0;
}

void radixsort(int *a, int n){
    int maior = getMaior(a, n);
    int exp;
    for (exp = 1; maior/exp > 0; exp *= 10) {  /** Faz a Contagem de classificação para cada dígito. */
        countSort(a, n, exp);
    }
}

int getMaior(int *a, int n) {
    int maior = a[0];
    int i;
    for (i = 1; i < n; i++) {
        if (a[i] > maior) {
            maior = a[i];
        }
    }
    return maior;
}

/**  Faz a classificação conforme o digito representado por exp  */
void countSort(int *a, int n, int exp) {
    int output[n];
    int count[10] = {0};

   
    int i;
    for (i = 0; i < n; i++)  /** Faz a frequencia  */
        count[ (a[i]/exp)%10 ]++;

    /**  frequência acumulada */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)     {
        output[count[ (a[i]/exp)%10 ] - 1] = a[i];
        count[ (a[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

/** Imprimir o array */
void printArray(int *a, int n) {
    printf("\n\n");
    int i;
    for (i = 0; i < n; i++) {
       printf("%d ", a[i]);
    }

}