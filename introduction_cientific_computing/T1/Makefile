CC= gcc
CFLAGS= -c -O3
LDFLAGS=  -O3
OBJ= main.o
LIB = -lm

all :  pdeSolver

pdeSolver : $(OBJ)
	$(CC) $(OBJ) -o pdeSolver	$(LIB)
main.o : main.c
	$(CC) $(CFLAGS) main.c $(LIB)
clean : 
	rm -f $(OBJ) *~ pdeSolver out.txt plot.gp
