$DEPURA=1
opt=
compilador: lex.yy.c y.tab.c compilador.o compilador.h tabela.h tabela.o
	gcc lex.yy.c compilador.tab.c compilador.o tabela.o -o compilador -ll -ly -lc -g $(opt)

lex.yy.c: compilador.l compilador.h
	flex compilador.l

y.tab.c: compilador.y compilador.h
	bison compilador.y -d -v -Werror

tabela.o: tabela.c tabela.h compilador.h
	gcc -g -c tabela.c -o tabela.o $(opt)

compilador.o : compilador.h compiladorF.c
	gcc -g -c compiladorF.c -o compilador.o  $(opt)

clean : 
	rm -f compilador.tab.* lex.yy.c tabela.o compilador.o compilador *~ mepa mepa.o
