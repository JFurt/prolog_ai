#ifndef _TABELA_H_
#define _TABELA_H_
#include "compilador.h"


#define CAT_VS 0
#define CAT_PROC 1
#define CAT_PF 2
#define CAT_FUNC 3
#define CAT_LABEL 4

#define TIPO_INT 0
#define TIPO_BOOL 1

#define PF_VAL 0
#define PF_REF 1







typedef struct VarSimples{
   int nl;
   int desl;
   int tipo;
}VarSimples;

typedef struct Procedure{
   int nl; //nivel lexico;
   int np; //num parametros;
   int *tipo_param;
   int *pas_param;
   char rot[TAM_ROTULO];
}Procedure;

typedef struct Label{
   int nl; //nivel lexico;
   char rot[TAM_ROTULO];
}Label;

typedef struct Function{
   Procedure p;
   VarSimples vs;

}Function;
typedef struct ParametroFormal{
   int nl;
   int desl;
   int tipo;
   int vr;
}ParametroFormal;
   

typedef union Attribute{
   VarSimples VS;
   Procedure Proc;
   ParametroFormal PF;
   Function Func;
   Label Label;
}Attribute;

typedef struct Celula{
   char ident[TAM_TOKEN];
   short int categoria;
   Attribute *attribute;
}Celula;

typedef struct Tabela{
   Celula **celulas;
   int nc;
}Tabela;



typedef struct Rotulo{
   struct Rotulo *prev;
   char abre[TAM_ROTULO];
   char fecha[TAM_ROTULO];
}Rotulo;


typedef struct PilhaRotulo{
   Rotulo *last;
   int contador;
}PilhaRotulo;

typedef struct NodoTipo{
   int tipo;
   struct NodoTipo *prev;
}NodoTipo;


typedef struct RotuloSim{
   int contador;
   char base[TAM_ROTULO];
   char s[TAM_ROTULO];
}RotuloSim;

typedef struct Valor{
   int val;
   struct Valor *p;
}Valor;

/*TABELA*/
Tabela tabela;
void iniciaTS();
void insereTS(char ident[TAM_TOKEN], short int categoria, Attribute *attribute);
void retiraTS(int n);
int buscaTS(char ident[TAM_TOKEN]);
int limpaTS();
void checaRepTS(char *token);
int ultimoProcTS();
//void insereDeslocParTS(int n);
void atualizaProcTS();
void atualizaFuncTS(int tipo);
int numeroVSTS();
/* PILHAS E ROTULOS*/
NodoTipo *topoPilhaTipo;
PilhaRotulo rotulos;
RotuloSim *rot_proc;
RotuloSim *rot_pula;
RotuloSim *rot_label;
Valor *topo_val;
Rotulo *last_single_rot;

void iniciaPilhas();
void imprimePilhaTipos();
void empilhaTipo(int tipo);
int desempilhaTipo();
int checaTipo(int tipo,int tipo_res);
void handleNormalExpression(int ind_element);
void criaRotuloSingle();

#endif
