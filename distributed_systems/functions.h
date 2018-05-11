#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define TIME_SEND 30.0
#define READ 1
#define UNREAD 0
#define TIME_LAT 1.0
#define send 3
#define recv 4

#define MAX(a,b) (a>b?a:b)

typedef struct Message{
	int sender;
	int BC;
   int LCB;
   int read; //marca se a msg já foi lida
	struct Message *next_msg;
	struct Message *prev_msg;
}Message;

typedef struct Buffer{
	int counter;
	Message *first_msg;
	Message *last_msg;
}Buffer;

typedef struct tnodo{
	int id;
   int *vBC;
   int LSB;
   int *vLCB;
   int sentCounter;
   int recvCounter;
	Buffer buffer;
}tnodo;

tnodo *nodo;
int N;

/*
int msg_cont;
int *last_state;
double *last_time;
double lat_soma;
int lat_cont;
double lat_max;
*/

void send_msg(Message *m,int sender, int receiver);
void deliver_msgs(int token);
void deliver(int token, Message *m);
void excluiMensagem(int token,Message *m);

#endif
