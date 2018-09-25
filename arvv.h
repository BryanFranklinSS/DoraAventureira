/* arvv.h */
/* TAD ArvVar*/

#define Tam 100
#define N_CHAR 122
#define PASTA "pasta"
#define ARQUIVO "arquivo"

/* Tipo exportado */
typedef struct arvvar ArvVar;


/* Funções */
ArvVar* mkdir (char* n);

void arvv_insere (ArvVar* a, ArvVar* sa);

void arvv_imprime (ArvVar* a);

int arvv_pertence (ArvVar* a, char c[Tam]);

void arvv_libera (ArvVar* a);



//=============================================

ArvVar* cd(char* nm, ArvVar* aa);

ArvVar* mm(ArvVar* n);
	
ArvVar* touch (char* n);

 
int verifica_extensao(char* str);




