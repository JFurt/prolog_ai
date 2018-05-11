#include "cv.h"
#include "permutacoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int best_p_val;
unsigned int *best_p;
unsigned int **g_distancia;
unsigned int N;
unsigned int *p;
unsigned int *usados;
void (*g_debug)(unsigned int n,unsigned int *percurso,unsigned int d);
void cv_compara(unsigned int *p, unsigned int n);
unsigned int cv_heuristica(unsigned int *p, unsigned int n,unsigned int d);
void processa_permutacoes_bb(unsigned int n, void processa(unsigned int *, unsigned int));
void todas_permutacoes_bb(unsigned int n, unsigned int d,void processa(unsigned int *, unsigned int));


unsigned int cv_ee(unsigned int n, unsigned int **distancia, void debug(unsigned int n,unsigned int *percurso, unsigned int d),unsigned int *percurso){
	
	g_distancia = distancia;
	g_debug = debug;
	best_p = percurso;
	processa_permutacoes(n,cv_compara);
	memcpy(percurso,best_p,n*sizeof(unsigned int));

	return best_p_val;


}

void cv_compara(unsigned int *p, unsigned int n){
	unsigned int res,i;
	res = 0;
	for(i = 0; i < n-1; i++){

		if(g_distancia[p[i]][p[i+1]] == cv_infinito)
			return ;
		res += g_distancia[p[i]][p[i+1]];
	}
	if(g_distancia[p[n-1]][p[0]] == cv_infinito)
		return ;
	res += g_distancia[ p[n-1] ][ p[0] ];
	if(best_p_val == cv_infinito || res < best_p_val){
		best_p_val = res;
		memcpy(best_p,p,n*sizeof(unsigned int));
		if(g_debug != NULL)
			g_debug(n,p,res);
	}
}

void cv_le_instancia(unsigned int *n, unsigned int ***matriz){
	unsigned int i,j,d,x;
	char c;
	scanf(" %u",n);
	(*matriz) = (unsigned int **) malloc((*n)*sizeof(unsigned int *));
	for(i = 0; i < *n; i++){
		(*matriz)[i] = malloc((*n)*sizeof(unsigned int));
		for(j = 0; j < *n; j++)
			if(i == j)
				(*matriz)[i][j] = 0;
			else
				(*matriz)[i][j] = cv_infinito;
	}
	while(scanf("%u %u %u",&i,&j,&d)){
		c = getchar();
		(*matriz)[i][j] = d;
		c = getchar();
		if(c == EOF || c == '\n')
			break;
		ungetc(c,stdin);
	}		
		
		
}

void cv_libera_instancia(unsigned int n, unsigned int **matriz){
	unsigned int i;
	for(i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);
}
	

unsigned int cv_bb(unsigned int n, 
                   unsigned int **distancia, 
                   void debug(unsigned int n,
                              unsigned int *percurso, 
                              unsigned int d),
                   unsigned int *percurso){

	g_distancia = distancia;
	g_debug = debug;
	best_p = percurso;
	processa_permutacoes_bb(n,cv_compara);
	memcpy(percurso,best_p,n*sizeof(unsigned int));

	return best_p_val;	



}	

void processa_permutacoes_bb(unsigned int n, void processa(unsigned int *, unsigned int)){
	p = malloc(n*sizeof(int));
	usados = malloc(n*sizeof(int));
	N = n;
	unsigned int i;
	for(i = 0; i < n; i++)
		usados[i] = 0;
	usados[0] = 1;
	p[0] = 0;
	todas_permutacoes_bb(1,0,processa);
}

void todas_permutacoes_bb(unsigned int n, unsigned int d,void processa(unsigned int *, unsigned int)){
	unsigned int i,dist;
	if(n == N)
		return processa(p,N);
	else if(cv_heuristica(p,n,d))
		return ;
	for(i = 0; i < N; i++)
		if(usados[i] == 0){
			usados[i] = 1;
			p[n] = i;
			dist = g_distancia[p[n-1]][i];
			if(dist != cv_infinito && (best_p_val == cv_infinito || dist + d <= best_p_val))//PODA
				todas_permutacoes_bb(n + 1,d + dist, processa);
			usados[i] = 0;
		}
}

unsigned int cv_heuristica(unsigned int *p, unsigned int n,unsigned int d){
	unsigned int soma = 0, min = 0,tmp,c_grau_in,c_grau_out;
	unsigned int arco_in,arco_out;

	for(unsigned int i = 0; i < N; i++){
		if(usados[i] == 0){
			c_grau_in = 0;
			c_grau_out = 0;
			min = cv_infinito;
			for(unsigned int j = 0; j < N; j++){
				tmp = g_distancia[i][j];
				if(min == cv_infinito || min > tmp)
					min = tmp;
				/*achando arcos*/
				if(tmp != cv_infinito && tmp != 0){
					arco_out = 1;
				}else
					arco_out = 0;
				tmp = g_distancia[j][i];
				if(tmp != cv_infinito && tmp != 0){
					arco_in = 1;	
				}else
					arco_in = 0;
				/*-------------*/		

				/*O arco é util?*/
				if(usados[j]){
					if(arco_in && j == p[n - 1])
						c_grau_in++;
					if(arco_out && j == p[0])
						c_grau_out++;
				}else{
					if(arco_in)
						c_grau_in++;
					if(arco_out)
						c_grau_out++;
				}
				/*-------------*/

			}
			if(c_grau_in == 0 || c_grau_out == 0){
					/*printf("(%u",p[0]);
					for(unsigned int l = 1 ; l < n ; l++)
						printf(", %u",p[l]);
					printf(") - ");	
					printf("%u %u %u %u\n",c_grau_in,c_grau_out,n,i);*/
				return 1; //PODA POR IMPOSSIBILIDADE DE GERAR CIRCUITO EULERIANO
			}
			soma += min;
		}
	}
	if(best_p_val != cv_infinito && best_p_val <= min + d) 
		return 1; //PODA POR QUE CUSTARÁ NO MÍNIMO MAIS CARO
 
	return 0;

}


