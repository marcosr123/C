#include <stdio.h>
#include <stdlib.h>

int pertenceL (int v[], int x, int n);
int pertenceB (int v[], int x, int n);
void imprimir(int v[], int n);
void bolha(int v[], int n);

int main () {
	int v[] = {3,10,8,4,7,13,6,9};
	int n=8;

	int x=14;
	printf("linear: \n");
	if (pertenceL(v,x,n)) {
		printf("numero encontrado!\n");
	} else {
		printf("numero nao encontrado!\n");
	}

	bolha(v,n);
	printf("bolha: ");
	imprimir(v,n);

    printf("\nDigite o valor a ser procurado usando a busca binaria: ");
    scanf("%d",&x);
    int posicao = pertenceB(v,x,n);

    if(posicao!=-1) {
        printf("\nO elemento %d foi encontrado na posição %d do vetor!", v[posicao], (posicao+1));
    } else {
        printf("\nO elemento procurado não existe!");
    }

	return 0;
}

int pertenceL (int v[], int x, int n){
	int i;
	for(i=0;i<n;i++) {
		if (v[i]==x) {
			return 1;
		}
	}
	return 0;
}

int pertenceB (int v[], int x, int n){
	int inf, sup, m;
	inf=0;
	sup=n-1;

	while (inf <= sup) {
	    m=(inf+sup)/2;
		if (x==v[m]) {
			return m;
		} else if (x > v[m]) {
			inf = m+1;
		} else {
			sup = m-1;
		}
	}
	return -1;
}

void imprimir(int v[], int n) {
    int i;
    printf("\n");
    for(i=0; i<n; i++) {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

void bolha(int v[], int n) {
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
