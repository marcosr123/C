#include<stdio.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL,"portuguese");
	FILE *arquivo;
	int i;
	char texto[100];
	arquivo = fopen ("TESTE.txt","w+");//cria o arquivo para escrita no local do arquivo.c/cpp
	if(arquivo==NULL){
		printf("Erro");
		return 1;
	}
	printf("Arquivo criado. Digite o que deseja pôr no arquivo:\n");
	gets(texto);
	for(i=0;texto[i];i++) fputc(texto[i],arquivo);
	//fprintf(arquivo,"texto:\n%s", texto);//essa parte devia colocar toda a string no arquivo
	fclose(arquivo);
	return 0;
}
