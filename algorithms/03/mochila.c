
#include "mochila.h"
#include "subconjuntos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

unsigned int *g_peso;
unsigned int *g_valor;
unsigned int *g_sol;
unsigned int g_sol_valor;
unsigned int g_sol_peso;
unsigned int g_capacidade;
unsigned int g_sol_p;

void compara(unsigned int *S, unsigned int p);
void (*g_debug) (unsigned int *,unsigned int, unsigned int,unsigned int);

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
