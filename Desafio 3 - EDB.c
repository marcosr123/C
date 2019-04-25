#include <stdio.h>
#include <stdlib.h>

//Marcos Richard Barros Cutrim - 2017149507

typedef struct pessoa{
	char nome[50],num[20],nasc[30];
}Pessoa;

Pessoa pessoa[10];

void procura_cadastro(int pos){
	char pessoa1[50];
	int i;
	printf("Digite o nome a ser procurado: ");
	gets(pessoa1);
	for(i=0;i<pos+1;i++){
		if(strcmp(pessoa[i].nome,pessoa1)==0){
			printf("Pessoa encontrada: %s %s %s",pessoa[i].nome,pessoa[i].num,pessoa[i].nasc);
			break;
		}else{
			printf("Erro 404 - Pessoa não encontrada!");
		}
	}
}

int main(){
	char procura[20];
	int pos=0,op=0,i,j;
	while(op!=5){
		printf("\t\tAgente Telefonica");
		printf("\t1 - Cadastrar nova pessoa\n");
		printf("\t2 - Imprime Agenda\n");
		printf("\t3 - Remover pessoa\n");
		printf("\t4 - Procurar pessoa\n");
		printf("\t5 - Sair\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				system("cls");
				printf("Digite o nome da pessoa:");
				gets(pessoa[pos].nome);
				printf("Digite a data de nascimento:");
				gets(pessoa[pos].nasc);
				printf("Digite o numero:");
				gets(pessoa[pos].num);
				pos++;
				break;
			case 2:
				system("cls");
				if(pos==0){
					printf("Não há cadastros\n");
				}else{
					for (i=0;i<pos+1;i++){
						printf("Telefone: %s || Nome: %s || Nascimento: %s",pessoa[i].num,pessoa[i].nome,pessoa[i].nasc);
					}
				}
				break;
			case 3:
				system("cls");
				printf("Digite o nome a ser excluido: ");
				gets(procura);
				for(i=0;i<pos+1;i++){
					if(strcmp(pessoa[i].nome,procura)==0){
						for(j=i+1;j<pos+1;j++){
							pessoa[j-1]=pessoa[j];
						}
						pos--;
						break;
					}else{
						printf("Erro 404 - Pessoa não encontrada!");
					}
				}
				break;
			case 4:
				system("cls");
				procura_cadastro(pos);
				break;
			case 5:
				system("pause");
				break;
		}
	}
}
