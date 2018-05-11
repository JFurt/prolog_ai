all: main

main: main.o smpl.o rand.o functions.o
	$(LINK.c) -o $@ -Bstatic T.o smpl.o rand.o functions.o -lm

smpl.o: smpl.c smpl.h
	$(COMPILE.c)  -g smpl.c

main.o: main.c smpl.h
	$(COMPILE.c) -g  main.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

functions.o: functions.c smpl.h
	$(COMPILE.c) -g  functions.c

clean:
	$(RM) *.o main relat saida *~

