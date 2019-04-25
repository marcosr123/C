#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
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
	float vtotal;
	
}Venda[cap];


void insereProduto(Produto *p){
	int i;
	for(i=0;i<2;i++){
		printf("DIGITE O NOME DO PRODUTO:\n");
		fflush(stdin);
		gets(p[i]->nome);
		printf("DIGITE A DESCRIÇÃO DO PRODUTO:\n");
		fflush(stdin);
		gets(p[i]->desc);
		printf("DIGITE O VALOR DO PRODUTO:\n");
		p[i]->valor;
		scanf("%f",p[i]);
		printf("DIGITE A QUANTIDADE EM ESTOQUE:\n");
		p[i]->numeroEstoque;
		scanf("%d", &p[i]);
	}
}

void excluiProduto(){
	
}

void consultaProduto(Produto *p){
	int i;
	char busca[60];
	printf("DIGITE O PRODUTO A SER BUSCADO:\n");
	scanf("%s",busca);
	for (i=0;i<2;i++){
		if(strcmp(p[i]->nome,busca)==0){
			printf("PRODUTO ENCONTRADO: %s ",p[i]->nome);
		}
	}
	printf("ERRO 404 - PRODUTO NÃO ENCONTRADO");
}

void alteraProduto(Produto *p){
	int i;
	char busca[20];
	printf("DIGITE O PRODUTO A SER ALTERADO:\n");
	scanf("%s",busca);
	for(i=0;i<2;i++){
		if(strcmp(busca,p[i]->nome)==0){
			printf("PRODUTO ENCONTRADO\n");
			printf("DIGITE O NOVO NOME:\n");
			fflush(stdin);
			gets(p[i]->nome);
			printf("DIGITE A NOVA DESCRIÇÃO:\n");
			fflush(stdin);
			gets(p[i]->desc);
			printf("DIGITE O NOVO VALOR:\n");
			p[i]->valor;
			scanf("%d", p[i]);
			printf("DIGITE A QUANTIDADE EM ESTOQUE:\n");
			p[i]->numeroEstoque;
			scanf("%d", p[i]);
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
		}
	}
}

void realizarVenda(Venda *v, Cliente *c, Produto *p){
	printf("DIGITE O NOME DO PRODUTO A SER COMPRADO:\n");
	printf("DIGITE A QUANTIDADE A SER COMPRADA:\n");
}

void cadastraCliente(Cliente *c){	
	system("cls");
	int i;
	for(i=0; i<2; i++){
		printf("DIGITE SEU NOME:\n");
		fflush(stdin);
		gets(c[i]->nome);
		printf("DIGITE SEU CPF\n");
		fflush(stdin);
		gets(c[i]->CPF);
		c[i]->cod = rand()%999;
	}
	
}

void alteraCliente(Cliente *c){
	int i;
	char busca[20];
	printf("DIGITE O CLIENTE A SER ALTERADO:\n");
	scanf("%s",busca);
	for(i=0;i<2;i++){
		if(strcmp(busca,c[i]->nome)==0){
			printf("CLIENTE ENCONTRADO\n");
			printf("DIGITE O NOVO NOME:\n");
			fflush(stdin);
			gets(c[i]->nome);
			printf("DIGITE O NOVO CPF:\n");
			fflush(stdin);
			gets(c[i]->CPF);
			break;
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
		}
	}
}

void excluirCliente(Cliente *c){
	system("cls");
	int i;
	char exnome[20];
	printf("DIGITE O NOME DO CLIENTE NO QUAL DESEJA EXCLUIR;\n");
	fflush(stdout);
	gets(exnome);
	for(i=0; i<2; i++){
		int retorno;
		retorno= strcmp(exnome,c[i]->nome);
		if(retorno==0){
			strcpy(c[i]->nome," ");
			strcpy(c[i]->CPF," ");
			printf("CADASTRO DA PESSOA %s EXLUIDO COM SUCESSO!", c[i]->nome);
		}else{
			printf("CADASTRO NAO ECONTRADO");
		}
	}
}

void mostrarClientes(Cliente *c){
	system("cls");
	int i;
	for(i=0; i<2; i++){
		printf("OS CLIENTES CADASTRADOS SAO:\n %s\n", c[i]->nome);
	}	
}

void mostraProdutos(Produto *p){
	system("cls");
	int i;
	for(i=0;i<2;i++){
		printf("%s\n",p[i]->nome);
		printf("%s\n",p[i]->desc);
		printf("%f\n",p[i]->valor);
	}
}

void menu(){
	printf("\t\tCADASTRO DE PRODUTOS\n");
	printf("\t\t1 - INSERIR PRODUTO\n");
	printf("\t\t2 - BUSCAR PRODUTO\n");
	printf("\t\t3 - ALTERAR PRODUTO\n");
	printf("\t\t4 - EXCLUIR PRODUTO\n");
	printf("\t\t5 - EXIBIR ESTOQUE\n");
	printf("\t\t6 - CADASTRAR CLIENTE\n");
	printf("\t\t7 - ALTERAR CLIENTE\n");
	printf("\t\t8 - EXCLUIR CLIENTE\n");
	printf("\t\t9 - EXIBIR CLIENTES\n");
	printf("\t\t10 - REALIZAR VENDAS\n");
	printf("\t\t11 - REALIZAR VENDAS\n");
	printf("\t\t12 - SAIR\n");
}

int main(){
	int op=0;
	setlocale(LC_ALL,"portuguese");
	//srand(time(NULL));
	Produto *p[cap];
 	p[cap]=(Produto*)malloc(cap*sizeof(Produto));	
	Cliente *c[cap];
	c[cap]= (Cliente*)malloc(cap*sizeof(Cliente));
	Venda *v[cap];
	v[cap]= (Venda*)malloc(cap*sizeof(Venda));
	cadastraCliente(*c);
	excluirCliente(*c);
	mostrarClientes(*c);
}

