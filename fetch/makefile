OBJ=search.o main.o
CFLAGS=-c -lm -g
LDFLAGS=-lm -g
sonda: search.o main.o
	gcc $(OBJ) $(LDFLAGS) -o sonda
main.o: main.c search.o struct.h
	gcc $(CFLAGS) main.c
search.o: search.c struct.h
	gcc $(CFLAGS) search.c
clean:
	rm -fr *.o *~ sonda
