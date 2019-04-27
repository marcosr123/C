# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <locale.h>

typedef struct registro{
		int id;
		char nascimento[20];
		char nome[100];
		struct registro *proximo;
}info;

void iniciar_lista(info **pRecebido){
   *pRecebido = NULL;
}

void inserir_lista(info **pRecebido){

	   info *temporario;

	temporario = (info *)malloc(sizeof(info));
		fflush(stdin);
		if (temporario == NULL){
			printf ("Falta Memória\n");
			
		}
		printf("\nInforme o nome do cliente : ");
		fgets( temporario->nome, 101, stdin );
		fflush(stdin);
		
		printf ("\nInforme a data de nascimento do cliente : ");
		scanf ("%s",temporario->nascimento);
	   
	   temporario->id = rand()%100;
	   	   
	   temporario->proximo = (*pRecebido);
	   (*pRecebido) = temporario;	
	   system ("pause");
	   system ("cls");
	   
}

void imprimir(info *pRecebido) //função para imprimir
{
	
	info *p;
	p = pRecebido;
	if (pRecebido == NULL)
	{
		printf("\nLista Vazia\n");
	}
	else
	{
		while(p!=NULL) //enquanto o registro não for nulo, imprima
		{
			printf("id: %d\n",p->id);
			printf("nome: %s\n",p->nome);
			printf("nascimento: %s\n\n\n",p->nascimento);
			
			
			p = p->proximo;
			
		}
		getchar();
	}
}
int main (){
	int opcao;
	
	info *pLista ;
	
	pLista = (info *)malloc(sizeof(registro));
	
	setlocale(LC_ALL, "Portuguese");
	while (opcao != 3){
		
		printf ("Informe a opção desejada:\n1 - Cadastrar cliente\n2 - Exibir Cadastrados\n3 - sair\n");
		scanf ("%d",&opcao);
		system ("pause");
		system ("cls");
		
		switch (opcao){
			case 1:
				inserir_lista(&pLista);
			break;
			case 2:
				imprimir(pLista);
			break;
			case 3:
			break;
		}
	}
	
}
