	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	// Definição dos tipos 'itemDaLista' e 'listaEncadeada'
	typedef struct item {
		int codigo;
		struct item *pMaior;
		struct item *pMenor;
	} itemDaArvore;

	typedef struct arvore{
		itemDaArvore *root;
		int tamanho;
	} arvoreBinaria;

	// Prototipação das funções
	void inicializacao (arvoreBinaria*);
	itemDaArvore minimo(itemDaArvore);


	// Desenvolvimento das funções

	// Inicializa um lista vazia.
	void inicializacao (arvoreBinaria *arvore){
		arvore->root = NULL;
		arvore->tamanho = 0;
	}

	int inserirroot(arvoreBinaria* arvore,int codigo)
	{
		itemDaArvore* novoItem;	
		novoItem = (itemDaArvore* ) malloc (sizeof (itemDaArvore));
		if (novoItem == NULL) {
			return -1;
		}
		novoItem->codigo = codigo;
		arvore->root = novoItem;
		arvore->root->pMaior = NULL;
		arvore->root->pMenor = NULL;
		arvore->tamanho++;
		return 0;
	}

	int inserir(arvoreBinaria* arvore, int codigo)
	{
		itemDaArvore* novoItem;	
		itemDaArvore* atualItem;	
		novoItem = (itemDaArvore* ) malloc (sizeof (itemDaArvore));
		if (novoItem == NULL) {
			return -1;
		}
		novoItem->codigo = codigo;
		
		if(novoItem->codigo > arvore->root->codigo){
			atualItem = arvore->root;			
			while(atualItem->codigo < novoItem->codigo)
				{
					if(atualItem->pMaior == NULL)
					{
						atualItem->pMaior = novoItem;
						atualItem->pMaior->pMaior  = NULL;
						atualItem->pMaior->pMenor  = NULL; 						
						break;
					} 
					atualItem = atualItem->pMaior;
				}
			if(atualItem->codigo > novoItem->codigo)
				atualItem->pMenor = novoItem;		
			
		}
		else{
			atualItem = arvore->root;			
			while(atualItem->codigo > novoItem->codigo)
				{
					if(atualItem->pMenor == NULL)
					{
						atualItem->pMenor = novoItem;
						atualItem->pMenor->pMaior  = NULL;
						atualItem->pMenor->pMenor  = NULL; 						
						break;
					} 
					atualItem = atualItem->pMenor;
				}
			if(atualItem->codigo < novoItem->codigo)
				atualItem->pMaior = novoItem;		
			
		}
		arvore->tamanho++;
		return 0;
	}

	void percorrer(itemDaArvore* root)
	{
		if(root != NULL){
		percorrer(root->pMenor);
		printf("%d ",root->codigo);
		percorrer(root->pMaior);
		}
	}

	void percorrerPreOrdem(itemDaArvore* root)
	{
		if(root != NULL){
		printf("%d ",root->codigo);
		percorrerPreOrdem(root->pMenor);
		percorrerPreOrdem(root->pMaior);
		}
	}

	void remover(itemDaArvore *root, int valor){   
	    itemDaArvore aux;   
	    if(root != NULL){   
	       // se o valor que será removido for menor que o nó atual,   
	       if(valor < root->codigo){    
	           remover(root->pMenor, valor); // faz recursividade á pMenoruerda   
	       }else{   
	            // se o valor que será removido for maior que o nó atual,   
	            if(valor > root->codigo){    
	                 remover(root->pMaior, valor); // faz recursividade á pMaioreita.   
	             }else{ // encontrou   
	                // quando o nó a ser removido for encontrado,   
	                if(root->pMenor != NULL && root->pMaior !=NULL ){    
	                     // verificamos se os nós filhos da pMenoruerda e pMaioreita não são null.   
	                     // se não forem null, buscamos o menor nó a partir do nó da pMaioreita.   
	                     aux = minimo(*root->pMaior);
	                     root->codigo = aux->codigo;   
	                     remover(root->pMaior, root->codigo);   
	                }else{    
	                       // caso os nó da pMaioreita e da pMenorueda, ou somente o da pMaioreita for null,    
	                       // precisamos apenas remover   
	                       aux = *root;    
	                       // o nó atual e fazer ajustar os ponteiros    
	                       if(root->pMenor == NULL){    
	                           // se o nó da pMenoruerda for vazio   
	                           // o nó pai do atual, apontará para o filho da pMaioreita do nó atual.   
	                           root = root->pMaior;   
	                       }    
	                       else {   
	                            // se o nó da pMenoruerda não for vazio.   
	                            // o nó pai do atual, apontará para o filho da pMenoruerda do nó atual.   
	                            *root = *root->pMenor;                          
	                       }   
	                free(aux);   
	                }   
	            }        
	       }    
	    }     
	}

	itemDaArvore minimo(itemDaArvore no){// procura o nó com valor mínimo   
    if(no == NULL){   
       return NULL;   
    }else{   
          if( no->pMenor == NULl){   
              return no;   
          }else{   
              return minimo(no->pMenor);   
          }   
    }   
} 


	int main(){
		arvoreBinaria *minhaArvore;
		minhaArvore = (arvoreBinaria*) malloc (sizeof (arvoreBinaria));
		if (minhaArvore == NULL) {
			printf("Não foi possível alocar memória\n");
			return -1;
		}
		inicializacao(minhaArvore);
		inserirroot(minhaArvore, 50);
		inserir(minhaArvore, 40);
		inserir(minhaArvore, 30);
		inserir(minhaArvore, 22);
		inserir(minhaArvore, 35);
		inserir(minhaArvore, 45);
		inserir(minhaArvore, 43);
		inserir(minhaArvore, 48);
		inserir(minhaArvore, 68);
		inserir(minhaArvore, 63);
		inserir(minhaArvore, 62);
		inserir(minhaArvore, 65);
		inserir(minhaArvore, 70);
		inserir(minhaArvore, 69);
		inserir(minhaArvore, 80);
		percorrerPreOrdem	(minhaArvore->root;
		return 0;
	}