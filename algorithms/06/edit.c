
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "edit.h"
#define MAX(A,B) A > B ? A : B
#define MIN(A,B) A > B ? B : A


void SCMcaller(char **A,unsigned int szA, char **B,unsigned int szB, unsigned int **C);
void SCM(char **A,unsigned int szA, char **B,unsigned int szB,unsigned int **ans,unsigned int *szAns);
unsigned int solve(char **A,char **B,unsigned int **C,unsigned int N, unsigned int M,unsigned int **ans);
unsigned int NEWLINE;

void diff(char **buffer1, int num_linhas1, char **buffer2, int num_linhas2){
	unsigned int i,j,a1,a2,c,i1,d1,d2;
	unsigned int szAns, **ans;
	int mx = MAX(num_linhas1+1,num_linhas2+1);
	ans = malloc(mx*sizeof(unsigned int *));
	for(i = 0; (int) i < mx; i++)
		ans[i] = malloc(2*sizeof(unsigned int));
	SCM(buffer1,(unsigned int) num_linhas1,buffer2, (unsigned int) num_linhas2, ans,&szAns);
	mx = MAX(num_linhas1,num_linhas2);
	a1=1;a2=1;
	for(i=0;i<szAns;i++){

		d1 = ans[i][0] - a1;
		d2 = ans[i][1] - a2;
		i1=abs(d1-d2);
		c = MIN(d1,d2);
		if(d1 < d2){
			if(a1==0)
				a1=1;
			else if(a1 == num_linhas1 +1)
				a1-=2;
			else
				a1-=1;
			a2 -= a2 > 0 ? 1 : 0;
			for(j=0;j<i1;j++)
				printf("%da%d\n> %s",a1+1,j+a2+1,buffer2[j+a2]);
		}
		else if(d1 > d2){
			a1= a1==0?1:a1;
			for(j=0; j<i1;j++)
				printf("%dd%d\n< %s",j+a1,a2-1,buffer1[j+a1-1]);
		}

		a1 = a1 == 0 ? 1 : a1;
		a2 = a2 == 0 ? 1 : a2;
		if(d1>d2){
			for(j=i1+1;j<d1;j++){
				printf("%dc%d\n< %s---\n> %s",a1+j,a2,buffer1[a1+j-1],buffer2[a2-1]);
				a2++;
			}
		}
		else if(d2>d1){
			for(j=i1;j<d2-1;j++){
				printf("%dc%d\n< %s---\n> %s",a1,a2+j,buffer1[a1-1],buffer2[a2+j-1]);
				a1++;
			}		
		}
		else{
			for(j=i1;j<d2;j++){
				printf("%dc%d\n< %s---\n> %s",a1,a2+j,buffer1[a1-1],buffer2[a2+j-1]);
				a1++;
			}		
		}
		a1 = ans[i][0]+1;
		a2 = ans[i][1]+1;
	}
	if(NEWLINE)
		printf("\\ No newline at end of file\n");

	free(ans);


}


void SCM(char **A,unsigned int szA, char **B,unsigned int szB, unsigned int **ans, unsigned int *szAns){
	unsigned int **C,i;
	C = malloc((szA+1)*sizeof(unsigned int *));
	for(i=0;i<=szA;i++)
		C[i] = malloc((szB+1)*sizeof(unsigned int));
	SCMcaller(A,szA,B,szB,C);
	
	*szAns = solve(A,B,C,szA+1,szB+1,ans);

	for(i=0;i<=szA;i++)
		free(C[i]);
	free(C);
}

unsigned int solve(char **A,char **B,unsigned int **C,unsigned int N, unsigned int M,unsigned int **ans){
	

	unsigned int i,j = 0,cont=0;
	unsigned int **tmp;
	int mx = MAX(N+1,M+1);
	unsigned int lastj = M-1;
	tmp = malloc(mx*sizeof(unsigned int *));
	for(i = 0; (int) i < mx; i++)
		tmp[i] = malloc(2*sizeof(unsigned int));
	i = N;
	while(i >= 1){
		if(j==0){
			j=lastj;
			i--;
		}
		if(i==0)
			break;
		if( (C[i][j] > C[i][j-1] && C[i][j] > C[i-1][j] && j > 1) || j==1 && !strcmp(A[i-1],B[j-1])){
			tmp[cont][0] = i;
			tmp[cont++][1] = j;
			i--;
			lastj = j;
		}
		j--;
	}
	

	for(i=0;i<cont;i++){
		ans[cont-1-i][0]=tmp[i][0];
		ans[cont-1-i][1]=tmp[i][1];
	}
	ans[cont][0]=N;	
	ans[cont++][1]=M;

	for(i = 0; (int) i < mx; i++)
		free(tmp[i]);
	free(tmp);

	return cont;

}

void SCMcaller(char **A,unsigned int szA, char **B,unsigned int szB, unsigned int **C){
	unsigned int i,j;
	for(i=0;i<=szA;i++)
		C[i][0]=0;
	for(i=0;i<=szB;i++)
		C[0][i]=0;
	
	for(i=1;i<=szA;i++){

		for(j=1;j<=szB;j++){
			if(!strcmp(A[i-1],B[j-1]))
				C[i][j] = C[i-1][j-1] +1;
			else
				C[i][j] = C[i-1][j] > C[i][j-1] ? C[i-1][j] : C[i][j-1];
		}
	}
}

char **le_arquivo_para_buffer(FILE *entrada, int *n){
	struct stat buff;
	fstat(fileno(entrada),&buff);

	char unsigned *S = malloc((unsigned int) buff.st_size);
	memset(S,0,(unsigned int) buff.st_size);
	char **arquivo = malloc(sizeof(char *));
	unsigned int i=0,c=0,k;
	NEWLINE=0;
	fread(S,(unsigned int) buff.st_size,1,entrada);
	while(S[c] != '\0'){
		if(c==buff.st_size)
			break;
		k = c;
		while(S[c]!='\n' && S[c] != '\0' && S[c] != EOF && (unsigned int) c < (unsigned int) buff.st_size	)
			c++;
		arquivo = realloc(arquivo,(i+1)*sizeof(char *));
		arquivo[i] = malloc((c-k + 2)*sizeof(char));
		memset(arquivo[i],0,(c-k + 2));
		
		memcpy(arquivo[i],S+k,c-k + 1);
		if(arquivo[i][c-k] != '\n'){
			arquivo[i][c-k] = '\n';
			NEWLINE=1;
			c++;
			i++;
			break;
		}
		c++;
		i++;

		
	}
	free(S);
	*n = (int) i;
	return arquivo;

}


void libera_buffer(char **buffer, int n){
	unsigned int i;
	for(i = 0; (int) i < n; i++)
		free(buffer[i]);
	free(buffer);


}

