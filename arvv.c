/* arvv.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvv.h"

  

struct arvvar {
	char nome[Tam];
	char tipo[Tam];  // as funções quem manipulam os nós verificam pelo tipo se é 
	                //um diretório ou uma pasta, e assim fazem ou não as devidas operações.
	
	struct arvvar* prim; /* ponteiro para eventual primeiro filho */
	struct arvvar* prox; /* ponteiro para eventual irmão */
};



/* Função cria
** Cria uma folha isolada para guardar um caractere e retorna seu ponteiro
*/


/* Função insere
** Insere um nó pré-existente na (sub)árvore 'a'
*/
void arvv_insere (ArvVar* a, ArvVar* sa) {
	
	sa->prox = a->prim;
	a->prim = sa;
}

/* Função imprime
** Percorre a árvore, imprimindo sua estrutura, seguindo a formatação textual
*/
void arvv_imprime (ArvVar* a) {
	ArvVar* p;
	printf(" <%s",a->nome);
	for (p = a->prim; p != NULL; p = p->prox)
		arvv_imprime(p);
	printf(">");
}

/* Função pertence
** Percorre a árvore, buscando um valor. Retorna um inteiro (lógico) indicando se encontrou ou não
*/
int arvv_pertence (ArvVar* a, char c[Tam]) {
	ArvVar* p;	
	
	if ( !strcmp(c, a->nome))
		return 1;
	else {
		for (p = a->prim; p != NULL; p = p->prox) {
			if (arvv_pertence(p, c))
				return 1;
		}
		return 0;
	}
}


/* Função libera
** Libera a memória alocada para a árvore, nó a nó
*/
void arvv_libera (ArvVar* a) {
	ArvVar* p = a->prim;
	while (p != NULL) {
		ArvVar* t = p->prox;
		arvv_libera(p);
		p = t;
	}
	free(a);
}

//=================================================
ArvVar* cd (char* nm, ArvVar* aa){
	ArvVar* p;
	

		for (p = aa->prim; p != NULL; p = p->prox) {
		if(!strcmp(p->tipo,ARQUIVO) && !strcmp(nm, p->nome)){   // assegura que a função cd não mude o diretório para
		printf("o endereco nao correspode a um diretorio.\n");  //dentro de um arquivo. 
		return aa;
		
			}
		if (!strcmp(nm, p->nome))
				return p;
				
		}
				
		printf("O sistema nao pode encontrar o caminho especificado.\n");
		return aa;
		
	}
	
	ArvVar* mm(ArvVar* n){
		ArvVar* aux;
		aux->prim = n->prim;
		
		return aux;
	}

	
	ArvVar* mkdir(char* n) {
	ArvVar* a = (ArvVar*) malloc(sizeof(ArvVar));
	strcpy(a->nome, n);
	
	a->prim = NULL;
	a->prox = NULL;
	
	strcpy(a->tipo, PASTA);

	return a;
}
	
	ArvVar* touch (char* n){
	ArvVar *b = (ArvVar*) malloc(sizeof(ArvVar));
	strcpy(b->nome, n);
	
	b->prim = NULL;
	b->prox = NULL;
	
	if(verifica_extensao(b->nome)){
		char tipo[Tam] = ".txt"; // se não houver extenção, será definido arquivo de texto como padrão.
	    strcat(b->nome, tipo);
	}
	
	strcpy(b->tipo, ARQUIVO);
	
	return b;
		
	}
//----------------------------------------------------	


//----------------------------------------------------
int verifica_extensao(char* str){
	int i;
	for(i =0; i<strlen(str); i++){
		if((str[i] == '.') && (str[i+1] =='\0' )){   // para o caso de declaração de nome com ponto,
			str[strlen(str)-1] ='\0';                //mas sem extensão. Ex: (arquivo.)
		
			return 1;}                                
			   
		if((str[i] == '.') && (str[i+1] !='\0' ))    //verifica se possui ponto e após ele há definição
		    return 0;                                //de tipo. Ex (arquivo.exe)
	}
	return 1;                                        //se não houver declaração de ponto. Ex (arquivo)
}	
	




