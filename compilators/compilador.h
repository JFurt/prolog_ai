/* -------------------------------------------------------------------
 *            Arquivo: compilaodr.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, protótipos e vaiáveis globais do compilador
 *
 * ------------------------------------------------------------------- */
#ifndef _COMPILADOR_H_
#define _COMPILADOR_H_
#define TAM_TOKEN 16
#define TAM_ROTULO 10

typedef enum simbolos { 
  simb_program, simb_var, simb_begin, simb_end, 
  simb_identificador, simb_numero,
  simb_read, simb_write,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses,
  simb_mais, simb_menos, simb_or, simb_vezes, simb_divididos, simb_and,
  simb_maior, simb_menor, simb_maior_igual, simb_menor_igual, simb_igual, simb_diferente,
  simb_while, simb_do, simb_procedure, simb_function, simb_if, simb_then, simb_else, simb_label,simb_goto,
} simbolos;



/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;
extern int l_element;


simbolos simbolo, relacao;
char token[TAM_TOKEN];
int desloc;
int l_element;
int nivel_lexico;
int val;
int var_ref;
int num_vars_aux;
int num_par;
int parameter_lock;
int pas_param;

char s[20];

#endif

