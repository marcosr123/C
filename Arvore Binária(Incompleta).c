#include <stdio.h>
#include <stdlib.h>

struct Arvbin{
	char info;
	struct Arvbin* dir;
	struct Arvbin* esq;
};

typedef struct Arvbin ArvBin;

ArvBin* criavoid(void){
	return NULL;
}
ArvBin* cria_arvore (char c, ArvBin* subesq, ArvBin* subdir){
	ArvBin* p=(ArvBin*)malloc(sizeof(ArvBin));
	if(p==NULL) exit(1);
	p->info = c;
	p->esq = subesq;
	p->dir = subdir;
	return p;
}

int arv_vazia (ArvBin* a){
 return a==NULL;
}

ArvBin* arv_libera (ArvBin* a){
	if (!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
	return NULL;
}

void arv_imprime (ArvBin* a){
	if (!arv_vazia(a)){
		printf("%c ",a->info); 
		arv_imprime(a->esq); 
		arv_imprime(a->dir); 
	}
}
void menu (){
	printf("Digite sua opção: \n");
	printf("1- Inserir Produto \n");
	printf("2- Buscar Produto \n");
	printf("3- Alterar Produto \n");
	printf("4- Remover Produto \n");
	printf("5- Exibir Estoque \n");
	printf("6- Sair \n");
}

int main(){
	int op=0;
	while (op!=6){
		menu();
		scanf("%d",&op);
		/*switch(op){
			case 1:
				
		}*/
	}
	
}
