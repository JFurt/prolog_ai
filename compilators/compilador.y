
// Testar se funciona corretamente o empilhamento de parâmetros
// passados por valor ou por referência.
// arrumar o variavel na atribuição

%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tabela.h"

int num_vars,ind_element;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token READ WRITE
%token NUMERO MAIS MENOS OR VEZES DIVIDIDOS AND
%token MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL IGUAL DIFERENTE
%token WHILE DO PROCEDURE FUNCTION LABEL GOTO
%token IF THEN ELSE
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

programa    :{ 
             geraCodigo (NULL, "INPP");
             nivel_lexico=0;
             }
             PROGRAM IDENT 
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {
             geraCodigo (NULL, "PARA"); 
             }
;

 
bloco       : parte_declara_labels
              parte_declara_vars
              parte_declara_procedimentos
              comando_composto 
               {
                  val = limpaTS();
                  if(val>0){
                     sprintf(s,"DMEM %d",val);
                     geraCodigo(NULL,s);
                  }
               }
;

parte_declara_labels: declara_labels | 
;

declara_labels: LABEL lista_de_labels PONTO_E_VIRGULA
;

lista_de_labels: lista_de_labels VIRGULA declara_label | declara_label
;

declara_label: NUMERO {
                  checaRepTS(token);
                  Attribute *attribute = malloc(sizeof(Attribute));
                  attribute -> Label.nl = nivel_lexico;
                  criaRotuloSingle();
                  sprintf(attribute -> Label.rot,"%s",last_single_rot -> abre);
                  insereTS(token,CAT_LABEL, attribute);
	}
;

parte_declara_procedimentos: declara_procedimentos |
;

declara_procedimentos: declara_procedimentos declara_proc_ou_func|
         declara_proc_ou_func
;

declara_proc_ou_func: declara_procedimento | declara_funcao
;


lista_id_par: lista_id_par VIRGULA insere_par 
            | insere_par 
;
insere_par: IDENT {   //arrumar <---
                  checaRepTS(token);
                  Attribute *attribute = malloc(sizeof(Attribute));
                  attribute -> PF.nl = nivel_lexico;
                  attribute -> PF.vr = var_ref;//transfere pf para proc na ts
                  tabela.celulas[ultimoProcTS()] -> attribute -> Proc.np++;
                  insereTS(token,CAT_PF, attribute);
                  num_vars++;
          }
;
parte_declara_vars:  VAR {desloc=0;} declara_vars
            |
;

declara_vars: declara_vars declara_var 
            | declara_var 
;

declara_var : {num_vars = 0;} 
              lista_id_var DOIS_PONTOS 
              tipo 
              { 
                  if(!strcmp(token,"integer")){
                  insereTipoTS(num_vars,TIPO_INT);
                  }else{
                     imprimeErro("Tipo incorreto");
                  }
                  sprintf(s,"AMEM %d",num_vars);
                  geraCodigo(NULL,s);
              }
              PONTO_E_VIRGULA
;



lista_id_var: lista_id_var VIRGULA insere_var 
            | insere_var 
;
insere_var: IDENT {   
                  checaRepTS(token);
                  num_vars++;
                  Attribute *attribute = malloc(sizeof(Attribute));
                  attribute -> VS.nl = nivel_lexico;
                  attribute -> VS.desl = desloc++;
                  insereTS(token,CAT_VS, attribute);
          }
;



/*--------------------Comandos--------------*/
comando_composto: T_BEGIN comandos T_END
;
comandos:  comando comandos_aux
;
comandos_aux: PONTO_E_VIRGULA comandos |//verificar ponto_e_virgula
;

comando: usa_rotulo comando_sem_rotulo
;

comando_sem_rotulo: atrib_ou_proc
      | comando_repetitivo
      | comando_composto
      | comando_condicional
      | preset
      | goto
;


atrib_ou_proc: variavel {l_element = ind_element;}  atrib_ou_prox_aux
;

atrib_ou_prox_aux: ATRIBUICAO atribuicao |
               chama_proc
;
/*-----------------FIM-Comandos--------------*/


/*---------------------Procedimento----------------*/

/*--------------------Declaracao-----------------*/
declara_procedimento: 	PROCEDURE
         IDENT
         {
         
            criaRotuloSingle();
            empilhaRotuloSingle();
            sprintf(s,"DSVS %s",last_single_rot -> abre);
            geraCodigo(NULL,s);
            nivel_lexico++;
            checaRepTS(token);

            /*Inserindo variavel na tabela */
            Attribute *attribute = malloc(sizeof(Attribute));
            attribute -> Proc.nl = nivel_lexico;
            attribute -> Proc.np = 0;

            criaRotuloSingle();
            sprintf(attribute -> Proc.rot,"%s",last_single_rot -> abre);
            insereTS(token,CAT_PROC, attribute); //fix.

            sprintf(s,"ENPR %d",nivel_lexico);
            geraCodigo(last_single_rot -> abre,s);
            
         
         } 
         parametros_formais_aux
         {
            atualizaProcTS();
	 }
         PONTO_E_VIRGULA
         bloco
         {
            sprintf(s,"RTPR %d, %d", nivel_lexico, tabela.celulas[ultimoProcTS()] -> attribute -> Proc.np);
            geraCodigo(NULL,s);
            geraCodigo(rotulos.last -> abre,"NADA");
            destroiRotulo();
            nivel_lexico--;
         } PONTO_E_VIRGULA
;




chama_proc:
            {
               l_element=ind_element;
               if(tabela.celulas[l_element] -> categoria != CAT_PROC){
                  sprintf(s,"A variável %s não é um procedimento",token);
                  imprimeErro(s);
               }
               empilhaValor(l_element);
               num_par=0;
            }
            passagem_parametros
            {
               if(num_par != tabela.celulas[topo_val -> val] -> attribute -> Proc.np)
                  imprimeErro("Numero incorreto de parametros");
               desempilhaValor();
//               sprintf(s,"CHPR %s, %d",tabela.celulas[l_element] -> attribute -> Proc.rot,tabela.celulas[l_element] -> attribute -> Proc.np);
               sprintf(s,"CHPR %s, %d",tabela.celulas[l_element] -> attribute -> Proc.rot,nivel_lexico);
               geraCodigo(NULL,s);
            }

;


/*---------------------Funcao----------------*/
declara_funcao: FUNCTION
         IDENT
         {
            criaRotuloSingle();
            empilhaRotuloSingle();
            sprintf(s,"DSVS %s",last_single_rot -> abre);
            geraCodigo(NULL,s);
            nivel_lexico++;

            checaRepTS(token);

            /*Inserindo variavel na tabela */ // <-----------
            Attribute *attribute = malloc(sizeof(Attribute));
            attribute -> Func.p.nl = nivel_lexico;
            attribute -> Func.p.np = 0;
	         attribute -> Func.p.tipo_param = malloc(sizeof(int));
	         attribute -> Func.p.pas_param = malloc(sizeof(int));
	         criaRotuloSingle();
            sprintf(attribute -> Func.p.rot,"%s",last_single_rot -> abre);
            insereTS(token,CAT_FUNC, attribute); //fix.

            sprintf(s,"ENPR %d",nivel_lexico);
            geraCodigo(last_single_rot -> abre,s);
         
         } 
         parametros_formais_aux
         {
            atualizaProcTS();
	 }
         DOIS_PONTOS
         tipo
         {
            if(!strcmp(token,"integer")){
                  atualizaFuncTS(TIPO_INT);
            }else{
                  imprimeErro("Tipo incorreto");
            }
         }
         PONTO_E_VIRGULA
         bloco
         {
            sprintf(s,"RTPR %d, %d", nivel_lexico, tabela.celulas[ultimoProcTS()] -> attribute -> Proc.np);
            geraCodigo(NULL,s);
            geraCodigo(rotulos.last -> abre,"NADA");
            destroiRotulo();
            nivel_lexico--;
         } PONTO_E_VIRGULA
;
chama_func:
            ABRE_PARENTESES 
            {
               empilhaValor(ind_element);
               if(tabela.celulas[topo_val -> val] -> categoria != CAT_FUNC){
                  sprintf(s,"A variável %s não eh uma funcao",token);
                  imprimeErro(s);
               }
               num_par=0;
               geraCodigo(NULL,"AMEM 1");
               empilhaTipo(tabela.celulas[topo_val -> val] -> attribute -> Func.vs.tipo);
            }
            lista_passagem_parametros_aux FECHA_PARENTESES
            {
               if(num_par != tabela.celulas[topo_val -> val] -> attribute -> Proc.np)
                  imprimeErro("Numero incorreto de parametros");
               sprintf(s,"CHPR %s, %d",tabela.celulas[topo_val -> val] -> attribute -> Proc.rot,nivel_lexico);
               desempilhaValor();
               geraCodigo(NULL,s);
            }
;

/*---------------------------Parametro-----------------*/

/*-------------------------DECLARACAO------------------*/

parametros_formais_aux: ABRE_PARENTESES parametros_formais 
                        FECHA_PARENTESES |

;

parametros_formais:  parametros_formais PONTO_E_VIRGULA declaracao_parametros |
                     declaracao_parametros |
;

declaracao_parametros: passagem_referencia 
                       {num_vars=0;} lista_id_par 
                       DOIS_PONTOS 
                       tipo {
                               if(!strcmp(token,"integer")){
                               insereTipoTS(num_vars,TIPO_INT);
                               }else{
                                  imprimeErro("Tipo incorreto");
                               }
                             }
;

passagem_referencia: VAR {var_ref=PF_REF;}
                     | {var_ref=PF_VAL;}
;


/*----------------------Passagem------------------*/


passagem_parametros: ABRE_PARENTESES lista_passagem_parametros_aux FECHA_PARENTESES|

;

lista_passagem_parametros_aux: lista_passagem_parametros
                  |
;

lista_passagem_parametros: {
                             pas_param = tabela.celulas[topo_val -> val] -> attribute -> Proc.pas_param[num_par];
                             
                             } expressao {
                             if(desempilhaTipo() != tabela.celulas[topo_val -> val] -> attribute -> Proc.tipo_param[num_par])
                                imprimeErro("Erro no tipo da passagem de parametros");
                             num_par++;
                             } passar_parametro_aux 
;

passar_parametro_aux: VIRGULA lista_passagem_parametros |

;
/*-------------------fim-Parametro-----------------*/


/*--------------------EXPRESSAO----------------------*/

expressao: expressao_simples_geral expressao_aux
;

expressao_aux: IGUAL expressao_simples_geral {geraCodigo(NULL,"CMIG");checaTipo(TIPO_INT,TIPO_BOOL);}
     |    DIFERENTE expressao_simples_geral {geraCodigo(NULL,"CMDG");checaTipo(TIPO_INT,TIPO_BOOL);}
     |    MAIOR expressao_simples_geral {geraCodigo(NULL,"CMMA");checaTipo(TIPO_INT,TIPO_BOOL);}
     |    MENOR expressao_simples_geral {geraCodigo(NULL,"CMME");checaTipo(TIPO_INT,TIPO_BOOL);}
     |    MAIOR_IGUAL expressao_simples_geral {geraCodigo(NULL,"CMAG");checaTipo(TIPO_INT,TIPO_BOOL);}
     |    MENOR_IGUAL expressao_simples_geral {geraCodigo(NULL,"CMEG");checaTipo(TIPO_INT,TIPO_BOOL);}
     |
;

expressao_simples_geral:  expressao_simples 
       {
          if(topo_val && pas_param==PF_REF)
            imprimeErro("Erro na passagem de parametros");
       }| pre_termo;

expressao_simples: expressao_simples_geral MAIS pre_termo {geraCodigo(NULL,"SOMA");checaTipo(TIPO_INT,TIPO_INT);}|
         expressao_simples_geral MENOS pre_termo {geraCodigo(NULL,"SUBT");checaTipo(TIPO_INT,TIPO_INT);}|
         expressao_simples_geral OR pre_termo{geraCodigo(NULL,"DISJ");checaTipo(TIPO_BOOL,TIPO_BOOL);}|
         MAIS pre_termo 
         | MENOS pre_termo
         {geraCodigo(NULL,"INVR");}
;

pre_termo: termo 
       {
          if(topo_val && pas_param==PF_REF)
            imprimeErro("Erro na passagem de parametros");
       }| fator;

termo: pre_termo VEZES fator {geraCodigo(NULL,"MULT");checaTipo(TIPO_INT,TIPO_INT);}
     | pre_termo DIVIDIDOS fator {geraCodigo(NULL,"DIVI");checaTipo(TIPO_INT,TIPO_INT);} //<----------
     | pre_termo AND fator {geraCodigo(NULL,"CONJ");checaTipo(TIPO_BOOL,TIPO_BOOL);} //tipos booleanos dos dois lados?
;

fator: variavel seleciona_variavel_dir| 
      NUMERO {
      if(topo_val && pas_param==PF_REF)
         imprimeErro("Erro na passagem de parametros");
      sprintf(s, "CRCT %s",token);
      geraCodigo(NULL,s);
      empilhaTipo(TIPO_INT);
   }
     | ABRE_PARENTESES expressao FECHA_PARENTESES
;

seleciona_variavel_dir: chama_func |
                        variavel_dir; 
variavel_dir:{


      if(topo_val){//dentro da passagem de parametros

         if(pas_param == PF_VAL){
             handleNormalExpression(ind_element);
         }else{ //passagem por referencia, só pode ter uma variavel
            if(tabela.celulas[ind_element] -> categoria == CAT_PF &&
               tabela.celulas[ind_element] -> attribute -> PF.vr == PF_REF){
                  sprintf(s,"CRVL %d, %d",tabela.celulas[ind_element] -> attribute -> VS.nl,tabela.celulas[ind_element] -> attribute -> VS.desl);
            }else{
                  sprintf(s,"CREN %d, %d",tabela.celulas[ind_element] -> attribute -> VS.nl,tabela.celulas[ind_element] -> attribute -> VS.desl);
            }
            geraCodigo(NULL,s);
            empilhaTipo(tabela.celulas[ind_element] -> attribute -> VS.tipo);
         }
      } else {//fora da passagem de parametros
           handleNormalExpression(ind_element);
        }

   }

;
/*------------------FIM-EXPRESSAO--------------------*/


/*------------------ATRIBUICAO-----------------------*/

atribuicao: expressao
       {
          VarSimples *vs;
          switch(tabela.celulas[l_element] -> categoria){
          case CAT_VS:
             vs = &(tabela.celulas[l_element] -> attribute -> VS);
             sprintf(s, "ARMZ %d, %d",vs -> nl, vs -> desl);
             break;
          case CAT_FUNC:
             if(ultimoProcTS()!=l_element)
                imprimeErro("Variavel incorreta no lado esquerdo da atribuicao");
             vs = &(tabela.celulas[l_element] -> attribute -> Func.vs);
             sprintf(s, "ARMZ %d, %d",vs -> nl, vs -> desl);
             break;
          case CAT_PF:
             if(tabela.celulas[l_element] -> attribute -> PF.vr == PF_VAL){
                sprintf(s,"A variavel %s nao pode ser atribuida, pois foi passada como valor",tabela.celulas[l_element] -> ident);
                imprimeErro(s);
             }
             sprintf(s, "ARMI %d, %d",tabela.celulas[l_element] -> attribute -> PF.nl,tabela.celulas[l_element] -> attribute -> PF.desl);
             break;
          default:
             sprintf(s,"Categoria incorreta para atribuicao na variavel %s",tabela.celulas[l_element] -> ident);
             imprimeErro(s);
          }
          if(desempilhaTipo() != vs -> tipo)
                 imprimeErro("Atribuição de tipos diferentes");
          geraCodigo(NULL,s);
       }
;

/*-----------------FIM-ATRIBUICAO--------------------*/


/*----------------------WHILE------------------------*/
comando_repetitivo: WHILE {
            criaRotulo();
            geraCodigo(rotulos.last->abre,"NADA");
           }expressao {//checa se é expressão booleana?
            if(desempilhaTipo() != 1){
               imprimeErro("Expressão não booleana");
            }
            sprintf(s,"DSVF %s", rotulos.last -> fecha);
            geraCodigo(NULL,s);


           }DO comando_sem_rotulo{
            sprintf(s,"DSVS %s", rotulos.last -> abre);
            geraCodigo(NULL,s);
            geraCodigo(rotulos.last -> fecha,"NADA");
            destroiRotulo();
         }         
;
/*-----------------FIM-WHILE-------------------------*/



/*-------------------IF-ELSE-------------------------*/

comando_condicional: if_then cond_else{
            geraCodigo(rotulos.last->fecha,"NADA");
            destroiRotulo();
         }
;


if_then:      IF
         expressao {
            if(desempilhaTipo() != 1){
               imprimeErro("Expressão não booleana");
            }
            criaRotulo();
            sprintf(s,"DSVF %s", rotulos.last -> abre);
            geraCodigo(NULL,s);
            
         } THEN
         comando_sem_rotulo 
         {
            sprintf(s,"DSVS %s", rotulos.last -> fecha);
            geraCodigo(NULL,s);
            geraCodigo(rotulos.last->abre,"NADA");
         }
;
cond_else:      ELSE {
         } comando_sem_rotulo |
         %prec LOWER_THAN_ELSE
;

/*----------------FIM-IF-ELSE-------------------------*/


/*-------------------GOTO-----------------------------*/

goto: GOTO rotulo {
        sprintf(s,"DSVR %s, %d, %d",tabela.celulas[ind_element] -> attribute -> Label.rot,
                                    tabela.celulas[ind_element] -> attribute -> Label.nl,
                                    nivel_lexico);
        geraCodigo(NULL,s);
     }
;
/*-------------------FIM-GOTO-------------------------*/

/*-----------------FIM-COMANDOS-----------------------*/



/*----------------FUNCOES-PRESET----------------------*/
preset: write | read
;
/* write */
write: WRITE ABRE_PARENTESES lista_variaveis_write FECHA_PARENTESES
;
lista_variaveis_write: lista_variaveis_write  VIRGULA imprime_variavel | imprime_variavel
;

imprime_variavel: expressao {
         geraCodigo(NULL,"IMPR");
         desempilhaTipo();
      }

;
/*read*/
read: READ ABRE_PARENTESES variavel FECHA_PARENTESES{
         geraCodigo(NULL,"LEIT");
         sprintf(s,"ARMZ %d, %d",tabela.celulas[ind_element] -> attribute -> VS.nl,tabela.celulas[ind_element] -> attribute -> VS.desl);
         geraCodigo(NULL,s);      

      }
;
/*------------------FIM-FUNCOES-PRESET----------------*/


/*------------------AUXILIARES------------------------*/
lista_idents: lista_idents VIRGULA IDENT  
            | IDENT
;
tipo        : IDENT
;

variavel: IDENT {
      if((ind_element = buscaTS(token)) < 0){
            sprintf(s,"A variável %s não foi declarada",token);
            imprimeErro(s);      
      }
   }
;

rotulo: NUMERO {
        if((ind_element = buscaTS(token)) < 0){
              sprintf(s,"O rotulo %s nao foi declarado",token);
              imprimeErro(s);      
        }
        if(tabela.celulas[ind_element] -> categoria != CAT_LABEL)
           imprimeErro("Rotulo invalido");
       }
;


usa_rotulo: rotulo DOIS_PONTOS {
               sprintf(s,"ENRT %d, %d",nivel_lexico,numeroVSTS());
               geraCodigo(tabela.celulas[ind_element] -> attribute -> Label.rot,s);

            }|
;

/*------------------FIM-AUXILIARES--------------------*/

%%
void yyerror (char *s) {
    fprintf (stderr, "%s\n", s);
}
main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos
 * ------------------------------------------------------------------- */
   iniciaTS();
   iniciaPilhas();
   yyin=fp;
   yyparse();
   return 0;
}

