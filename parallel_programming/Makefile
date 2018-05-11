CC= gcc
CFLAGS= -c -Wall -Winline -Wshadow -fopenmp -O3
LDFLAGS=  -Wall -Winline -Wshadow -fopenmp -O3
OPT= 
OBJ= main.o
LIB = -L/usr/local/lib  -lm 

all :  solver
	mkdir -p Resultados

solver : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(OPT) -o rbgs	$(LIB)
main.o : main.c
	$(CC) $(CFLAGS) $(OPT) main.c $(LIB)
clean : 
	rm -f $(OBJ) *~ rbgs time_mean  mean*.txt out.txt -r Resultados


