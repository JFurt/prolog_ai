#include "subconjuntos.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int *S;

	
void subconjuntos(unsigned int n, unsigned int p,unsigned int a, void processa(unsigned int *, unsigned int));
//void escreve(unsigned int *S, unsigned int p);


void processa_subconjuntos(unsigned int n, 
                           void processa(unsigned int *, unsigned int)){
	S = (unsigned int *) malloc(n * sizeof(long int));
	subconjuntos(n,0,0,processa);
}


void subconjuntos(unsigned int n, unsigned int p,unsigned int a, void processa(unsigned int *, unsigned int)){
	if(processa != NULL)
		processa(S,p);
	for(unsigned int i = a; i < n; i++){
		S[p] = i;
		subconjuntos(n,p+1,i+1,processa);
	}
}
	
/*void escreve(unsigned int *S, unsigned int p){
	for(long int i = 0; i < p ; i++)
		printf("%u ",S[i]);
	printf("\n");
}	

int main(){
	processa_subconjuntos(5,&escreve);
}*/
