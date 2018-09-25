#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvv.h"


char* lestr();
//=============================
int read_cmd (char* cmd, int max);
void print_dir (char* dir, char* user);

int main (void) {
    
    char cmd[N_CHAR];
    char user[N_CHAR] = "claudio";
    char dir[N_CHAR] = "/";
    
    int retVal;   
//=================================
    ArvVar* a1 = mkdir("C:");        //criação do diretorio raiz.
    ArvVar* atudir = mm(a1);
//================================= 
void tree (){
	arvv_imprime (a1);
}
	
//=================================
    ArvVar* d1 = mkdir("users");
    ArvVar* d2 = mkdir("Claudio");
	ArvVar* d3 = mkdir("documents");  
    ArvVar* d4 = mkdir("pictures"); 
    ArvVar* d5 = mkdir("videos"); 
	ArvVar* d6 = mkdir("music"); 
    ArvVar* d7 = mkdir("baidu");  // pq essa mizenga ta em todas huehuhe. 
    ArvVar* d8 = mkdir("desktop"); 
	ArvVar* d9 = mkdir("downloads");  
	
//==================================		   
    arvv_insere (a1, d1);
    arvv_insere (d1, d2);
    arvv_insere (d2, d3);
    arvv_insere (d2, d4);
    arvv_insere (d2, d5);
    arvv_insere (d2, d6);
    arvv_insere (d2, d7);
    arvv_insere (d2, d8);
    arvv_insere (d2, d9);
//=================================
   
    
    // loop principal
    do {   	
    		
        print_dir (dir, user);
        arvv_imprime (a1);    // REMOVER APÓS A FASE DE DESENVOLVIMENTO
        retVal = read_cmd (cmd, N_CHAR); 
        switch (retVal) {
            case 0:
            	//função cd.
                atudir = cd (lestr(),atudir);   
				            
                break;
            case 1:
            	//função mkdir.
                arvv_insere (atudir, mkdir (lestr()));
               
                break;
            case 2:
            	//função touch.
                 arvv_insere (atudir, touch (lestr()));

                break;
            case 3:
            	//função cd.
                tree ();
              
                break;
            case 4:
                // pwd ();
                printf ("Funcao ainda nao implementada\n");
                break;
            case 5:
                 exit (1);
                break;
            default:
                printf ("\r'%s' nao reconhecido como um comando interno\nou externo, um programa operavel ou um arquivo em lotes.\n", cmd);
        }    
    } while (retVal != 5);
    
    free(a1);
    
    return 0;
}

int read_cmd (char* cmd, int max) {
    fflush (stdin);
    fgets (cmd, max, stdin);
    cmd[strlen(cmd)-1] = '\0';
    
    int retVal = -1;
    
    if (!strcmp (cmd, "cd"))
        retVal = 0;
    else if (!strcmp (cmd, "mkdir"))
        retVal = 1;
    else if (!strcmp (cmd, "touch"))
        retVal = 2;
    else if (!strcmp (cmd, "tree"))
        retVal = 3;
    else if (!strcmp (cmd, "pwd"))
        retVal = 4;
    else if (!strcmp (cmd, "exit"))
        retVal = 5;
    
    return retVal;
}

void print_dir (char* dir, char* user) {
    printf ("%s %s$ ", dir, user);
}

//========================================
char* lestr(){
	char* nome = malloc(Tam);
	fflush(stdin);
	fgets(nome, Tam, stdin);
	nome[strlen(nome)-1] = '\0';
	
	return nome;
}



	








