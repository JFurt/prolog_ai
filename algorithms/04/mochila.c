
#include "mochila.h"
#include "subconjuntos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


unsigned int *g_peso;
unsigned int *g_valor;
unsigned int *g_sol,*g_vetor_indice;
double *g_vetor_razao;
unsigned int g_sol_valor;
unsigned int g_sol_peso;
unsigned int g_capacidade;
unsigned int g_sol_p;
void Quick(unsigned int inicio,unsigned int fim);

unsigned int *S;

void compara(unsigned int *S, unsigned int p);
void (*g_debug) (unsigned int *,unsigned int, unsigned int,unsigned int);

void subconjuntos_bb(unsigned int n, unsigned int p,unsigned int a, unsigned int i_peso,unsigned int i_valor);
void processa_subconjuntos_bb(unsigned int n);

void mochila_le_instancia(unsigned int *n_itens, 
                          unsigned int *capacidade,
                          unsigned int **peso,
                          unsigned int **valor){

	unsigned int j,p,v;
	scanf("%u",n_itens);
	scanf("%u",capacidade);
	*peso = (unsigned int *) malloc(*n_itens * sizeof(unsigned int));
	*valor = (unsigned int *) malloc(*n_itens * sizeof(unsigned int));
	for(unsigned int i = 0; i < *n_itens; i++){
		scanf("%u %u %u",&j,&p,&v);
		(*peso)[j] = p;
		(*valor)[j] = v;
	}
}

void mochila_ee(unsigned int n, 
                unsigned int capacidade,
                unsigned int *peso,
                unsigned int *valor,
                void debug(unsigned int *conteudo, 
                           unsigned int tamanho,
                           unsigned int peso,
                           unsigned int valor),
                unsigned int **solucao,
                unsigned int *tamanho_solucao,
                unsigned int *peso_solucao,
                unsigned int *valor_solucao){


	*solucao = (unsigned int *) malloc(n* sizeof(unsigned int));
	g_peso = (unsigned int *) malloc(n * sizeof(unsigned int));
	memcpy(g_peso,peso,n * sizeof(unsigned int));
	g_valor = (unsigned int *) malloc(n * sizeof(unsigned int));
	memcpy(g_valor,valor,n * sizeof(unsigned int));
	g_sol = (unsigned int *) malloc(n * sizeof(unsigned int));
	g_debug = debug;
	g_sol_valor = 0;
	g_sol_peso = 0;
	g_capacidade = capacidade;
	processa_subconjuntos(n,&compara);
	memcpy(*solucao,g_sol,g_sol_p*sizeof(unsigned int));
	*tamanho_solucao = g_sol_p;
	*peso_solucao =  g_sol_peso;
	*valor_solucao = g_sol_valor;
}

void mochila_bb(unsigned int n, 
                unsigned int capacidade,
                unsigned int *peso,
                unsigned int *valor,
                void debug(unsigned int *conteudo, 
                           unsigned int tamanho,
                           unsigned int peso,
                           unsigned int valor),
                unsigned int **solucao,
                unsigned int *tamanho_solucao,
                unsigned int *peso_solucao,
                unsigned int *valor_solucao){


	*solucao = (unsigned int *) malloc(n* sizeof(unsigned int));
	g_peso = (unsigned int *) malloc(n * sizeof(unsigned int));
	memcpy(g_peso,peso,n * sizeof(unsigned int));
	g_valor = (unsigned int *) malloc(n * sizeof(unsigned int));
	memcpy(g_valor,valor,n * sizeof(unsigned int));
	g_sol = (unsigned int *) malloc(n * sizeof(unsigned int));
	g_vetor_indice = (unsigned int *) malloc(n * sizeof(unsigned int));
	g_vetor_razao = (double *) malloc(n * sizeof(double));
	g_debug = debug;
	g_sol_valor = 0;
	g_sol_peso = 0;
	g_capacidade = capacidade;
	for(unsigned int i = 0; i < n;i++){
		g_vetor_indice[i] = i;
		g_vetor_razao[i] = (double) valor[i]/ (double) peso[i];
	}
	Quick(0,n-1);	
	processa_subconjuntos_bb(n);
	memcpy(*solucao,g_sol,g_sol_p*sizeof(unsigned int));
	*tamanho_solucao = g_sol_p;
	*peso_solucao =  g_sol_peso;
	*valor_solucao = g_sol_valor;
}

void processa_subconjuntos_bb(unsigned int n){
	S = (unsigned int *) malloc(n * sizeof(long int));
	subconjuntos_bb(n,0,0,0,0);
}


void subconjuntos_bb(unsigned int n, unsigned int p,unsigned int a, unsigned int i_peso,unsigned int i_valor){
	double app_peso,app_val;
	unsigned int l;

	if(i_peso <= g_capacidade && i_valor > g_sol_valor){//melhor solução
		g_sol_valor = i_valor;
		g_sol_peso = i_peso;
		g_sol_p = p;
		memcpy(g_sol,S,p*sizeof(unsigned int));
		if(g_debug != NULL)
			g_debug(S,p,i_peso,i_valor);
	}
	app_peso = i_peso;
	app_val = i_valor;
	for(int i = n-1; i >= 0; i--){
		l = g_vetor_indice[i];
		if(a <= l){
			if(app_peso + g_peso[l] > g_capacidade){
				app_val += ((double) g_capacidade - (double) app_peso)*g_vetor_razao[i];
				break;
			}
			else{
				app_val += g_valor[l];
				app_peso += g_peso[l];
			}
		}
		
	}

	if(app_val < (double) g_sol_valor){
		return ;
	}

	/*-----*/
	for(unsigned int i = a; i < n; i++){
		S[p] = i;
		if(i_peso + g_peso[i] <= g_capacidade)
			subconjuntos_bb(n,p+1,i+1,i_peso + g_peso[i],i_valor + g_valor[i]);
	}
}
	
void compara(unsigned int *S, unsigned int p){
	unsigned int s_peso = 0, s_valor = 0;
	for(unsigned int i = 0; i < p; i++){
		s_peso += g_peso[S[i]];
		s_valor += g_valor[S[i]];
	}
	if(s_peso <= g_capacidade && s_valor > g_sol_valor){
		g_sol_valor = s_valor;
		g_sol_peso = s_peso;
		g_sol_p = p;
		memcpy(g_sol,S,p*sizeof(unsigned int));
		if(g_debug != NULL)
			g_debug(S,p,s_peso,s_valor);
	}
}


void Quick(unsigned int inicio, unsigned int fim){
    
   unsigned int  meio,auxi;
   int j,i;
   double aux,pivo;
    
   i = (int) inicio;
   j = (int) fim;
    
   meio = (unsigned int) ((i + j) / 2);
   pivo = g_vetor_razao[meio];
    
   do{
      while (i < fim && g_vetor_razao[i] < pivo) i = i + 1;
      while (j > 0 && g_vetor_razao[j] > pivo) j = j - 1;
       
      if(i <= j){
         aux = g_vetor_razao[i];
         g_vetor_razao[i] = g_vetor_razao[j];
         g_vetor_razao[j] = aux;

         auxi = g_vetor_indice[i];
         g_vetor_indice[i] = g_vetor_indice[j];
         g_vetor_indice[j] = auxi;

         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
    
   if((int)inicio < j) 
	Quick(inicio, j);
   if(i < (int)fim) 
	Quick(i, fim);   
 
}


