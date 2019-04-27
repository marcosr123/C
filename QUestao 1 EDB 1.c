#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
void Strings(char *String1,char *String2){  
int Dif;
printf("Digite uma String:\n\n");
scanf("%s", String1);
printf("Digite uma String:\n\n");
scanf("%s", String2);
int (strcmp(String1,String2));
printf("%d: é o Tamanho da primeira String e:\n",lstrlen(String1));
printf("%d: é O Tamanho da segunda String e:\n",lstrlen(String2));
Dif=lstrlen(String1) - lstrlen(String2);
printf("%d:é A Diferença das Duas e:\n",Dif);
}

 int main(void){
	setlocale
   char *String1;
   char *String2;
   String1=(char*) malloc(1000*sizeof(char));
   String2=(char*) malloc(1000*sizeof(char));
   Strings(String1,String2);
   system("pause");
    return ;
}
