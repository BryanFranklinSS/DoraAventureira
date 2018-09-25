/* arvv.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvv.h"

  

struct arvvar {
	char nome[Tam];
	char tipo[Tam];  // as fun��es quem manipulam os n�s verificam pelo tipo se � 
	                //um diret�rio ou uma pasta, e assim fazem ou n�o as devidas opera��es.
	
	struct arvvar* prim; /* ponteiro para eventual primeiro filho */
	struct arvvar* prox; /* ponteiro para eventual irm�o */
};



/* Fun��o cria
** Cria uma folha isolada para guardar um caractere e retorna seu ponteiro
*/


/* Fun��o insere
** Insere um n� pr�-existente na (sub)�rvore 'a'
*/
void arvv_insere (ArvVar* a, ArvVar* sa) {
	
	sa->prox = a->prim;
	a->prim = sa;
}

/* Fun��o imprime
** Percorre a �rvore, imprimindo sua estrutura, seguindo a formata��o textual
*/
void arvv_imprime (ArvVar* a) {
	ArvVar* p;
	printf(" <%s",a->nome);
	for (p = a->prim; p != NULL; p = p->prox)
		arvv_imprime(p);
	printf(">");
}

/* Fun��o pertence
** Percorre a �rvore, buscando um valor. Retorna um inteiro (l�gico) indicando se encontrou ou n�o
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


/* Fun��o libera
** Libera a mem�ria alocada para a �rvore, n� a n�
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
		if(!strcmp(p->tipo,ARQUIVO) && !strcmp(nm, p->nome)){   // assegura que a fun��o cd n�o mude o diret�rio para
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
		char tipo[Tam] = ".txt"; // se n�o houver exten��o, ser� definido arquivo de texto como padr�o.
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
		if((str[i] == '.') && (str[i+1] =='\0' )){   // para o caso de declara��o de nome com ponto,
			str[strlen(str)-1] ='\0';                //mas sem extens�o. Ex: (arquivo.)
		
			return 1;}                                
			   
		if((str[i] == '.') && (str[i+1] !='\0' ))    //verifica se possui ponto e ap�s ele h� defini��o
		    return 0;                                //de tipo. Ex (arquivo.exe)
	}
	return 1;                                        //se n�o houver declara��o de ponto. Ex (arquivo)
}	
	




