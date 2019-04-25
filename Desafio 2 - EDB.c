#include <stdio.h>

typedef struct aluno{
    char nome[20];
    int matricula;
    float nota1,nota2,nota3;
}Aluno;

void atrib_nota(Aluno *a){
	printf("Digite o nome do aluno: ");
	scanf("%s",a->nome);
	a->matricula;
	printf("Digite o nome do aluno: ");
	scanf("%d",&a);
	a->nota1;
	printf("Digite o nome do aluno: ");
	scanf("%f",&a);
	printf("Digite o nome do aluno: ");
	scanf("%f",&a);
	printf("Digite o nome do aluno: ");
	scanf("%f",&a->nota3);
}

float calc_media (Aluno *a){
    float media=0;
    return media = (a->nota1 + a->nota2 + a->nota3)/3;
}

void imprime_maior(Aluno *a){
    printf("A maior média pertence a ",a->nome);
    printf("Suas notas são %d ; %d ; %d",a->nota1,a->nota2,a->nota3);
}

int main(){
    int i;
    Aluno *pont[5];
    float media[5];
    for(i=0;i<5;i++){
        atrib_aluno(pont[i]);
    }
    for (i=0;i<5;i++){
        media[i] = calc_media(pont[i]);
    }




}
