#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 1000

int inserir (int a,int *v1,int *v2){
	int i;
	if (a==1){
		for (i=0;i<max;i++){
			printf("Digite o valor do vetor %d: ",i);
			scanf("%d",&v1[i]);
		}
	}else if (a==2){
		for (i=0;i<max;i++){
			printf("Digite o valor do vetor %d: ",i);
			scanf("%d",&v2[i]);
		}
	}
	system("cls");
	return 0;
}

int mostrar (int a,int *v1,int *v2){
	int i;
	if (a==3){
		for (i=0;i<max;i++){
			printf("O valor do vetor %d é %d\n",i,v1[i]);
		}
	}else if (a==4){
		for (i=0;i<max;i++){
			printf("O valor do vetor %d é %d\n",i,v2[i]);
		} 
	}
	getch();
	system("cls");
	return 0;	
}

int seleciona (int *v, int a){
	int j,k=a; 
	for (j=a+1;j<max;j++){
		if(v[k]>v[j]){
			k=j;
		}
	}
	return k;
}
	

int organiza (int a,int *v1,int *v2){
	int i,j,k=max;
	if (a==5){
		for (i=1;i<k;i++){
			for (j=0;j<k-i;j++){
				if (v1[j]>v1[j+1]){
					int x = v1[j];
					v1[j] = v1[j+1];
					v1[j+1] = x;
				}
			}
		}
		for (i=1;i<k;i++){
			for (j=0;j<k-i;j++){
				if (v2[j]>v2[j+1]){
					int x = v2[j];
					v2[j] = v2[j+1];
					v2[j+1] = x;
				}
			}
		}
	}else if(a==6){
		int x;
		for (i=0;i<max-1;i++){
			k=seleciona(v1,i);
			x = v1[i];
			v1[i] = v1[k];
			v1[k] = x;
		}
		for (i=0;i<max-1;i++){
			k=seleciona(v1,i);
			x = v2[i];
			v2[i] = v2[k];
			v2[k] = x;
		}
	}	
	return 0;
}

int buscaseq (int a,int b, int *v1,int *v2){
	int i;
	if (a==1){
		for (i=0;i<max;i++){
			if(b==v1[i]){
				printf("O numero %d pertencente ao vetor e se encontra na posição %d",b,i);
			}else{
				printf("O numero %d não pertence ao vetor.",b);
			}
		}
	}else if(a==2){
		for (i=0;i<max;i++){
			if(b==v2[i]){
				printf("O numero %d pertencente ao vetor e se encontra na posição %d",b,i);
			}else{
				printf("O numero %d não pertence ao vetor.",b);
			}
		}
	}
	getch();
	system("cls");
	return 0;
}

int buscabin (int a,int b,int *v1,int *v2){
	int i,f,m;
	i=0;
	f=max-1;
	if(a==1){
		while(i<=f){
			m= (i+f)/2;
			if(b==v1[m]){
				printf("O numero %d pertence ao vetor.",b);
				getch();
				system("cls");
				return 1;
			}else if(b<v1[m]){
				f = m-1;
			}else{
				i = m+1;
			}
		}
	}else if(a==2){
		while(i<=f){
			m= (i+f)/2;
			if(b==v2[m]){
				printf("O numero %d pertence ao vetor.",b);
				getch();
				system("cls");
				return 1;
			}else if(b<v1[m]){
				f = m-1;
			}else{
				i = m+1;
			}
		}
	}
	getch();
	system("cls");
	return 0;
}

int main (){
	setlocale(LC_ALL,"Portuguese");
	int v1[max],v2[max],indice,i,x,y,z=0;
	while(z==0){
		printf("Digite sua opção:\n 1 - Inserir valores no primeiro vetor\n 2 - Inserir valores no segundo vetor\n 3 - Imprimir Vetor 1\n 4 - Imprimir Vetor 2\n 5 - Ordenação por troca\n 6 - Ordenação por seleção\n 7 - Busca sequencial\n 8 - Busca Binária\n 9 - Sair\n");
		scanf("%d",&indice);
		switch(indice){
			case 1:
				system("cls");
				inserir(indice,v1,v2);
				break;
			case 2:
				system("cls");
				inserir(indice,v1,v2);
				break;
			case 3:
				system("cls");
				mostrar(indice,v1,v2);
				system("cls");
				break;
			case 4:
				system("cls");
				mostrar(indice,v1,v2);
				system("cls");
				break;
			case 5:
				system("cls");
				organiza(indice,v1,v2);
				break;
			case 6:
				system("cls");
				organiza(indice,v1,v2);
				break;
			case 7:
				system("cls");
				printf("Digite em qual vetor será efetuada a busca: ");
				scanf("%d",&x);
				printf("Digite o valor a ser buscado: ");
				scanf("%d",&y);
				buscaseq(x,y,v1,v2);
				break;
			case 8:
				system("cls");
				printf("Digite em qual vetor será efetuada a busca: ");
				scanf("%d",&x);
				printf("Digite o valor a ser buscado: ");
				scanf("%d",&y);
				buscabin(x,y,v1,v2);
				break;
			case 9:
				z= 1;
				break;
		}
	}
}



