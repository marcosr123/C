#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>


typedef struct produto{
	int cod;
	char nome[20];
	char desc[40];
	float valor;
	int numeroEstoque;
	struct produto *prox;
}Produto;

typedef struct cliente{
	int cod;
	char nome[20];
	char CPF[15];
	struct cliente *prox;
}Cliente;

typedef struct vendas{
	char nomep[20];
	char CPFc[11];
	int cod_venda;
	float vtotal;
	int numestoque_atualizado;
	struct vendas *prox;
	struct vendas *ant;
}Venda;

Produto* crialista() {
    return NULL;
}

Cliente* criarlista(){
	return NULL;
}


Produto* inserirProduto(Produto *p, int ID){
	system("cls");
    Produto *novo =(Produto*) malloc(sizeof(Produto));
    printf("ID: %d\n",ID);
    novo->cod = ID;
	fflush(stdin);
	printf("Digite o nome do Produto que deseja inserir: ");
   	fgets(novo->nome,21,stdin);
   	fflush(stdin);
   	printf("Digite uma descrição do produto:");
   	fgets(novo->desc,41,stdin);
	fflush(stdin);
	printf("Digite o Valor unitario do produto:");
	scanf("%f",&novo->valor);
	printf("Digite  numero de unidades desse produto no estoque:");
	scanf("%d",&novo->numeroEstoque);
	novo->prox=p;
	return novo;
}

Produto* excluiProduto(Produto *p){
	system("cls");
	Produto *ant= NULL;
	Produto *prod= p;
	int busca;
	printf("DIGITE O NOME DO PRODUTO NO QUAL DESEJA EXCLUIR;\n");
	fflush(stdin);
	scanf("%d",&busca);
	int retorno;
    while(prod!=NULL && prod->cod!=busca){
        ant=prod;
        prod=prod->prox;
        printf("DEU1");
    }
	if(prod==NULL){
        return p;
        printf("DEU");
	}
    if(ant==NULL){
        p= prod->prox;
    }else{
        ant->prox=prod->prox;
        printf("DEU3");
    }
    free(prod);
    return p;

}

Produto* consultaProduto(Produto *p){
	system("cls");
    Produto *buscar;
    int id;
	printf("DIGITE O PRODUTO A SER BUSCADO:\n");
	fflush(stdin);
	scanf("%d",&id);
	for (buscar=p;buscar!=NULL;buscar=buscar->prox){
		if(id == buscar->cod){
			return buscar;
		}
    }
    return NULL;

}
Produto *alteraProduto(Produto *p){
	system("cls");
	Produto *busca;
	int id;
	printf("DIGITE O PRODUTO A SER ALTERADO:\n");
	fflush(stdin);
	scanf("%d",&id);
	for(busca=p;busca!=NULL;busca=busca->prox){
		if(id == busca->cod){
			printf("PRODUTO ENCONTRADO\n");
			printf("DIGITE O NOVO NOME:\n");
			fflush(stdin);
			gets(busca->nome);
			printf("DIGITE A NOVA DESCRIÇÃO:\n");
			fflush(stdin);
			gets(busca->desc);
			printf("DIGITE O NOVO VALOR:\n");
			busca->valor;
			scanf("%d", &busca);
			//printf("DIGITE A QUANTIDADE EM ESTOQUE:\n");
			//fflush(stdin);
			//p->numeroEstoque;
			//scanf("%d", &p);
			return busca;
			getchar();
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
			getchar();
		}
	}

}

Cliente* cadastraCliente(Cliente *c, int id){
	system("cls");
    Cliente *cl= (Cliente*)malloc(sizeof(Cliente));
	cl->cod = id;
	printf("ID: %s",id);
	printf("DIGITE O NOME DO CLIENTE:\n");
	fflush(stdin);
	gets(cl->nome);
	printf("DIGITE O CPF DO CLIENTE:\n");
	int tam=11;
	fflush(stdin);
	gets(cl->CPF);
	int tamanho;
	tamanho= strlen(cl->CPF);
	if(tamanho==11){
        printf("CPF VALIDO!");
        getchar();
	}else{
        printf("CPF INVALIDO!");
        getchar();
	}
    
    return cl;
}

Cliente*  alteraCliente(Cliente *c){
	system("cls");
	Cliente *buscar;
	int cpf;
	printf("DIGITE O CPF DO CLIENTE A SER ALTERADO:\n");
	scanf("%d",cpf);
	for(buscar=c;buscar!=NULL;buscar=buscar->prox){
		if(cpf == buscar->CPF){
			printf("CLIENTE ENCONTRADO\n");
			printf("DIGITE O NOVO NOME:\n");
			fflush(stdin);
			gets(buscar->nome);
			fflush(stdout);
			printf("DIGITE O NOVO CPF:\n");
			fflush(stdin);
			gets(buscar->CPF);
			int tamanho;
			tamanho= strlen(buscar->CPF);
			if(tamanho!=11){
				printf("CPF INVALIDO, DIGITE NOVAMENTE!");
				getchar();
				alteraCliente(c);
			}
			getchar();
			return buscar;
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
			getchar();
		}
	}
    system("cls");
}

/*void excluirCliente(Cliente *c){
	system("cls");
	int i;
	char exnome[20];
	printf("DIGITE O NOME DO CLIENTE NO QUAL DESEJA EXCLUIR;\n");
	fflush(stdin);
	gets(exnome);
	for(i=0; i<cap; i++){
        int retorno;
        retorno= strcmp(exnome,c[i]->nome);
		if(retorno==0){
			strcpy(c[i]->nome," ");
			strcpy(c[i]->CPF," ");
			c[i]->cod=0;
			printf("CADASTRO DA PESSOA %s EXLUIDO COM SUCESSO!");
			getchar();
		}else{
			printf("CADASTRO NAO ECONTRADO NA POSICAO %d", i);
			getchar();
		}
	}
    system("cls");
}*/

void mostrarClientes(Cliente *c){
	system("cls");
	Cliente *cl;
	printf("OS CLIENTES CADASTRADOS SAO:\n");
	for(cl=c;cl!=NULL;cl=cl->prox){
		printf("                   %s\n", cl->nome);
		printf("\n CPF DE NUMERO : %s", cl->CPF);
		printf("\n CODIGO NUMERO : %d\n", cl->cod);
	}
}


void mostraProdutos(Produto *p){
	Produto *prod;
	for (prod = p; prod != NULL; prod = prod->prox) {
		printf("ID = %d\n",prod->cod);
        printf("NOME = %s\n", prod->nome);
		printf("DESCRIÇÃO = %s\n",prod->desc);
		printf("VALOR = %f0.2\n",prod->valor);
		printf("QUANTIDADE EM ESTOQUE = %d\n\n",prod->numeroEstoque); 
    }
	getchar();
}

/*void realizarVenda(Venda *v, Cliente *c, Produto *p){
	char prodvendido[20];
	char clientecompra[11];
	int n,i;
	printf("DIGITE O CPF DO CLIENTE QUE IRA COMPRAR: \n");
    fflush(stdin);
    gets(clientecompra);
    for(i=0; i<cap;i++){
        if(strcmp(clientecompra,c[i]->CPF)==0){
            printf("CPF DO CLIENTE IDENTIFICADO!\n");
            v[i]->CPFc==clientecompra;
            break;
        }
    }
    printf("CPF DO CLIENTE NAO IDENTIFICADO! TENTE NOVAMENTE!");
    //realizarVenda(v,c,p);
	printf("DIGITE O NOME DO PRODUTO A SER COMPRADO:\n");
    fflush(stdin);
    gets(prodvendido);
	for(i=0;i<cap;i++){
		if(strcmp(prodvendido,p[i]->nome)==0){
			printf("DIGITE A QUANTIDADE A SER COMPRADA:\n");
			scanf("%d", &n);
            p[i]->nome==v[i]->nomep;
			p[i]->numeroEstoque= p[i]->numeroEstoque-n;
			v[i]->numestoque_atualizado=p[i]->numeroEstoque;
			printf("QUANTIDADE RESTANTE DO PRODUTO %s NO ESTOQUE EH: %d\n", v[i]->nomep, v[i]->numestoque_atualizado);
			break;
		}
	}
	printf("NOME DO PRODUTO NAO ACHADO NO ESTOQUE!");
	getchar();
    //realizarVenda(v,c,p);
}

//void ConsultarVenda(Venda *v, Cliente *c){
	//int i;
	//printf("VENDAS REALIZADAS:  \n");
	//for(i=0; i<cap; i++){
		//if(c[i]->cod!=0){
			//printf("CPF DO COMPRADOR: %s\n PRODUTO COMPRADO: %s\n QUANTIDADE RESTANTE NO ESTOQUE: %d\n", v[i]->CPFc, v[i]->nomep, v[i]->numestoque_atualizado);
		//}
	//}
//}
int validarCpf(Cliente *c){
    Cliente *cl;
    char cpfc[11];

}*/


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
	printf("\t\t11 - EXIBIR VENDAS\n");
	printf("\t\t12 - SAIR\n");
}

int main(){
    system("color 3E");
	int op=0,d=0,b=0;
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	Produto *p = crialista();
	Cliente *c = criarlista();
	//Venda *v;
	MENU:while(op!=12){
		menu();
		scanf("%d",&op);
		switch(op){
			case 1:
				d++;
				system("cls");
				p = inserirProduto(p,d);
				system("cls");
				break;
			case 2:
				if(d>0){
                    system("cls");
                    Produto  *s = consultaProduto(p);
                    if (s!=NULL){
                    	printf("PRODUTO ENCONTRADO: %s",s->nome);
                    	system("cls");
					}else{
						printf("PRODUTO NÂO ENCONTRADO!");
					}
                    break;
				}else
                    printf("PRODUTOS NAO CADASTRADOS!");
                    system("pause");
			case 3:
				if(d>0){
                    system("cls");
                    p = alteraProduto(p);
                    break;
				}else
                    printf("PRODUTOS NAO CADASTRADOS!");
                    system("pause");
			case 4:
				if(d>0){
                    system("cls");
                    p = excluiProduto(p);
                    break;
                }else
                    printf("PRODUTOS NAO CADASTRADOS!");
                    system("pause");
			case 5:
				system("cls");
				mostraProdutos(p);
				break;
			case 6:
				b++;
				system("cls");
				c = cadastraCliente(c,b);
				system("cls");
				break;
			case 7:
				if(b>0){
                    system("cls");
                    c = alteraCliente(c);
                    break;
				}else
                    printf("CLIENTES NAO CADASTRADOS!");
                    system("pause");
			case 8:
				if(b>0){
                    system("cls");
                    //excluirCliente(c);
                    break;
				}else
                    printf("CLIENTES NAO CADASTRADOS!");
                    system("pause");
			case 9:
				if(b>0){
                    system("cls");
                    mostrarClientes(c);
                    break;
				}else
				printf("CLIENTES NAO CADASTRADOS!");
				system("pause");
			case 10:
				if(b&&d >0){
                    //realizarVenda(v,c,p);
                    system("cls");
                    break;
				}else
                    printf("EH PRECISO CADASTRAR CLIENTES E PRODUTOS!");
                    system("pause");
			case 11:
				system("cls");
				//ConsultarVenda(*v,*c);
				break;
			case 12:
				free(p);
				free(c);
			    return 0;
				break;
			default:
				printf("OPÇÃO INVÁLIDA!");
				break;
                system("cls");
		}
	}

}
