#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define cap 20

typedef struct produto{
	int cod;
	char nome[20];
	char desc[40];
	float valor;
	int numeroEstoque;
}Produto[cap];

typedef struct cliente{
	int cod;
	char nome[20];
	char CPF[15];
}Cliente[cap];

typedef struct Vendas{
	//Cliente *j[cap];
	//j[cap]=Cliente.CPF[15];
	int cod_venda;
	int cod_ident;
	float vtotal;
	
}Venda[cap];

void insereProduto(Produto *p){
	int i;
	for(i=0;i<cap;i++){
		printf("DIGITE O NOME DO PRODUTO:\n");
		scanf("%s",p[i]->nome);
		printf("DIGITE A DESCRIÇÃO DO PRODUTO:\n");
		scanf("%s",p[i]->desc);
		printf("DIGITE O VALOR DO PRODUTO:\n");
		scanf("%f",p[i]->valor);
	}
}

void excluiProduto(){
	
}

void consultaProduto(Produto *p){
	int i;
	char busca[60];
	printf("DIGITE O PRODUTO A SER BUSCADO:\n");
	gets(busca);
	for (i=0;i<cap;i++){
		if(strcmp(p[i]->nome,busca)==0){
			printf("PRODUTO ENCONTRADO: %s ",p[i]->nome);
			break;
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
		}
	}
}

void alteraProduto(Produto *p){
	int i;
	char busca[20];
	printf("DIGITE O PRODUTO A SER ALTERADO:\n");
	gets(busca);
	for(i=0;i<cap;i++){
		if(strcmp(busca,p[i]->nome)==0){
			printf("PRODUTO ENCONTRADO\n");
			printf("DIGITE O NOVO NOME:\n");
			gets(p[i]->nome);
			printf("DIGITE A NOVA DESCRIÇÃO:\n");
			
			gets(p[i]->desc);
			printf("DIGITE O NOVO VALOR:\n");
			scanf("%f",p[i]->valor);
			printf("DIGITE A QUANTIDADE EM ESTOQUE:\n");
			scanf("%d",p[i]->numeroEstoque);
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
		}
	}
}

void realizarVenda(){
	
}

void cadastraCliente(Cliente *c){	
	int i;
	for(i=0;i<cap;i++){
		printf("DIGITE SEU NOME:");
		gets(c[i]->nome);
		printf("DIGITE SEU CPF");
		gets(c[i]->CPF);
	}
}

void excluirCliente(Cliente *c){
	int i;
	char exnome[20];
	printf("DIGITE O NOME DO CLIENTE NO QUAL DESEJA EXCLUIR;\n");
	gets(exnome);
	for(i=0; i<2; i++){
		int retorno;
		retorno= strcmp(exnome,c[i]->nome);
		if(retorno==0){
			free(c[i]->nome);
			free(c[i]->CPF);
		printf("CADASTRO EXLUIDO COM SUCESSO!");
		}else{
			printf("CADASTRO NAO ECONTRADO");
		}
	}
}

void menu(Produto *p,Cliente *c, Venda *v){
	int op=0;
	while(op!=12){
		printf("\t\t 1 - Inserir Produto\n");
		printf("\t\t 2 - Buscar Produto\n");
		printf("\t\t 3 - Alterar Produto\n");
		printf("\t\t 4 - Excluir Produto\n");
		printf("\t\t 5 - Exibir Estoque\n");
		printf("\t\t 6 - Cadastrar Cliente\n");
		printf("\t\t 7 - Alterar Cliente\n");
		printf("\t\t 8 - Excluir Cliente\n");
		printf("\t\t 9 - Exibir Clientes\n");
		printf("\t\t 10 - Realizar Vendas\n");
		printf("\t\t 11 - Consultar Vendas\n");
		printf("\t\t 12 - Sair\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				system("cls");
				insereProduto(p);
				break;
			case 2:
				system("cls");
				consultaProduto(p);
				break;
			case 3:
				system("cls");
				alteraProduto(p);
				break;
			case 4:
				system("cls");
				excluiProduto(p);
				break;
			case 5:
				break;
			case 6:
				system("cls");
				cadastraCliente(c);
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
		}
		
	}
	
}


int main(){
	int cont=0;
	Produto *p[cap];
 	p[cap]=(Produto*)malloc(cap*sizeof(Produto));	
	Cliente *c[cap];
	c[cap]= (Cliente*)malloc(cap*sizeof(Cliente));
	Venda *v[cap];
	v[cap]= (Venda*)malloc(cap*sizeof(Venda));
	menu(*p,*c,*v);



}
