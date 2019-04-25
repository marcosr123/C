#include <stdio.h>
#include <stdlib.h>

#define MAXElem 10

typedef struct {
   int inicio;
   int fim;
   char *nome;
}Cliente; 

void criarFila(Cliente *p, int capacidade){
   p->inicio = 0;
   p->fim = -1;
   p->nome = (char*) malloc (capacidade * sizeof(char));
}

int estavazia (Fila *p){
   return ((p->fim == -1)?1:0);
}

int estacheia (Fila *p){
	return ((p->fim == MAXElem-1)?1:0);
}

void enfileirar (Fila *p, int v){
	p->pElem[++p->fim] = v;
	printf("%d\n\n", p->pElem[p->fim]);
}

int desenfileirar (Fila *p){
   int valor = p->pElem[p->inicio];
   int i;
   for(i=0; i < p->fim; i++) {
     p->pElem[i] = p->pElem[i+1];
   }
   p->fim--;
   return valor;
}

void mostrarFila (Fila *p ){
   int i;
   printf("\n\n");
   for(i=0; i <= p->fim; i++) {
     printf("%d ", p->pElem[i]);
   }
}

int main(){
	Cliente minhaFila;

	criarFila(&minhaFila, MAXElem);
	int sair=1;
	do {
        int op;
        int valor;
		printf("\n1- enfileirar\n");
		printf("2- desenfileirar\n");
		printf("3- mostrar Fila \n");
		printf("4- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op);

		switch (op){
			case 1:
				if(!estacheia(&minhaFila)==1) {
					printf("\nVALOR? ");
					scanf("%d", &valor);
					enfileirar(&minhaFila, valor);
				} else {
					printf("\nFila CHEIA! \n");
				}
				break;
			case 2:
				if (!estavazia(&minhaFila)==1)  {
					valor = desenfileirar (&minhaFila);
					printf ( "\n%d retirado!\n", valor );
				} else {
					printf( "\nFila VAZIA! \n" );
				}
				break;
			case 3:
				if (!estavazia(&minhaFila)==1) {
					mostrarFila(&minhaFila);
				} else {
					printf( "\nFila VAZIA!\n" );
				}
				break;
			case 4:
				sair=0;
                break;
			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}while(sair);
}


