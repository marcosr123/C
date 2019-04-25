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


void insereProduto(){
	
}
void excluiProduto(){
	
}
void consultaProduto(){
	
}
void alteraProduto(){
	
}
void realizarVenda(){
	
}

void cadastraCliente(Cliente *c){	
	int i;
	for(i=0; i<2; i++){
		printf("DIGITE SEU NOME:\n");
		gets(c[i]->nome);
		printf("DIGITE SEU CPF\n");
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
				//free(c[i]->cod);
				free(c[i]->CPF);
			printf("CADASTRO EXLUIDO COM SUCESSO!");
			}
	 else
		printf("CADASTRO NAO ECONTRADO");
	}
}




int main(){
	Produto *p[cap];
 	p[cap]=(Produto*)malloc(cap*sizeof(Produto));	
	Cliente *c[cap];
	c[cap]= (Cliente*)malloc(cap*sizeof(Cliente));
	Venda *v[cap];
	v[cap]= (Venda*)malloc(cap*sizeof(Venda));
	cadastraCliente(*c);
	excluirCliente(*c);


}
