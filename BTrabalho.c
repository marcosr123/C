#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct cliente{
    char nome[30];
    Data nasc;
} Cliente;

typedef struct no{
    Cliente c;
    int id;
    struct no *prox;
}Lista;

void criarLista(Lista *l){
    l=NULL;
}

Lista *insere(Lista *l,Cliente c,FILE *a){
    Lista *novo=malloc(sizeof(Lista));
    strcpy(novo->c.nome,c.nome);
    novo->c.nasc.dia=c.nasc.dia;
    novo->c.nasc.mes=c.nasc.mes;
    novo->c.nasc.ano=c.nasc.ano;
    novo->id=rand()%1000;
    novo->prox=l;
    a=fopen("registro.txt","a");
    fprintf(a,"%d\n",novo->id);
    fputs(novo->c.nome,a);
    fprintf(a,"\n%d\n",novo->c.nasc.dia);
    fprintf(a,"%d\n",novo->c.nasc.mes);
    fprintf(a,"%d\n",novo->c.nasc.ano);
    fclose(a);
    return novo;
}

Lista *insere2(Lista *l,Cliente c,int v,FILE *a){
    Lista *novo=malloc(sizeof(Lista));
    strcpy(novo->c.nome,c.nome);
    novo->c.nasc.dia=c.nasc.dia;
    novo->c.nasc.mes=c.nasc.mes;
    novo->c.nasc.ano=c.nasc.ano;
    novo->id=v;
    novo->prox=l;
    return novo;
}

void ordenar(Lista **l) {
    Lista *ant = *l, *aux;
    int v;
    Cliente c;
    while(ant) {
        aux = ant->prox;
        while(aux) {
            if(ant->id > aux ->id) {
                v=ant->id;
                strcpy(c.nome,ant->c.nome);
                c.nasc.dia=ant->c.nasc.dia;
                c.nasc.mes=ant->c.nasc.mes;
                c.nasc.ano=ant->c.nasc.ano;
                ant->id=aux->id;
                strcpy(ant->c.nome,aux->c.nome);
                ant->c.nasc.dia=aux->c.nasc.dia;
                ant->c.nasc.mes=aux->c.nasc.mes;
                ant->c.nasc.ano=aux->c.nasc.ano;
                aux->id=v;
                strcpy(aux->c.nome,c.nome);
                aux->c.nasc.dia=c.nasc.dia;
                aux->c.nasc.mes=c.nasc.mes;
                aux->c.nasc.ano=c.nasc.ano;
                printf("a");
            }
            aux = aux->prox;

        }
        ant = ant->prox;
    }
}

int main(){
    Lista *mylista,*mylista2;
    criarLista(mylista);
    criarLista(mylista2);
    FILE *arq;
    Cliente c;
    int op,n;
    while(op!=3){
        printf("1-registrar cliente \n");
        printf("2-ler arquivo e ordenar clientes \n");
        printf("3- \n");
        printf("\n\n\n\n\n\nopcao:\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            printf("digite o nome do cliente:\n");
            scanf("%s",c.nome);
            printf("digite o dia do nascimento:\n");
            scanf("%d",&c.nasc.dia);
            printf("digite o mes do nascimento:\n");
            scanf("%d",&c.nasc.mes);
            printf("digite o ano do nascimento:\n");
            scanf("%d",&c.nasc.ano);
            mylista=insere(mylista,c,arq);
            system("cls");
            break;
        case 2:
            arq=fopen("registro.txt","rt");
            while(!feof(arq)){
                fscanf(arq,"%d",&n);
                fscanf(arq,"%s",&c.nome);
                fscanf(arq,"%d",&c.nasc.dia);
                fscanf(arq,"%d",&c.nasc.mes);
                fscanf(arq,"%d",&c.nasc.ano);
                mylista2=insere2(mylista2,c,n,arq);
                printf("\n%d",mylista2->id);
            }
            fclose(arq);
            ordenar(&mylista2);

        }
    }
}
