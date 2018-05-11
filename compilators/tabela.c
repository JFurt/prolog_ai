#include "tabela.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void iniciaTS(){
   tabela.nc = 0;
}

void insereTS(char ident[TAM_TOKEN], short int categoria, Attribute *attribute){
   tabela.nc++;
   tabela.celulas = realloc(tabela.celulas,tabela.nc*sizeof(Celula *));
   tabela.celulas[tabela.nc-1] = malloc(sizeof(Celula));
   strcpy(tabela.celulas[tabela.nc-1] -> ident,ident);
   tabela.celulas[tabela.nc-1] -> categoria = categoria;
   tabela.celulas[tabela.nc-1] -> attribute = attribute;
}

void retiraTS(int n){ //retira os n ultimos elementos
   int i;
   for(i=tabela.nc-1;i > tabela.nc-1-n;i--){
      if(tabela.celulas[i] -> attribute){
         free(tabela.celulas[i] -> attribute);
      }
      free(tabela.celulas[i]);
   }
   tabela.nc = tabela.nc - n;
   tabela.celulas = realloc(tabela.celulas, tabela.nc*sizeof(Celula)); //encurtando o vetor com realloc, SE DER BUG PROCURE AQUI.
}

int buscaTS(char ident[TAM_TOKEN]){
   int i;
   for(i = tabela.nc-1; i >=0; i--){
      if(!strcmp(tabela.celulas[i] -> ident, ident)){
         return i;
      }
   }
   return -1;

}
int insereTipoTS(int num_vars,int tipo){
   int i;
   for(i= tabela.nc-1; i>tabela.nc-1-num_vars; i--){
      tabela.celulas[i] -> attribute -> VS.tipo = tipo;
   }

}



int limpaTS(){
   int i=tabela.nc - 1, nvs=0,exit=0,new_nc=tabela.nc,j;
   Celula *cel;
   printf("limpando a tabela de simbolos no nl=%d\n",nivel_lexico);
   while(!exit && i >= 0){
      cel = tabela.celulas[i];
      printf("tirando a entrada %s ",cel -> ident);
      switch(cel -> categoria){
         case CAT_VS:

            if(cel -> attribute -> VS.nl < nivel_lexico){
               exit = 1;
               break;
            }
            printf("%d, %d\n",cel -> attribute -> VS.nl,cel -> attribute -> VS.desl);
            nvs++;
            free(cel -> attribute);
            free(cel);
            new_nc--;
            break;
         case CAT_PROC:

            if(cel -> attribute -> Proc.nl <= nivel_lexico){
               exit = 1;
               break;
            }
            printf("%d",cel -> attribute -> Proc.nl);
            for(j=0;j<cel->attribute->Proc.np;j++)
               printf(" <%d, %d>",cel->attribute->Proc.tipo_param[j],cel->attribute->Proc.pas_param[j]);

            printf("\n");
            free(cel -> attribute);
            free(cel);
            new_nc--;
            break;
         case CAT_PF:

            if(cel -> attribute -> PF.nl < nivel_lexico){
               exit = 1;
               break;
            }
            printf("%d, %d vr=%d\n",cel -> attribute -> PF.nl,cel -> attribute -> PF.desl,cel -> attribute -> PF.vr);
            free(cel -> attribute);
            free(cel);
            new_nc--;
            break;
         case CAT_FUNC:

            if(cel -> attribute -> Func.p.nl <= nivel_lexico){
               exit = 1;
               break;
            }
            printf("%d",cel -> attribute -> Func.p.nl);
            for(j=0;j<cel->attribute->Func.p.np;j++)
               printf(" <%d, %d>",cel->attribute->Func.p.tipo_param[j],cel->attribute->Func.p.pas_param[j]);

            printf("\n");
            free(cel -> attribute);
            free(cel);
            new_nc--;
            break;
         case CAT_LABEL:

            if(cel -> attribute -> Label.nl < nivel_lexico){
               exit = 1;
               break;
            }
            printf("%s, %d\n",cel -> attribute -> Label.rot,cel -> attribute -> Label.nl);
            free(cel -> attribute);
            free(cel);
            new_nc--;
            break;
         default:
            imprimeErro("Erro na tabela de simbolos");
      }
      i--;
   }
   tabela.nc = new_nc;
   return nvs;

}

void checaRepTS(char *token){ // atualizar p func (>=)
   int ind = buscaTS(token),exit=0;
   if(ind >= 0){
      switch(tabela.celulas[ind] -> categoria){
         case CAT_VS:
            if(tabela.celulas[ind] -> attribute -> VS.nl == nivel_lexico){
               exit = 1;
            }
            break;
         case CAT_PROC:
            if(tabela.celulas[ind] -> attribute -> Proc.nl == nivel_lexico){
               exit = 1;
            }
            break;
         case CAT_PF:
            if(tabela.celulas[ind] -> attribute -> PF.nl == nivel_lexico){
               exit = 1;
            }
            break;
         case CAT_FUNC:
            if(tabela.celulas[ind] -> attribute -> Func.p.nl == nivel_lexico){
               exit = 1;
            }
            break;
         case CAT_LABEL:
            if(tabela.celulas[ind] -> attribute -> Func.p.nl == nivel_lexico){
               exit = 1;
            }
            break;
         default:
            sprintf(s,"Erro na tabela de simbolos %d",tabela.celulas[ind] -> categoria);
            imprimeErro(s);
      }

   }
   if(exit){
      sprintf(s,"Redeclaração de %s",token);
      imprimeErro(s);
   }

}


int ultimoProcTS(){
   int i;
   for(i = tabela.nc -1; i >=0; i--)
      if(tabela.celulas[i] -> categoria == CAT_PROC || tabela.celulas[i] -> categoria == CAT_FUNC)
         return i;
   return -1;
}

void atualizaProcTS(){
   int i,proc_index = ultimoProcTS();
   Procedure *p;
   if(tabela.celulas[proc_index] -> categoria == CAT_PROC)
      p = &(tabela.celulas[proc_index] -> attribute -> Proc);
   else if(tabela.celulas[proc_index] -> categoria == CAT_FUNC)
      p = &(tabela.celulas[proc_index] -> attribute -> Func.p);
   int np= p -> np;
   int c=0,d=-3-np;
   
   
   p -> tipo_param = malloc(np*sizeof(int));
   p -> pas_param = malloc(np*sizeof(int));
   for(i=(tabela.nc-np);i<tabela.nc;i++){
      p -> tipo_param[c]=tabela.celulas[i]-> attribute -> PF.tipo;
      p -> pas_param[c]=tabela.celulas[i]-> attribute -> PF.vr;
      tabela.celulas[i]->attribute->PF.desl=d++;
      c++;
   }

}

void atualizaFuncTS(int tipo){
   int f_index = ultimoProcTS();
   tabela.celulas[f_index] -> attribute -> Func.vs.tipo = tipo;
   tabela.celulas[f_index] -> attribute -> Func.vs.nl = nivel_lexico;
   tabela.celulas[f_index] -> attribute -> Func.vs.desl = -4-tabela.celulas[f_index] -> attribute -> Func.p.np;

}

int numeroVSTS(){
   int i,exit,n=0;
   for(i=tabela.nc-1;i>=0;i--){
      switch(tabela.celulas[i] -> categoria){
         case CAT_VS:
            if(tabela.celulas[i] -> attribute -> VS.nl < nivel_lexico){
               exit = 1;
            }else{
               n++;
            }
            break;
         case CAT_PROC:
            if(tabela.celulas[i] -> attribute -> Proc.nl < nivel_lexico){
               exit = 1;
            }
            break;
         case CAT_PF:
            if(tabela.celulas[i] -> attribute -> PF.nl < nivel_lexico){
               exit = 1;
            }
            break;
         case CAT_FUNC:
            if(tabela.celulas[i] -> attribute -> Func.p.nl < nivel_lexico){
               exit = 1;
            }
            break;
         case CAT_LABEL:
            if(tabela.celulas[i] -> attribute -> Func.p.nl < nivel_lexico){
               exit = 1;
            }
            break;
         default:
            sprintf(s,"Erro na tabela de simbolos %d",tabela.celulas[i] -> categoria);
            imprimeErro(s);
      }
      if(exit)
         return n;
   }
   return n;
}
/*void insereDeslocParTS(int n){
   int i,d = -4;
   for(i = tabela.nc-1;i>= tabela.nc-n;i--){
      if(tabela.celulas[i] -> categoria != CAT_PF)
         imprimeErro("Erro de tipos na tabela");
      printf("%d\n",d);
      tabela.celulas[i] -> attribute -> PF.desl = d--;
   }
}*/


void iniciaPilhas(){
   rotulos.last = NULL;
   rotulos.contador = 0;
   rot_proc = malloc(sizeof(RotuloSim));
   rot_proc -> contador = 0;
   sprintf(rot_proc -> base,"P");
   rot_pula = malloc(sizeof(RotuloSim));
   rot_pula -> contador = 0;
   sprintf(rot_pula -> base,"RP");
   rot_label = malloc(sizeof(RotuloSim));
   rot_label -> contador = 0;
   sprintf(rot_label -> base,"GT");
   topo_val = NULL;
   last_single_rot = malloc(sizeof(Rotulo));
}

void criaRotulo(){
   Rotulo *rotulo = malloc(sizeof(Rotulo));
   rotulo -> prev = rotulos.last;
   rotulos.last = rotulo;
   if(rotulos.contador<10)
      sprintf(rotulo -> fecha, "R0%d",rotulos.contador++);
   else
      sprintf(rotulo -> fecha, "R%d",rotulos.contador++);   
   if(rotulos.contador<10)
      sprintf(rotulo -> abre, "R0%d",rotulos.contador++);
   else
      sprintf(rotulo -> abre, "R%d",rotulos.contador++);

}
void criaRotuloSingle(){
   if(rotulos.contador<10)
      sprintf(last_single_rot -> abre, "R0%d",rotulos.contador++);
   else
      sprintf(last_single_rot -> abre, "R%d",rotulos.contador++);
}
void empilhaRotuloSingle(){
   Rotulo *rotulo = malloc(sizeof(Rotulo));
   rotulo -> prev = rotulos.last;
   rotulos.last = rotulo;
   sprintf(rotulo -> abre,"%s",last_single_rot -> abre);
}
void destroiRotulo(){
   if(rotulos.last == NULL)
      return;
   Rotulo *x = rotulos.last;
   rotulos.last = rotulos.last -> prev;
   free(x);
}


void empilhaTipo(int tipo){
   NodoTipo *nodo = malloc(sizeof(NodoTipo));
   nodo -> tipo = tipo;
   nodo -> prev = topoPilhaTipo;
   topoPilhaTipo = nodo;
}

int desempilhaTipo(){
   if(topoPilhaTipo==NULL)
      return -1;
   int tipo = topoPilhaTipo -> tipo;
   NodoTipo *temp = topoPilhaTipo;
   topoPilhaTipo = topoPilhaTipo -> prev;
   free(temp);
   return tipo;
}

int checaTipo(int tipo,int tipo_res){
   if(desempilhaTipo() != tipo || desempilhaTipo() != tipo){
      imprimeErro("Operação de tipos incorretos");
   }
   empilhaTipo(tipo_res);
}

void criaRotuloSim(RotuloSim *rot){
   sprintf(rot -> s,"%s%d",rot -> base,rot -> contador++);
}

void empilhaValor(int v){
   Valor *valor = malloc(sizeof(Valor));
   valor -> p = topo_val;
   valor -> val = v;
   topo_val = valor;
}

void desempilhaValor(int v){
   if(!topo_val)
      imprimeErro("Erro na pilha");
   Valor *valor = topo_val -> p;
   free(topo_val);
   topo_val = valor;
}

void imprimePilhaTipos(){
   NodoTipo *v = topoPilhaTipo;
   while(v){
      printf("%d ", v -> tipo);
      v = v -> prev;
   }
   printf("\n\n\n\n");
}
void handleNormalExpression(int ind_element){
      if(tabela.celulas[ind_element] -> categoria != CAT_PF && //Se o ident n for par.form.
         tabela.celulas[ind_element] -> categoria != CAT_VS){ //Se o ident n for var.simp.
         if(tabela.celulas[ind_element] -> categoria == CAT_FUNC && tabela.celulas[ind_element] -> attribute -> Func.p.np==0){
            //Chama funcao sem parametros, também checa o número de parametros
            empilhaTipo(tabela.celulas[ind_element] -> attribute -> Func.vs.tipo);
            geraCodigo(NULL,"AMEM 1");
            sprintf(s,"CHPR %s,%d",tabela.celulas[ind_element] -> attribute -> Func.p.rot,nivel_lexico);
            geraCodigo(NULL,s);
         }else{
            sprintf(s,"O identificador %s esta sendo usado no local incorreto",token);
            imprimeErro(s);      
         }
      }else{
            if(tabela.celulas[ind_element] -> categoria == CAT_PF &&
               tabela.celulas[ind_element] -> attribute -> PF.vr == PF_REF){
                  //CRVI
                  sprintf(s,"CRVI %d, %d",tabela.celulas[ind_element] -> attribute -> VS.nl,tabela.celulas[ind_element] -> attribute -> VS.desl);
            }else{
                  //CRVL
                  sprintf(s,"CRVL %d, %d",tabela.celulas[ind_element] -> attribute -> VS.nl,tabela.celulas[ind_element] -> attribute -> VS.desl);
            }
            geraCodigo(NULL,s);
            empilhaTipo(tabela.celulas[ind_element] -> attribute -> VS.tipo);
      }
}
