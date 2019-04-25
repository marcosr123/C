#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define cap 20

typedef struct produto{
	int *cod;
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
	Cliente *j[cap];
	//Cliente j[cap]=Cliente.CPF[15];
	int cod_venda;
	int cod_ident;
	float vtotal;
}Venda[cap];


void insereProduto(Produto *p){
	p->cod = 3;
	gets(p.nome);
	gets(p.desc);
	scanf("%f",&p.valor);
}
void excluiProduto(){
	
}
void consultaProduto(){
	
}
void alteraProduto(){
	
}
void realizarVenda(){
	
}

int main(){
	Produto *p[cap];
 	p[cap]=(Produto*)malloc(cap*sizeof(Produto));	
	Cliente *c[cap];
	c[cap]= (Cliente*)malloc(cap*sizeof(Cliente));
	Venda *v[cap];
	v[cap]= (Venda*)malloc(cap*sizeof(Venda));
	gets(p[cap]->cod);

}
