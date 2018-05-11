#include "functions.h"
#include "smpl.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void send_msg(Message *m,int sender, int receiver){ // ARRUAMRASDFSDFSDF
   Message *ml = malloc(sizeof(Message));
   memcpy(ml,m,sizeof(Message));
   /*Escreve a mensagem no buffer */
   ml -> next_msg = NULL;
   if(nodo[receiver].buffer.counter==0){
      ml -> prev_msg = NULL;
      nodo[receiver].buffer.first_msg = ml;
      nodo[receiver].buffer.last_msg = ml;
   }else{
      nodo[receiver].buffer.last_msg -> next_msg = ml;
      ml -> prev_msg = nodo[receiver].buffer.last_msg;
      nodo[receiver].buffer.last_msg = ml;
   }
   nodo[receiver].buffer.counter++;

   /* evento */
   if(sender!= receiver)
      schedule(recv,TIME_LAT,receiver);
   else
      ml -> read = READ;
}

void deliver_msgs(int token){
   int i;
   Message *m = nodo[token].buffer.first_msg,*mt;
   while(m){
      mt = m -> next_msg;
      if(m->BC <= nodo[token].LSB){
         deliver(token,m);

         excluiMensagem(token,m);

      }
      m = mt;
   }
}



void excluiMensagem(int token,Message *m){
   if(m -> next_msg)
      m -> next_msg -> prev_msg = m -> prev_msg;

   if(m -> prev_msg)
      m -> prev_msg -> next_msg = m -> next_msg;

   if(m==nodo[token].buffer.first_msg)
      nodo[token].buffer.first_msg = m -> next_msg;

   if(m==nodo[token].buffer.last_msg)
      nodo[token].buffer.last_msg = m -> prev_msg;

   nodo[token].buffer.counter--;

   free(m);
}

void deliver(int token, Message *m){
   printf("O processo %d entregou a mensagem, cujo BC eh %d, enviada por %d.\n",token,m->BC , m->sender);
}


