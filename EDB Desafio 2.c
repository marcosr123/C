#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct aluno{
	char nome[30];
	int matricula;
	float nota1,nota2,nota3;
}Aluno;

void atrib_nota(Aluno *a){
	printf("Digite o nome do aluno: ");
	scanf("%s",a->nome);
	printf("Digite a matricula do aluno: ");
	scanf("%d",a->matricula);
	printf("Digite a nota 1 do aluno: ");
	scanf("%f",a->nota1);
	printf("Digite a nota 2 do aluno: ");
	scanf("%f",a->nota2);
	printf("Digite a nota 3 do aluno: ");
	scanf("%f",a->nota3);
}

float calc_media (Aluno *a){
    float media=0;
    media = a->nota1;
    media += a->nota2;
    media += a->nota3;
    return media;
}

void imprime_maior(Aluno *a){
    printf("A maior média pertence a ",a->nome);
    printf("Suas notas são %d ; %d ; %d",a->nota1,a->nota2,a->nota3);
}

void organiza_medias (float media[]){
	int i,aux;
	for (i=0;i<5;i++){
		if (media[i]>media[i+1]){
			aux = media[i];
			media[i] = media[i+1];
			media[i+1] = aux;
		}
	}
}

int main(){
	Aluno *aluno[5];
	int i;
	float media[5];
	for(i=0;i<5;i++){
        atrib_aluno(aluno[i]);
    }
    for (i=0;i<5;i++){
        media[i] = calc_media(aluno[i]);
    }
    organiza_medias(&media[5]);

	
	
}
