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
	printf("DIGITE O ID DO PRODUTO NO QUAL DESEJA EXCLUIR;\n");
	fflush(stdin);
	scanf("%d",&busca);
	int retorno;
    while(prod!=NULL && prod->cod!=busca){
        ant=prod;
        prod=prod->prox;
    }
	if(prod==NULL){
        return p;
	}
    if(ant==NULL){
        p= prod->prox;
    }else{
        ant->prox=prod->prox;
    }
    free(prod);
    return p;

}

Produto* consultaProduto(Produto *p){
	system("cls");
    Produto *buscar;
    int id;
	printf("DIGITE O ID DO PRODUTO A SER BUSCADO:\n");
	fflush(stdin);
	scanf("%d",&id);
	for (buscar=p;buscar!=NULL;buscar=buscar->prox){
		if(id == buscar->cod){
			system("cls");
			return buscar;
			getchar();
		}
    }
    return NULL;

}
Produto *alteraProduto(Produto *p){
	system("cls");
	Produto *busca;
	int id;
	printf("DIGITE O ID DO PRODUTO A SER ALTERADO:\n");
	fflush(stdin);
	scanf("%d",&id);
	for(busca=p;busca!=NULL;busca=busca->prox){
		if(id == busca->cod){
			printf("PRODUTO ENCONTRADO\n");
			fflush(stdin);
			printf("Digite o nome do Produto que deseja inserir: ");
			fgets(busca->nome,21,stdin);
			fflush(stdin);
			printf("Digite uma descrição do produto:");
			fgets(busca->desc,41,stdin);
			fflush(stdin);
			printf("Digite o Valor unitario do produto:");
			scanf("%f",&busca->valor);
			printf("Digite  numero de unidades desse produto no estoque:");
			scanf("%d",&busca->numeroEstoque);
			system("cls");
			return busca;
			getchar();
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
			getchar();
		}
	}

}

Cliente* cadastraCliente(Cliente *c, int COD){
	system("cls");
    Cliente *cl= (Cliente*)malloc(sizeof(Cliente));
	printf("DIGITE O NOME DO CLIENTE:\n");
	fflush(stdin);
	gets(cl->nome);
	printf("DIGITE O CPF DO CLIENTE:\n");
	fflush(stdin);
	gets(cl->CPF);
	int tamanho;
	tamanho= strlen(cl->CPF);
	if(tamanho==11){
        printf("CPF VALIDO!\n");
	}else{
        printf("CPF INVALIDO!");
        getchar();
	}
    cl->cod = COD;
    printf("ID: %d",COD);
    cl->prox=c;
    getchar();
	return cl;
}

Cliente* alteraCliente(Cliente *c){
	system("cls");
	Cliente *busca;
	int id;
	printf("DIGITE O ID DO CLIENTE A SER ALTERADO:\n");
	fflush(stdin);
	scanf("%d",&id);
	for(busca=c;busca!=NULL;busca=busca->prox){
		printf("fon");
		if(id == busca->cod){
			system("cls");
			printf("CLIENTE ENCONTRADO\n");
			printf("DIGITE O NOVO NOME:\n");
			fflush(stdin);
			gets(busca->nome);
			fflush(stdout);
			printf("DIGITE O NOVO CPF:\n");
			fflush(stdin);
			gets(busca->CPF);
			int tamanho;
			tamanho= strlen(busca->CPF);
			if(tamanho!=11){
				printf("CPF INVALIDO, DIGITE NOVAMENTE!");
				getchar();
				alteraCliente(c);
			}
			getchar();
			return busca;
		}else{
			printf("ERROR 404 - NÂO ENCONTRADO");
			getchar();
		}
	}
    system("cls");
}

Cliente* excluirCliente(Cliente *c){
	system("cls");
	Cliente *ant= NULL;
	Cliente *cli= c;
	int busca;
	printf("DIGITE O ID DO CLIENTE NO QUAL DESEJA EXCLUIR;\n");
	fflush(stdin);
	scanf("%d",&busca);
	int retorno;
    while(cli!=NULL && cli->cod!=busca){
        ant=cli;
        cli=cli->prox;
    }
	if(cli==NULL){
        return c;
        printf("VAZIO");
	}
    if(ant==NULL){
        c= cli->prox;
    }else{
        ant->prox=cli->prox;
    }
    free(cli);
    return c;
}

void mostrarClientes(Cliente *c){
	Cliente *cli;
	for (cli = c; cli != NULL; cli = cli->prox) {
        printf("NOME = %s\n", cli->nome);
		printf("CPF = %s\n",cli->CPF);
		printf("ID = %d\n\n",cli->cod);
    }
	getchar();
	system("cls");
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
	system("cls");
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
		getchar();
		system("cls");
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
                    	getchar();
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
				c= cadastraCliente(c,b);
				system("cls");
				break;
			case 7:
				if(b>0){
                    system("cls");
                    c= alteraCliente(c);
                    break;
				}else
                    printf("CLIENTES NAO CADASTRADOS!");
                    system("pause");
			case 8:
				if(b>0){
                    system("cls");
                     c= excluirCliente(c);
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
			/*case 10:
				if(b&&d >0){
                    realizarVenda(*v,*c,*p);
                    system("cls");
                    break;
				}else
                    printf("EH PRECISO CADASTRAR CLIENTES E PRODUTOS!");
                    system("pause");
			case 11:
				system("cls");
				//ConsultarVenda(*v,*c);
				break;*/
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
