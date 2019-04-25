#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


typedef struct produto{
	int CodIdenti;
	char Nome[20];
	char Descricao[40];
	float ValorU;
	int quant;
	struct produto *prox;
}Produto;

typedef struct cadastro{
	int CodCliente;
	char nome[20];
	char Cpf[11];
	struct cadastro *prox;
}Cadastro;

typedef struct vendas{
	int codvenda;
	int codigcli;
	float valortotal;
	int codigpr;
	int status;
	char CPf[11];
	struct vendas *ant;
	struct vendas *prox;
}Vendas;

typedef struct no{
	int ID;
	int codvenda;
	int quant;
	struct no *prox;
}Lista;

typedef struct f{
	Lista *inicio;
	Lista *fim;
	int tam;
}Fila;

Fila* criaFila() {
    Fila *f=(Fila*)malloc(sizeof(Fila));
    f->inicio=NULL;
    f->fim=NULL;
    f->tam=0;
    return f;
}
Produto* criarProduto(){
	return NULL;
}

Cadastro* criarCadastro(){
	return NULL;
}

Vendas* criarVendas(){
	return NULL;
}
Produto* liberap(Produto* l) {
    Produto *p = l;
    while (p != NULL) {
        p = l->prox;
        free(l);
        l = p;
    }
    return NULL;
}
Cadastro* liberac(Cadastro* l) {
    Cadastro *p = l;
    while (p != NULL) {
        p = l->prox;
        free(l);
        l = p;
    }
    return NULL;
}
Vendas* liberav(Vendas* lista) {
    Vendas *p = lista;
    while (p != NULL) {
        p = lista->prox;
        free(lista);
        lista = p;
    }
    return NULL;
}
void retira(Fila *f,Vendas *v, Produto *p) {
    Lista *elem=f->inicio;
	Vendas *vi;
	system("pause");
		for(vi=v;vi!=NULL;vi=vi->prox){
			system("pause");
			if(vi->codvenda==elem->codvenda){
				system("pause");
				if(p->quant>=elem->quant){
					system("pause");
					vi->status=1;
					f->inicio = elem->prox;
					if (f->inicio == NULL) /* verifica se fila ficou vazia */
						f->fim = NULL;
					f->tam--;
    				free(elem);
				}
				
			}
		}
}
int cpfvalida(Cadastro *l){
	
char cpf[12];  
int icpf[12];  
int i,somador=0,digito1,result1,result2,digito2,valor,aux=0,cont=0;  

	printf("Digite o cpf: ");  
	scanf(" %s",cpf);  
	
  
//Efetua a conversao de array de char para um array de int.  
	for(i=0;i<11;i++){  
		icpf[i]=cpf[i]-48;  
	}	  
  //numeros iguais
  for(i=0;i<10;i++){
  	if(icpf[i]==icpf[i+1]){
  		cont++;
	  }
  }
  if(cont==10){
  	aux++;
  	printf("CPF Inválido");
  	return aux;
  }
//PRIMEIRO DIGITO.  
  
	for(i=0;i<9;i++){  
		somador+=icpf[i]*(10-i);  
	}  
  
	result1=somador%11;  
  
	if((result1==0) || (result1==1)){  
		digito1=0;  
	}else{  
		digito1 = 11-result1;  
	}  
  
//SEGUNDO DIGITO.  
  
somador=0;  
  
	for(i=0;i<10;i++){  
		somador+=icpf[i]*(11-i);  
	}  
  
	valor=(somador/11)*11;  
	result2=somador-valor;  
  
	if((result2==0) || (result2==1)){  
		digito2=0;  
	}else{  
		digito2=11-result2;  
	}	  
  
//RESULTADOS DA VALIDACAO.  
  
	if((digito1==icpf[9]) && (digito2==icpf[10])){  
		printf("\nCPF Válido.\n");  
		strcpy(l->Cpf,cpf);
		return aux;
	}else{  
		printf("CPF Inválido!.\n");
		aux++;
		return aux;  
	}  

}
Produto* inserir(Produto *l,int n){
	printf("-----------------------------CADASTRAR PRODUTO --------------------------------\n\n");
	Produto *novo =(Produto*) malloc(sizeof(Produto));
	printf("ID: %d\n",n);
	novo->CodIdenti=n;
	fflush(stdin);
	printf("Digite o nome do Produto que deseja inserir: ");
   	fgets(novo->Nome,21,stdin);
   	fflush(stdin);
   	printf("Digite uma descrição do produto:");
   	fgets(novo->Descricao,41,stdin);
	fflush(stdin);
	printf("Digite o Valor unitario do produto:");
	scanf("%f",&novo->ValorU);
	printf("Digite  numero de unidades desse produto no estoque:");
	scanf("%d",&novo->quant);

	novo->prox=l;
	return novo;

}
Produto* buscar(Produto *l){
	Produto *p;
	int v;
	printf("Informe o ID do produto a ser buscado\n");
	scanf ("%d",&v);
	for(p=l;p!=NULL;p=p->prox){
		if(p->CodIdenti==v){
			return p;
		}

    }
    return NULL;
}




Produto *alterar_produto(Produto *l){
	int alterar,aix=0,quant;
	Produto *p;

		printf("Informe o ID do Produto a ser alterado!\n");
		scanf("%d",&alterar);
		for(p=l; p!=NULL; p=p->prox){
			if(p->CodIdenti == alterar){
				fflush(stdin);
				printf("Digite o novo nome do Produto que deseja inserir:");
				fgets(p->Nome,20,stdin);

				fflush(stdin);
				printf("Digite uma nova descrição para o produto:");
				fgets(p->Descricao,40,stdin);

				printf("Digite o novo Valor unitario do produto:");
				scanf("%f", &p->ValorU);

				printf("Digite  o novo numero de unidades desse produto no estoque:");
				scanf("%d",&quant);
				p->quant+=quant;
				aix++;
				return p;
			}
		}
			if( aix == 0){
				printf("Produto não encontrado!\n");
				return NULL;
			}
}

Produto *excluir_produto(Produto *l){
	int excluir;
	Produto *ant=NULL;
	Produto *p=l;

	printf("Informe o ID do Produto a ser excluido!\n");
	scanf("%d",&excluir);

		while((p!=NULL)&&(p->CodIdenti!= excluir)){
			ant = p;
			p=p->prox;
		}
		if(p==NULL){
			return l;
		}else if(ant == NULL){
			l=p->prox;
		}else {
			ant->prox=p->prox;
		}
	 	free(p);
	 	return l;
}

void exibir_produto(Produto *l){
	Produto *p;
	int verif = p->quant;
	if(verif<0){
		verif =0;
	}
		for(p=l; p!=NULL; p=p->prox){			
			printf ("Codigo: %d\n",p->CodIdenti);
			printf("Nome: %s\n",p->Nome);
			printf("Descrição: %s\n",p->Descricao);
			printf("Valor: %0.2f\n",p->ValorU);
			printf("Quantidade: %d\n",verif);

        }
}
Cadastro *inserir2(Cadastro *l,int c){
	printf("-----------------------------CADASTRAR CLIENTE --------------------------------\n\n");
    Cadastro *novo = (Cadastro*) malloc(sizeof(Cadastro));
   int cont=0,valid,aux=0,t=1;
   printf ("ID: %d\n",c);
   novo->CodCliente = c;
   fflush(stdin);
    printf("DIGITE O NOME DO CLIENTE: ");
    fgets(novo->nome,21,stdin);
    fflush(stdin);

while(t==1){
t = cpfvalida(novo);
}
novo->prox = l;
return novo;

}

void alterar_cliente(Cadastro *l){
	int i,alterar,verif=0,aux=0;
	Cadastro *c;
		printf("Informe o ID do Cliente a ser alterado!\n");
		scanf("%d",&alterar);
		for(c =l; c!=NULL; c=c->prox){
			if(c->CodCliente == alterar){
				fflush(stdin);
				printf("Digite o novo nome do cliente que deseja alterar:");
				fgets(c->nome,20,stdin);
                cpfvalida(c);
                aux++;
			}
		}
		if(aux == 0){
			printf("Cliente não encontrado!\n");
		}
}

Cadastro *excluir_cliente(Cadastro *l){
	int excluir;
	Cadastro *ant=NULL;
	Cadastro *p=l;

	printf("Informe o ID do Cliente a ser excluido!\n");
	scanf("%d",&excluir);

		while((p!=NULL)&&(p->CodCliente != excluir)){
			ant = p;
			p=p->prox;
		}
		if(p==NULL){
			return l;
		}else if(ant == NULL){
			l=p->prox;
		}else {
			ant->prox=p->prox;
		}
	 	free(p);
	 	return l;
}
void exibir_cliente(Cadastro *c){
	Cadastro *l;
	for(l=c;l!=NULL;l=l->prox){
		printf ("Codigo: %d\n",c->CodCliente);
		printf("Nome: %s\n",c->nome);
		printf("CPF: %s\n",c->Cpf);
	}
}

void insere_fila(Fila *f,int n,int quanti){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->ID=n;
	novo->codvenda=n;
	novo->quant=quanti;
	novo->prox = NULL;
		if (f->fim!=NULL){
	  		f->fim->prox = novo;
		}else{
		  f->inicio = novo;
		}
	   f->fim = novo;
	   f->tam++;

	   

}

Cadastro* verificarcliente(Cadastro *c){
	int aux=0,codigocli;
	Cadastro *l;
	printf ("\nInforme o ID do cliente: ");
	scanf ("%d",&codigocli);
		for (l=c; l!=NULL; l=l->prox){
			if(l->CodCliente == codigocli){
				aux++;
				return l;
			}
		}
		return NULL;
}

Produto* verificarproduto(Produto *p){
	int aux=0,codigopro;
	Produto *l;
	printf ("\nInforme o ID do produto: ");
	scanf ("%d",&codigopro);
		for (l=p; l!=NULL; l=l->prox){
			if(l->CodIdenti == codigopro){
				return l;
			}
		}
		return NULL;
}
Vendas *vendas(Vendas *v,int n,Produto *p,Cadastro *c,Fila *f){
	int uni,aux,aux1,i,cont=0,resp,rep=0,vini=0;
	Vendas *novo = (Vendas*)malloc(sizeof(Vendas));
	Produto *result1;
	Cadastro *result2;

		do{
			if(rep!=0){	
            printf ("ID do produto ou ID do cliente inválidos!");
      		 }
            result2 = verificarcliente(c);
            result1 = verificarproduto(p);
            system("cls");     
            rep++;
            system("pause");
            system("cls");
        }while(result1 == NULL && result2 == NULL);
			if(result1->quant<0){
				printf ("Esse produto tem %d unidades à %0.2f reais cada\n",vini,result1->ValorU);
				printf("Deseja comprar quantas unidades?");
				scanf ("%d",&uni);
			}else{
				printf ("Esse produto tem %d unidades à %0.2f reais cada\n",result1->quant,result1->ValorU);
				printf("Deseja comprar quantas unidades?");
				scanf ("%d",&uni);
			}
				if (uni <= result1->quant){
					novo->codvenda = n;
					printf ("Produto comprado com sucesso!\n");
					printf ("Informações do comprador:\n");
					printf ("Codigo Venda: %d\nCPF Comprador: %s\nUnidades Compradas: %d\n ",novo->codvenda,result2->Cpf,uni);
					aux1 = result1->ValorU;
					novo->valortotal = aux1 * uni;
					aux = result1->quant;
					result1->quant = aux - uni;
					strcpy(novo->CPf,result2->Cpf);
					novo->codigcli=result2->CodCliente;
					novo->codigpr = result1->CodIdenti;
					novo->status=1;

				}else{
					printf ("Estoque Insuficiente!\n");
					printf ("Você será colocado em uma fila de espera!\n");
					insere_fila(f,n,uni);
					novo->codvenda=n;
					aux1 = result1->ValorU;
					novo->valortotal = aux1 * uni;
					aux = result1->quant;
					result1->quant = aux - uni;
					
					strcpy(novo->CPf,result2->Cpf);
					novo->codigcli=result2->CodCliente;
					novo->codigpr = result1->CodIdenti;
					novo->status=0;
			 }

	novo->prox=v;
	novo->ant=NULL;
	if (v != NULL){
		v->ant = novo;
	}
	return novo;
}

void consultarVendas(Vendas *v){
Vendas *l;
   printf(" -----------------------------CONSULTAR VENDAS----------------------");
	for(l=v;l!=NULL;l=l->prox){
		printf("\nCODIGO DA VENDA: %d\n",l->codvenda);
		printf ("CODIGO DO PRODUTO: %d\n",l->codigpr);
		printf("CPF DO COMPRADOR: %s\n",l->CPf);
		printf("Valor: %0.2f\n",l->valortotal);
		printf ("Status: %d\n",l->status);
	printf("-------------------------------------------------------------------\n");
	
	}
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	Produto *minhalistap;
	minhalistap = criarProduto();
	Cadastro *minhalistac;
	minhalistac = criarCadastro();
	Vendas *minhalistav;
	 minhalistav = criarVendas();
	Fila *minhafila;
	minhafila = criaFila();
	Produto *veri;
	Produto *verif;
	Vendas *vi;
	int i,n,pcadas=-1,cadas=-1,vvendas=-1;
	int opcao;

	while(opcao!=12){
		printf("                           ------------------------SISTEMA DE VENDAS ----------------------------\n");
		printf("                           |    DIGITE 1 - PARA INSERIR UM PRODUTO NO NOSSO ESTOQUE:            |\n");
		printf("                           |    DIGITE 2 - PARA BUSCAR UM PRODUTO NO NOSSO ESTOQUE:             |\n");
		printf("                           |    DIGITE 3 - PARA ALTERAR UM PRODUTO DO NOSSO ESTOQUE:            |\n");
		printf("                           |    DIGITE 4 - PARA EXCLUIR UM PRODUTO DO NOSSO ESTOQUE:            |\n");
		printf("                           |    DIGITE 5 - PARA EXIBIR PRODUTOS DO NOSSO ESTOQUE:  	        |\n");
		printf("                           |    DIGITE 6 - PARA CADASTRAR UM CLIENTE:                           |\n");
		printf("                           |    DIGITE 7 - PARA ALTERAR UM CLIENTE CADASTRADO:                  |\n");
		printf("                           |    DIGITE 8 - PARA EXCLUIR UM CLIENTE:                             |\n");
		printf("                           |    DIGITE 9 - PARA EXIBIR OS CLIENTES CADASTRADOS:                 |\n");
		printf("                           |    DIGITE 10 - PARA REALIZAR VENDAS:                               |\n");
		printf("                           |    DIGITE 11 - PARA CONSULTAR VENDAS REALIZADAS:                   |\n");
		printf("                           |    DIGITE 12 - PARA SAIR:                                          |\n");
		scanf("%d",&opcao);
		system("cls");
		switch(opcao){

		case 1:
			pcadas++;
			minhalistap = inserir(minhalistap,pcadas);
			system ("pause");
			system("cls");
			break;
		case 2:
			veri =buscar(minhalistap);
			if(veri!=NULL){
				printf("ID encontrado!\n");
			}else{
				printf("ID não encontrado!\n");
			}
			system ("pause");
			system("cls");
		break;
		case 3:
			verif = alterar_produto(minhalistap);
			retira(minhafila,minhalistav,verif);
			system ("pause");
			system("cls");
		break;
		case 4:
			minhalistap=excluir_produto(minhalistap);
			system ("pause");
			system("cls");
		break;
		case 5:
			exibir_produto(minhalistap);
			system ("pause");
			system("cls");
		break;
		case 6:
			cadas++;
			minhalistac=inserir2(minhalistac,cadas);
			system("pause");
			system("cls");
			break;
		case 7:
			alterar_cliente(minhalistac);
			system ("pause");
			system("cls");
		break;
		case 8:
			minhalistac=excluir_cliente(minhalistac);
			system ("pause");
			system("cls");
		break;
		case 9:
			exibir_cliente(minhalistac);
			system("pause");
			system("cls");
		break;
		case 10:
			vvendas++;
			minhalistav=vendas(minhalistav,vvendas,minhalistap,minhalistac,minhafila);
			system("pause");
			system("cls");
		break;
		case 11:
         	consultarVendas(minhalistav);
           	system("pause");
           	system("cls");
		break;
		case 12:
		    minhalistap=liberap(minhalistap);
		    minhalistac=liberac(minhalistac);
		    minhalistav=liberav(minhalistav);
		break;
		default:
				printf ("Opção invalida!\n");
				system ("pause");
				system("cls");
			break;


		}
	}
}


