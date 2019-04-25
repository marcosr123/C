#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// AUTOR: HUGO MENDES
struct ficha{
	char Nome[40];
	char teleforne[20];
	char Nascimento[20];
};
struct ficha agenda[5]; // tamanho da agenda
int ficha_e =0, posicao =0; 
char opcao[2] ="0"; // posicao da agenda
int i;

void procurar(int ficha_e){
	char procurado[40];
	
	printf("DIGITE O NOME DA PESSOA QUE DESEJA PROCURAR NA LISTA TELEFONICA\n:");
	gets(procurado);
	
	bool achei = false;
	int i;
	for(i=0;i<ficha_e;i++){
		if(strcmp(procurado,agenda[i].Nome) == 0){
			achei = true;
			printf("\n\n O TELEFONE DA PESSOA: %s PROCURADA E : %s\n\n ", agenda[i].Nome, agenda[i].teleforne);
			break;
		}
		else if(achei == false){
			printf("NOME NAO FOI ENCONTRADO:\n");
		}
	}
}

int main(){


	printf("                                 AGENDA TELEFONICA - HUGO MENDES:\n\n");
while(opcao[0]!= '5'){
  int i;
  	printf("\n\nDIGITE 1 - PARA CADASTRAR UMA PESSOA NA AGENDA TELEFONICA:\n:");
		printf("DIGITE 2 - PARA REMOVER UMA PESSOA DA AGENDA\n:");
			printf("DIGITE 3 - PARA IMPRIMIR:\n");
				printf("DIGITE 4 - PARA  PROCURAR UMA PESSOA NA AGENDA TELEFONICA:\n");
			printf("DIGITE 5 - PARA SAIR DA AGENDA:\n");
			gets(opcao);
			if(opcao[0] == '1'){
				system("cls");
				printf("DIGITE O NOME DA PESSOA:\n");
				gets(agenda[posicao].Nome);
				printf("DIGITE O TELEFONE DA PESSOA:\n");
				gets(agenda[posicao].teleforne);
				printf("DIGITE A DATA DE NASCIMENTO DA PESSOA:\n");
				gets(agenda[posicao].Nascimento);
				ficha_e++;
				posicao++; // incrementa a posicao
			}
			if(opcao[0]== '2'){
		        		system("cls");
				char procurado[40]; // VETOR PARA GUARDAR O NOME DA PESSOA QUE SERÁ EXCLUIDA DA LISTA.
				printf("\nDIGITE O NOME DA PESSOA QUE DESEJA EXCLUIR:\n");
				gets(procurado);
				
				bool achei = false;
			    	int i;
				for(i=0; i<ficha_e ; i++){
					if(strcmp(procurado,agenda[i].Nome)==0){
						achei = true;
						printf("\nO TELEFONE DA PESSOA %s E: %s E SERA EXCLUIDO:\n\n", agenda[i].Nome, agenda[i].teleforne);
						
						int j;
						for(j=i+1;ficha_e;j++){
							agenda[j-1]=agenda[j];
							
						}
						ficha_e--;
						posicao--;
						break;
					}
					if(achei == false){
						printf("\nNOME NAO ENCONTRADO:\n");
					}
					
				}
			}
			
			if(opcao[0]== '3'){
						system("cls");
				printf("\n\n");
				int i;
				for(i=0;i<ficha_e;i++){
					printf("O TELEFONE DA PESSOA %s E: %s", agenda[i].Nome,agenda[i].teleforne);
				}
				if(ficha_e == 0){
					printf("NAO HA PESSOAS CADASTRADAS:");
				}
			}
			if(opcao[0]== '4'){
						system("cls");
				procurar(ficha_e);
			}
}

return 0;
}

