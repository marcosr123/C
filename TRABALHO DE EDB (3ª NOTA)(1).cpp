#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//JOÃO VICTOR PINTO GONÇALVES
//RAIMUNDO JACOB RODRIGUES NETO
//MARCOS RICHARD

typedef struct arvore{
	int elemento;
	struct arvore *esq, *dir;
}Arvore;

void criar_arvore(Arvore **raiz){
	*raiz=NULL;
}

void inserir(Arvore **arvore, Cliente cliente){
	if(*arvore==NULL){
		*arvore=(Arvore*)malloc(sizeof(Arvore));
		(*arvore)->esq=NULL;
		(*arvore)->dir=NULL;
		(*arvore)->elemento=cliente.id;
	}
	else{
		if(cliente.id<((*arvore)->elemento)){
			inserir(&(*arvore)->esq,&(*cliente)->id);
		}
		else inserir(&(*arvore)->dir,cliente.id);
	}
}

void asd(){
	printf("========CADASTRO DE CLIENTES========");
}

int main(){
	setlocale(LC_ALL,"portuguese");
	asd();
	criar_arvore((*arvore)->elemento);
	system("color 1F");
	Cliente cliente[100];
	int opcao,i=0,j=0;
	menu:printf("1-Cadastrar\n2-Sair\nComando-> ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			if(i==100){
				printf("NUMERO MÁXIMO DE CLIENTES ALCANÇADO.");
				system("pause");
				system("cls");
				goto menu;
			}
			printf("NOME: ");
			scanf("%s",cliente[i].nome);
			printf("DATA DE NASCIMENTO: ");
			scanf("%s",cliente[i].nascimento);
			cliente[i].id=rand()%100;
			while(j<=i){
				if(cliente[i].id==cliente[j].id) cliente[i].id=rand()%100;
				j++;
			}
			inserir((*arvore)->elemento,(*cliente[i])->id);
			i++;
			break;
		case 2:
			return 0;
	}

}
