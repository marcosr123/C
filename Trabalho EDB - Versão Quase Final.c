#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
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
	char nomep[20];
	char CPFc[11];
	int cod_venda;
	float vtotal;
	int numestoque_atualizado;
}Venda[cap];

void inserirProduto(Produto *p){
	system("cls");
	int i;
	for(i=0;i<2;i++){
		printf("DIGITE O NOME DO PRODUTO:\n");
		fflush(stdin);
		gets(p[i]->nome);
		printf("DIGITE A DESCRIÇÃO DO PRODUTO:\n");
		fflush(stdin);
		gets(p[i]->desc);
		printf("DIGITE O VALOR DO PRODUTO:\n");
		fflush(stdin);
		scanf("%f", &p[i]->valor);
		printf("DIGITE A QUANTIDADE EM ESTOQUE:\n");
		fflush(stdin);
		scanf("%d", &p[i]->numeroEstoque);
		system("cls");
	}
    getchar();
}

void excluiProduto(Produto *p){
	system("cls");
	int i;
	char prodnome[20];
	printf("DIGITE O NOME DO PRODUTO NO QUAL DESEJA EXCLUIR;\n");
	fflush(stdin);
	gets(prodnome);
	int retorno;
	for(i=0; i<2; i++){
		retorno= strcmp(prodnome,p[i]->nome);
		if(retorno==0){
			strcpy(p[i]->nome," ");
			strcpy(p[i]->desc, " ");
			p[i]->numeroEstoque=0;
			p[i]->valor=0;
			printf("CADASTRO DO PRODUTO %s EXLUIDO COM SUCESSO!", p[i]->nome);
			getchar();
		}else{
			printf("PRODUTO NAO ECONTRADO");
			getchar();
		}
	}
	getchar();
}

void consultaProduto(Produto *p){
	system("cls");
	int i;
	char busca[60];
	printf("DIGITE O PRODUTO A SER BUSCADO:\n");
	scanf("%s",busca);
	int retorno;
	for (i=0;i<2;i++){
		retorno= strcmp(busca,p[i]->nome);
		if(retorno==0){
			system("cls");
			printf("PRODUTO ENCONTRADO: %s ",p[i]->nome);
			getchar();
		}else{
			printf("ERRO 404 - PRODUTO NÃO ENCONTRADO");
			getchar();
		}
	}

	getchar();
}

void alteraProduto(Produto *p){
	system("cls");
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
			scanf("%d", &p[i]);
			printf("DIGITE A QUANTIDADE EM ESTOQUE:\n");
			fflush(stdin);
			p[i]->numeroEstoque;
			scanf("%d", &p[i]);
			getchar();
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
			getchar();
		}
	}

}

void realizarVenda(Venda *v, Cliente *c, Produto *p){
	char prodvendido[20];
	char clientecompra[11];
	int n,i;
	printf("DIGITE O CPF DO CLIENTE QUE IRA COMPRAR");
    fflush(stdin);
    gets(clientecompra);
    for(i=0; i<2;i++){
        if(strcmp(clientecompra,c[i]->CPF)==0){
            v[i]->CPFc==clientecompra;
        }
    }
    printf("NOME DO CLIENTE NAO IDENTIFICADO! TENTE NOVAMENTE!");
    realizarVenda(v,c,p);
	printf("DIGITE O NOME DO PRODUTO A SER COMPRADO:\n");
    fflush(stdin);
    gets(prodvendido);
	for(i=0;i<2;i++){
		if(strcmp(prodvendido,p[i]->nome)==0){
			printf("DIGITE A QUANTIDADE A SER COMPRADA:\n");
			scanf("%d", &n);
			p[i]->numeroEstoque= p[i]->numeroEstoque-n;
			v[i]->numestoque_atualizado=p[i]->numeroEstoque;
			break;
		}
	}
	printf("NOME DO PRODUTO NAO ACHADO NO ESTOQUE!");
    realizarVenda(v,c,p);
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
		int tamanho;
		tamanho= strlen(c[i]->CPF);
		if(tamanho!=11){
			printf("CPF INVALIDO, DIGITE NOVAMENTE!");
			getchar();
			cadastraCliente(c);
		}
		c[i]->cod = rand()%999;
		getchar();
	}

}

void alteraCliente(Cliente *c){
	system("cls");
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
			fflush(stdout);
			printf("DIGITE O NOVO CPF:\n");
			fflush(stdin);
			gets(c[i]->CPF);
			int tamanho;
			tamanho= strlen(c[i]->CPF);
			if(tamanho!=11){
				printf("CPF INVALIDO, DIGITE NOVAMENTE!");
				getchar();
				alteraCliente(c);
			}
			getchar();
			break;
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
			getchar();
		}
	}

}

void excluirCliente(Cliente *c){
	system("cls");
	int i;
	char exnome[20];
	printf("DIGITE O NOME DO CLIENTE NO QUAL DESEJA EXCLUIR;\n");
	fflush(stdin);
	gets(exnome);
	for(i=0; i<2; i++){
        int retorno;
        retorno= strcmp(exnome,c[i]->nome);
		if(retorno==0){
			strcpy(c[i]->nome," ");
			strcpy(c[i]->CPF," ");
			c[i]->cod=0;
			printf("CADASTRO DA PESSOA %s EXLUIDO COM SUCESSO!");
			getchar();
		}else{
			printf("CADASTRO NAO ECONTRADO");
			getchar();
		}
	}

}

void mostrarClientes(Cliente *c){
	system("cls");
	int i;
	for(i=0; i<2; i++){
		if(c[i]->cod!=0){
			printf("OS CLIENTES CADASTRADOS SAO:\n %s\n", c[i]->nome);
			printf("\n CPF DE NUMERO : %s", c[i]->CPF);
			printf("\n CODIGO NUMERO : %d\n", c[i]->cod);
			getchar();
		}
	}
	getchar();

}

void mostraProdutos(Produto *p){
	system("cls");
	int i;
	for(i=0;i<2;i++){
		if(p[i]->valor!=0){
			printf("PRODUTO CADASTRADO: %s\n",p[i]->nome);
			printf("DESCRICAO: %s\n",p[i]->desc);
			printf("VALOR: %2f\n",p[i]->valor);
			printf("QUANTIDADE NO ESTOQUE: %d\n\n",p[i]->numeroEstoque);
			getchar();
		}
	}
	getchar();

}

void menu(){
	system("cls");
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
    system("color 3E");
	int op=0;
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	Produto *p[cap];
	p[cap]=(Produto*)malloc(cap*sizeof(Produto));
	Cliente *c[cap];
	c[cap]= (Cliente*)malloc(cap*sizeof(Cliente));
	Venda *v[cap];
	v[cap]= (Venda*)malloc(cap*sizeof(Venda));
	MENU:while(op!=12){
		menu();
		scanf("%d",&op);
		switch(op){
			case 1:
				system("cls");
				inserirProduto(*p);
				break;
			case 2:
				system("cls");
				consultaProduto(*p);
				break;
			case 3:
				system("cls");
				alteraProduto(*p);
				break;
			case 4:
				system("cls");
				excluiProduto(*p);
				break;
			case 5:
				system("cls");
				mostraProdutos(*p);
				break;
			case 6:
				system("cls");
				cadastraCliente(*c);
				break;
			case 7:
				system("cls");
				alteraCliente(*c);
				break;
			case 8:
				system("cls");
				excluirCliente(*c);
				break;
			case 9:
				system("cls");
				mostrarClientes(*c);
				break;
			case 10:
				system("cls");
                realizarVenda(*v,*c,*p);
				break;
			case 11:
				system("cls");

				break;
			case 12:
			    return 0;
				break;
			default:
				printf("OPÇÃO INVÁLIDA!");
				break;
		}
	}

}

