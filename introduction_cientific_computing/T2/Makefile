CC= gcc
CFLAGS= -c -march=native -mavx -O3
LDFLAGS= -march=native -O3
OBJ= main.o
LIB = -lm
all :  pdeSolver

pdeSolver: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -pthread -o pdeSolver -DLIKWID_PERFMON $(LIB)

main.o : main.c
	$(CC) $(CFLAGS) main.c $(LIB) 
clean : 
	rm -f $(OBJ) *~ pdeSolver out.txt plot.gp *.txt
assembly:
	$(CC) -march=native -s main.c
