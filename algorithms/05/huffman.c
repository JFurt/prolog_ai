#include "huffman.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



struct Bit{
	unsigned int value: 1;
};
typedef struct Bit bit;

typedef bit *bits;

typedef struct Cell{
	unsigned int cont;
	bit *bits;
	bit *out;
	unsigned int out_size;
}Cell;

typedef struct Cell *Table;

typedef struct Node{
	Cell *content;
	struct Node *left;
	struct Node *right;

}Node;

typedef struct Tree{
	unsigned int value;
	Node *root;
}Tree;

	

unsigned int partition(Tree **vTrees, int ini,  int end);
void quick_sort(Tree **vTrees, int ini,int end);
void create_forest(Tree **vTrees, Table *table, unsigned int size);
unsigned int huff(Table *table, unsigned int b,unsigned int size_table);
unsigned int equal_bit(bits *c1,bits *c2,unsigned int b);
void insert(Tree **vTrees, Tree *newTree, unsigned int size);
void code_rec(Node *n, bits V,unsigned int h);
void generate_code(Node *n,unsigned int b);
unsigned int print_out_file(FILE *in, FILE *out, Table *table, unsigned int b, unsigned int size_table,fpos_t *pos);
unsigned char *monta_str_out(Cell c, unsigned int b, unsigned char *s,unsigned int *size);
unsigned int le_bits(FILE *in, Cell *N, Cell *Resto,unsigned int offset,unsigned int b, unsigned int *size_resto);
void le_tabela(Table *table, FILE *in,unsigned int b, unsigned int size_table);
void translate(FILE *in,FILE *out,Table *table, unsigned int b, unsigned int size_table,unsigned char *quebra_bin,unsigned char *quebra_in);

FILE *compacta(FILE *entrada, FILE *saida, unsigned int b){
	fpos_t pos;
	Table table = malloc(sizeof(Cell));	
	unsigned int i,size_table = 0;	
	Cell *N = malloc(sizeof(Cell));
	Cell *R = malloc(sizeof(Cell));
	unsigned int off,size_resto,x;


	fgetpos(entrada,&pos);

	N -> bits = malloc(b*sizeof(bit));
	R -> bits = malloc(b*sizeof(bit));


	off = 0;
	while(le_bits(entrada,N,R,off,b,&size_resto)){
		//processa
		i = 0;
		while(i < size_table && !equal_bit(&(N->bits),&(table[i].bits),b))
			i++;
		if(i == size_table){
			size_table++;
			table = realloc(table,size_table*sizeof(Cell));
			table[i].bits = malloc(b*sizeof(bit));
			memcpy(table[i].bits,N -> bits,b*sizeof(bit));
			table[i].cont = 1;
		}else
			table[i].cont++;
		memcpy(N -> bits, R -> bits, size_resto* sizeof(bit));
		off = size_resto;
	}


	huff(&table,b,size_table);


	fsetpos(entrada,&pos);


	/*arquivo de entrada quebrado*/
	if(size_resto){
		fprintf(saida,"i");
		for(i = 0; i < size_resto; i++)
			fprintf(saida,"%u",R -> bits[i].value);
		fprintf(saida,"\n");

	}
	/*fim do ajuste*/

	fgetpos(saida,&pos);

	/*imprimindo lixo*/
	x = 0;
	for(i = 0; i < size_table;i++)
		x += table[i].cont*table[i].out_size;
	if(x%8){
		fgetpos(saida,&pos);
		for(i=0;i<x%8+2;i++)
			fprintf(saida,"t");
	}
	/*fim*/
	
	print_out_file(entrada,saida,&table,b,size_table,&pos);


	fflush(saida);
}


unsigned int print_out_file(FILE *in, FILE *out, Table *table, unsigned int b, unsigned int size_table,fpos_t *pos){
	unsigned int i,j,size;
	unsigned char *s;
	unsigned int cont_out, end=0; 
	Cell c_out;
	c_out.bits = malloc(sizeof(bit));
	Cell *N = malloc(sizeof(Cell));
	Cell *R = malloc(sizeof(Cell));
	unsigned int off,size_resto;
	N -> bits = malloc(b*sizeof(bit));
	R -> bits = malloc(b*sizeof(bit));




	fprintf(out,"%u %u\n",b,size_table);
	/*imprimindo tabela*/
	for(i = 0; i < size_table; i++){
		s = malloc((b/8 + 1 + (*table)[i].out_size + 4)*sizeof(char));
		monta_str_out( (*table)[i], b,s,&size);
        fprintf(out,"%u ",(*table)[i].out_size);
        fwrite(s,1,size,out);
		free(s);
	}	
	/*fim*/


	/*imprimindo arquivo*/
	off = 0;
	while(1){
		cont_out = 0;
		while(cont_out == 0 || cont_out %8){
			if(!le_bits(in,N,R,off,b,&size_resto)){
				end = 1;
				break;
			}
			//processa
			i = 0;
			while(i < size_table && !equal_bit(&(N -> bits),&( (*table)[i].bits ),b))
				i++;
			c_out.bits = realloc(c_out.bits,(cont_out + (*table)[i].out_size + 1)*sizeof(bit));
			for(j = 0; j < (*table)[i].out_size; j++){
			        c_out.bits[cont_out + j].value = (*table)[i].out[j].value;    
			}
		        cont_out += (*table)[i].out_size;				

			memcpy(N -> bits, R -> bits, size_resto* sizeof(bit));
			off = size_resto;
		}
		s= malloc((cont_out/8 + 2)*sizeof(char));
		for(i = 0; i < cont_out/8 ; i++){
		    s[i] = 0;
		    for(j = 0 ; j < 8; j++)
		        s[i] = s[i] | (c_out.bits[i*8 + j].value << (7-j));
		}
		if(cont_out/8)
			fwrite(s,1,cont_out/8,out);
	  free(s);
		if(end)
			break;
	}
	/*fim da impressão do arquivo*/

	/*arquivo quebrado*/
	if(cont_out%8){
		fsetpos(out,pos);
		fprintf(out,"o");
		for(i = (cont_out/8)*8; i < cont_out; i++)
			fprintf(out,"%u",c_out.bits[i].value);
		fprintf(out,"\n");
	}
	/*fim da quebra do arquivo de saida*/

}

unsigned int le_bits(FILE *in, Cell *N, Cell *Resto,unsigned int offset,unsigned int b, unsigned int *size_resto){
	unsigned int n = b/8;
	unsigned int cont_N = offset, cont_resto = 0,j;	
	unsigned char *buf = malloc(sizeof(char));
	while(cont_N < b){
		if(!fread(buf,1,1,in))
			return 0;
		for(j = 0; j < 8; j++){
			if(cont_N+ j < b)
				N -> bits[cont_N+ j].value = ((*buf >> (7-j)) & 1);
			else
				Resto -> bits[cont_resto++].value = ( (*buf >> (7-j)) & 1);
		}
		cont_N = cont_resto > 0 ? b : cont_N + 8 ;
	}
	*size_resto = cont_resto;
	free(buf);
	return cont_N;


}


unsigned char *monta_str_out(Cell c, unsigned int b, unsigned char *s,unsigned *size){
	int i,n,no,j;
	n = b/8;
	for(i = 0; i < n; i++){
		s[i] = 0;
		for(j = 0; j < 8; j++)
			s[i] = s[i] | (c.bits[i*8 + j].value << (7-j));
	}
	if(b%8){
		s[n] = 0;
		for(i = 0; i < b%8;i++)
			s[n] = s[n] | (c.bits[n*8 + i].value << (7-i));
		no = ++n + c.out_size/8;
	}else{
		no = n + c.out_size/8;
	}
	for(i = n; i < no; i++){
		s[i] = 0;
		for(j = 0; j < 8; j++)
			s[i] = s[i] | (c.out[(i-n)*8 + j].value << (7-j));
	}
	if(c.out_size%8){
		s[no] = 0;
		for(i = 0; i < (c.out_size%8);i++)
			s[no] = s[no] | (c.out[(no-n)*8 + i].value << (7-i));
		s[no+1] = '\n';
        *size = no+2;
	}
	else{
		s[no] = '\n';
        *size = no+1;
	}
}

unsigned int huff(Table *table, unsigned int b,unsigned int size_table){
	Tree **vTrees = malloc(size_table*sizeof(Tree *));
	Tree *newTree;
	unsigned int nSize = size_table,ind,i;
	create_forest(vTrees,table,size_table);
	quick_sort(vTrees,0,size_table-1);
	while(nSize > 1){
		newTree = malloc(sizeof(Tree));
		newTree -> root = malloc(sizeof(Node));
		newTree -> root -> left = vTrees[0] -> root;
		newTree -> root -> right = vTrees[1] -> root;
		newTree -> value = vTrees[0] -> value + vTrees[1] -> value;
		remove_start(vTrees,nSize);
		nSize--;
		insert(vTrees,newTree,nSize);
	}
	generate_code(vTrees[0] -> root,b);


}



void generate_code(Node *n,unsigned int b){
	bits V;
	V = malloc(4*b*sizeof(bit));
	V[0].value = 0;
	code_rec(n -> left,V,1);
	V[0].value = 1;
	code_rec(n -> right,V,1);
    free(V);
}

void code_rec(Node *n, bits V,unsigned int h){
    unsigned int i;
	if(n -> content){
		n -> content -> out = malloc(h*sizeof(bit));
		memcpy(n -> content -> out,V,h*sizeof(bit));
		n -> content -> out_size = h;
		return;
	}
	V[h].value = 0;
	code_rec(n -> left,V,h+1);
	V[h].value = 1;
	code_rec(n -> right,V,h+1);
}




void remove_start(Tree **vTrees,unsigned int size){
	unsigned int i;
	free(vTrees[0]);
	free(vTrees[1]);
	for(i = 2; i < size ; i++)
		vTrees[i-2] = vTrees[i];

}

void insert(Tree **vTrees, Tree *newTree, unsigned int size){
	unsigned int i=0,j;
	while(i < (size - 1) && vTrees[i] -> value < newTree -> value)
		i++;
	for(j = size-1; j > i; j--)
		vTrees[j] = vTrees[j-1];
	vTrees[i] = newTree;
}

void create_forest(Tree **vTrees, Table *table, unsigned int size){
	unsigned int i;
	for(i = 0;i < size; i++){
		vTrees[i] = malloc(sizeof(Tree));
		vTrees[i] -> root = malloc(sizeof(Node));
		vTrees[i] -> root -> content = &((*table)[i]);
		vTrees[i] -> value = (*table)[i].cont;
	}

}

void quick_sort(Tree **vTrees, int ini,int end){
	unsigned int q;
	if(ini < end){
		q = partition(vTrees,ini,end);
		quick_sort(vTrees,ini,q-1);
		quick_sort(vTrees,q+1,end);
	}
}
		
unsigned int partition(Tree **vTrees,  int ini, int end){
	int p,i,j;
	Tree *x,*tmp;
	x = vTrees[end];
	i = ini-1;
	for(j = ini; j < end; j++){
		if(vTrees[j] -> value <= x -> value){
			i++;
			tmp = vTrees[j];
			vTrees[j] = vTrees[i];
			vTrees[i] = tmp;
		}
	}
	vTrees[end] = vTrees[i+1];
	vTrees[i+1] = x;
	return i+1;
}






unsigned int equal_bit(bits *c1, bits *c2,unsigned int b){
	unsigned int i;
	for(i = 0; i < b ; i++)
		if((*c1)[i].value != (*c2)[i].value)
			return 0;
	return 1;
}




FILE *descompacta(FILE *entrada, FILE *saida){
	unsigned char *s,*quebra_bin = NULL,*quebra_in=0;
	unsigned int b, size_table,i,j;
	Table table;

	s = malloc(1000*sizeof(char));
	fgets(s,1000,entrada);
	if(s[0] == 'i'){
			//arquivo quebrado
		quebra_in = malloc(1000*sizeof(char));
		i = 1;
		while(s[i] != '\n' && s[i] != '\0')
			quebra_in[i-1] = s[i++];
		quebra_in[i-1] = '\0';
		fgets(s,1000,entrada);
	}
	if(s[0] == 'o'){
			//saida quebrada
		quebra_bin = malloc(12*sizeof(char));
		i = 1;
		while(s[i] != '\n' && s[i] != '\0')
			quebra_bin[i-1] = s[i++];
		quebra_bin[i-1] = '\0';
		fgets(s,1000,entrada);

	}
	sscanf(s,"%u %u",&b,&size_table);
	free(s);

	table = malloc(size_table*sizeof(Cell));
	le_tabela(&table,entrada,b,size_table);


	translate(entrada,saida,&table,b,size_table,quebra_bin,quebra_in);

	fflush(saida);
}

void translate(FILE *in,FILE *out,Table *table, unsigned int b, unsigned int size_table,unsigned char *quebra_bin,
		unsigned char *quebra_in){

	unsigned int cont_N,end,off=0,size_resto,end_file,i,j,k,cont_s=0,cont_s_bit=0,ind,mx_out=0,size_N,x;
	unsigned char *s = malloc(sizeof(char));
	Cell *N = malloc(sizeof(Cell)),*R = malloc(sizeof(Cell));
	
	for(i=0;i<size_table;i++)
		if(mx_out < (*table)[i].out_size)
			mx_out = (*table)[i].out_size;

	N -> bits = malloc( (mx_out+b+1)*sizeof(bits));
	R -> bits = malloc(8*sizeof(bits));


	size_N = 0;
	while(1){
		cont_N = 0;
		end = 0;
		end_file=0;
		while(1){
			if(size_N <= cont_N){
				if((x = le_bits(in,N,R,size_N,8+size_N,&size_resto)) == 0){
					if(quebra_bin){
						i=0;
						while(quebra_bin[i] != '\0' && quebra_bin[i] != '\n')
							N -> bits[size_N+i].value = (quebra_bin[i++] - 48);
						size_resto = 0;
						size_N += i;
						free(quebra_bin);
						quebra_bin = NULL;

					}else{
						end_file = 1;
						break;
					}
					
				}else{
					size_N = x;
				}
				for(i=size_N;i<size_N+size_resto;i++)
					N -> bits[i].value = R -> bits[i-size_N].value;
				size_N += size_resto;
			}else{
				size_resto = 0;

			}
			cont_N +=8;
			//processa
			for(k=0;k<=size_N;k++){
				i = 0;
				if(k > 0){
					while(i < size_table && (k != (*table)[i].out_size || !equal_bit(&(N->bits),&( (*table)[i].out ),k)))
						i++;
					if(i < size_table){
						end=1;
						ind = i;
						break;
					}
				}
			}
//			memcpy(N -> bits,R -> bits,size_resto*sizeof(bit));
			if(end)
				break;
		}
		if(end_file)
			break;

		for(j = 0; j < (size_N-k%8); j++)
			N -> bits[j].value = N -> bits[k+j].value;
		size_N -= k;


		for(i = 0; i < b ; i++){
				s[cont_s] = s[cont_s] | ((*table)[ind].bits[i].value << (7-cont_s_bit));
				if(cont_s_bit == 7){
					cont_s++;
					s = realloc(s,cont_s*sizeof(char));
					s[cont_s] = 0;
					cont_s_bit = 0;
				}
				else
					cont_s_bit++;
		}
		if(!cont_s_bit){
			fwrite(s,1,cont_s,out);
		 	free(s);
			s = malloc(sizeof(char));
			cont_s = 0;
			s[cont_s] = 0;
		}
	}
	if(quebra_in){
		for(i = cont_s_bit; i < 8;i++)
			s[cont_s] |= (quebra_in[i-cont_s_bit] - 48) << (7-i);
		fwrite(s,1,cont_s+1,out);
	}

	

}

void le_tabela(Table *table, FILE *in,unsigned int b, unsigned int size_table){
	unsigned int i, o = 0,size_resto,size_out;
	unsigned char *s,c;
	Cell *N = malloc(sizeof(Cell)), *R = malloc(sizeof(Cell)), *O = malloc(sizeof(Cell));
	N -> bits = malloc(b*2*sizeof(bit));
	O -> bits = malloc(b*2*sizeof(bit));
	R -> bits = malloc(b*2*sizeof(bit));
	for(i = 0; i < size_table;i++){
		fscanf(in,"%u",&size_out);
		c = fgetc(in);
		le_bits(in,N,R,o,b,&size_resto);
		le_bits(in,O,R,o,size_out,&size_resto);
		(*table)[i].bits = malloc(b*sizeof(bit));
		memcpy((*table)[i].bits,N -> bits,b*sizeof(bit));
		(*table)[i].out = malloc(size_out*sizeof(bit));
		memcpy((*table)[i].out,O -> bits,size_out*sizeof(bit));
		(*table)[i].out_size = size_out;
	}
	fgetc(in);
}






/*int main(){
	FILE *f = fopen("teste","r");
	FILE *f1 = fopen("teste_out","w");
	compacta(f,f1,9);	
	fclose(f1);
	FILE *f3 = fopen("teste2","w");
	FILE *f2 = fopen("teste_out","r");
	descompacta(f2,f3);
//	fclose(f);
	fclose(f2);
	fclose(f3);
}*/
