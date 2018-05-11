#include <stdio.h>
#include <stdlib.h>
#include "smpl.h"
#include "functions.h"

/* programa simples emque cada node conta seu tempo */

int main(int argc, char *argv[]){
	static int N, token, event, r, i;

	static char fa_name[5];


   Message *m;
   int min;
/*
   double sum=0,v;
   stream(2);
   for(i = 0; i < 100; i++){
      v = normal(0,1);
      sum += v;
      printf("%lf\n",v);
   }
   printf("media %lf\n",sum/100);*/
	if(argc != 2){
		puts("Uso correto: é tempo <num_nodos>");
		exit(1);
	}
	N = atoi(argv[1]);
	smpl(0,"exemplo de simulacao");
	reset();
	stream(1);
	nodo = (tnodo *) malloc(N*sizeof(tnodo));
	for(i = 0; i< N; i++){
      /*smpl*/
		memset(fa_name,'\0',5);
		sprintf(fa_name, "%d", i);
		nodo[i].id = facility(fa_name,1);
      
      /*bla*/
      nodo[i].LSB = 0;
      nodo[i].vLCB = malloc(N*sizeof(int));
      memset(nodo[i].vLCB,0,N*sizeof(int));
      nodo[i].vBC= malloc(N*sizeof(int));
      memset(nodo[i].vBC,0,N*sizeof(int));
      nodo[i].buffer.counter=0;
	}
	for(i=0;i<N;i++){
		schedule(send,TIME_SEND,i);
	}

	while(time() < 180.0){
		cause(&event, &token);
		switch(event){
         case send:
            if(1){ //probabilidade

               /* atualizando BC[i] */
               nodo[token].vBC[token]++;

               /*Faz a mensagem*/
               Message *m = malloc(sizeof(Message));
               m -> sender = token;
               m -> BC = nodo[token].vBC[token];
               m -> LCB = nodo[token].vLCB[token];
               m -> read = UNREAD;

               //LCB

               for(i=0;i<N;i++){
                  send_msg(m,token,i);
               }
               free(m);
            }

            schedule(send,TIME_SEND,token);
            break;
         case recv:

            /* Selecionando a nova mensagem */
            m = nodo[token].buffer.first_msg;
            for(i=0;i<nodo[token].buffer.counter-1;i++){
               if(m -> read == READ)
                  m = m ->next_msg;
               else{
                  m -> read = READ;
                  break;
               }
            }
              
            /* implementar timesilence 


            */
          
            /* Atualiza proprio BC */
            nodo[token].vBC[token] = MAX(nodo[token].vBC[token],m -> BC);
            nodo[token].vBC[m->sender] = m -> BC;

            min = nodo[token].vBC[token];
            for(i=0;i<N;i++){
               if(nodo[token].vBC[i] < min)
                  min = nodo[token].vBC[i]; 
            }

            nodo[token].vLCB[token] = min;

            nodo[token].vLCB[m->sender] = m -> LCB;

            min = m -> LCB;
            for(i=0;i<N;i++){
               if(nodo[token].vLCB[i] < min)
                  min = nodo[token].vLCB[i]; 
            }
            
            printf("%d %d - ",token,m -> sender);
            for(i=0;i<N;i++){
                  printf("<%d,%d> ",nodo[token].vBC[i],nodo[token].vLCB[i]);
            }
            printf("\n");
            
            if(min!=nodo[token].LSB){
               nodo[token].LSB = min;
               deliver_msgs(token);
            }
            
            break;
			
		}
	}

}
