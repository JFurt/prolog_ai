%--movimentador atomico

adjacente( [ [A], [0,0,0,0], [B1,B2,B3,B4], [B]],a,[ [A], [0,0,0,0], [B1,B2,B3,B4], [B]]) :- !.

adjacente( [ [A], [A1,A2,A3,A4], [0,0,0,0], [B]],b,[ [A], [A1,A2,A3,A4], [0,0,0,0], [B]]) :- !.


adjacente([ [A],[A1,A2,A3,A4],[B1,B2,B3,B4],[B] ],J,[ [P], [At1,At2,At3,At4], [Bt1,Bt2,Bt3,Bt4], [B] ]) :-
	J = a,
	jogada([ [A],[A1,A2,A3,A4],[B1,B2,B3,B4] ],  [ [P], [At1,At2,At3,At4], [Bt1,Bt2,Bt3,Bt4] ]).

adjacente([ [A],[A1,A2,A3,A4],[B1,B2,B3,B4],[B] ],J, [ [A], [At1,At2,At3,At4], [Bt1,Bt2,Bt3,Bt4], [P] ]) :-
	J = b,
	jogada([ [B],[B1,B2,B3,B4],[A1,A2,A3,A4] ], [ [P], [Bt1,Bt2,Bt3,Bt4], [At1,At2,At3,At4] ]).
	

jogada([ [J], [J1,J2,J3,J4], [O1,O2,O3,O4] ],Proximo) :-
	not(J1 = 0),
	joga_na_casa(J1,[ [J], [J2,J3,J4,O1,O2,O3,O4,0] ], [ [P], [Jt2,Jt3,Jt4,Ot1,Ot2,Ot3,Ot4,Jt1] ]),
	Proximo = [ [P], [Jt1,Jt2,Jt3,Jt4], [Ot1,Ot2,Ot3,Ot4] ].


jogada([ [J], [J1,J2,J3,J4], [O1,O2,O3,O4] ],Proximo) :-
	not(J2 = 0),
	joga_na_casa(J2,[ [J], [J3,J4,O1,O2,O3,O4,J1,0] ], [ [P], [Jt3,Jt4,Ot1,Ot2,Ot3,Ot4,Jt1,Jt2] ]),
	Proximo = [ [P], [Jt1,Jt2,Jt3,Jt4], [Ot1,Ot2,Ot3,Ot4] ].


jogada([ [J], [J1,J2,J3,J4], [O1,O2,O3,O4] ],Proximo) :-
	not(J3 = 0),
	joga_na_casa(J3, [ [J], [J4,O1,O2,O3,O4,J1,J2,0] ], [ [P], [Jt4,Ot1,Ot2,Ot3,Ot4,Jt1,Jt2,Jt3] ]),
	Proximo = [ [P], [Jt1,Jt2,Jt3,Jt4], [Ot1,Ot2,Ot3,Ot4] ].


jogada([ [J], [J1,J2,J3,J4], [O1,O2,O3,O4] ],Proximo) :-
	not(J4 = 0),
	joga_na_casa(J4, [ [J], [O1,O2,O3,O4,J1,J2,J3,0] ], [ [P], [Ot1,Ot2,Ot3,Ot4,Jt1,Jt2,Jt3,Jt4] ]),
	Proximo = [ [P], [Jt1,Jt2,Jt3,Jt4], [Ot1,Ot2,Ot3,Ot4] ].


joga_na_casa(0,[ [P], Cauda], [ [P], Cauda ]).

joga_na_casa(Valor, [ [P], [CC,C2,C3,C4,C5,C6,C7,C8] ], [ [PR], [CCRfin,CR2,CR3,CR4,CR5,CR6,CR7,CR8] ]) :-
	Valor > 0,
	CC = 1,
	CCR is 0,
	ValorR is Valor - 1,
	joga_na_casa(ValorR, [ [P], [C2,C3,C4,C5,C6,C7,C8,CCR ]], [ [PP], [CR2,CR3,CR4,CR5,CR6,CR7,CR8,CCRfin ] ]),
	PR is PP + 2.

joga_na_casa(Valor, [ [P], [CC,C2,C3,C4,C5,C6,C7,C8] ], [ [PR], [CCRfin,CR2,CR3,CR4,CR5,CR6,CR7,CR8] ]) :-
	Valor > 0,
	not(CC = 1),
	CCR is CC + 1,
	ValorR is Valor - 1,
	joga_na_casa(ValorR, [ [P], [C2,C3,C4,C5,C6,C7,C8,CCR ]], [ [PR], [CR2,CR3,CR4,CR5,CR6,CR7,CR8,CCRfin ] ]).


%---

%---Global
altura_max(1).

%---Util
		
	oponente(a,b) :- !.
	oponente(b,a) :- !.

	signal(a,1) :- !.
	signal(b,-1) :- !.


	maior(pinf,_,pinf) :- !.

	maior(_,pinf,pinf) :- !.

	maior(X,pinf,X) :- !,false.

	maior(pinf,X,X) :- !,false.


	maior(ninf,Y,Y) :- !.

	maior(X,ninf,X) :- !.


	maior(ninf,_,ninf) :- !,false.

	maior(_,ninf,ninf) :- !,false.


	maior(X,Y,X) :-
		X > Y,!.

	maior(_,Y,Y) :- !.



	menor(ninf,_,ninf) :- !.

	menor(_,ninf,ninf) :- !.


	menor(ninf,X,X) :- !,false.

	menor(X,ninf,X) :- !,false.



	menor(pinf,X,X) :- !.

	menor(X,pinf,X) :- !.



	menor(X,Y,X) :-
		X < Y,!.

	menor(_,Y,Y) :- !.


	maior_ini( [TX,X], [_,ninf] , [TX,X]) :- !.

	maior_ini( [_,ninf], [TY,Y] , [TY, Y]) :- !.

	


	maior_ini( [TP,pinf], _, [TP,pinf]) :- !.

	maior_ini( _,[TP,pinf], [TP,pinf]) :- !.



	maior_ini([TX,X], [_,Y], [TX,X]) :-
		X > Y,!.

	maior_ini([_,_], [TY,Y], [TY,Y]) :- !.


%---min

min([ [PA], [0,0,0,0], [0,0,0,0], [PB] ],_,_,_,_,_,ninf):-
	PA > PB,!.



min([ [PA], [0,0,0,0], [0,0,0,0], [PB] ],_,_,_,_,_,0):-
	PA = PB, !.

min([ [_], [0,0,0,0], [0,0,0,0], [_] ],_,_,_,_,_,pinf):- !.



min(T,_,_,Altura,AlturaMax,J,Result) :-
	Altura = AlturaMax,
	fae(T,J,Result), 
	!.

min(T,Alfa,Beta,Altura,AlturaMax,J,Result) :-
	findall(S,adjacente(T,J,S),Adj),
	min_inner(Adj,Alfa,Beta,Altura,AlturaMax,J,Result,0).

min_inner([_],Alfa,Beta,_,_,_,Alfa,1) :-
	maior(Alfa,Beta,Alfa), 
	!.

min_inner([Tab | Cauda],Alfa,Beta,Altura,AlturaMax,J,Result,_) :-
	AlturaNova is Altura + 1,
	oponente(J,O),
	max(Tab,Alfa,Beta,AlturaNova,AlturaMax,O,RetornoAlt),
	menor(RetornoAlt,Beta,BetaNovo),
	min_inner(Cauda,Alfa,BetaNovo,Altura,AlturaMax,J,Result,1).

min_inner([],_,Beta,_,_,_,Beta,_) :- !.



%----max

max([ [PA], [0,0,0,0], [0,0,0,0], [PB] ],_,_,_,_,_,pinf):-
	PA > PB,!.

max([ [PA], [0,0,0,0], [0,0,0,0], [PB] ],_,_,_,_,_,0):-
	PA = PB, !.

max([ [_], [0,0,0,0], [0,0,0,0], [_] ],_,_,_,_,_,ninf):- !.



max(T,_,_,Altura,AlturaMax,J,Result) :-
	Altura = AlturaMax,
	fae(T,J,Result),
	!.

max(T,Alfa,Beta,Altura,AlturaMax,J,Result) :-
	findall(S,adjacente(T,J,S),Adj),
	max_inner(Adj,Alfa,Beta,Altura,AlturaMax,J,Result,0).

max_inner([_],Alfa,Beta,_,_,_,Beta,1) :-
	maior(Beta,Alfa,Alfa), !.

max_inner([Tab | Cauda],Alfa,Beta,Altura,AlturaMax,J,Result,_) :-
	AlturaNova is Altura + 1,
	oponente(J,O),
	min(Tab,Alfa,Beta,AlturaNova,AlturaMax,O,RetornoAlt),
	maior(RetornoAlt,Alfa,AlfaNovo),
	max_inner(Cauda,AlfaNovo,Beta,Altura,AlturaMax,J,Result,1).

max_inner([],Alfa,_,_,_,_,Alfa,_) :- !.




inicia_max([],T,_,_,T) :- !.



inicia_max(S,_,J,AlturaMax,Proximo) :-
	inicia_max_inner(S,ninf,pinf,0,AlturaMax,J,_,Proximo),!.

inicia_max_inner([Tab | Cauda],Alfa,Beta,Altura,AlturaMax,J,TAtual,TRes) :-
	AlturaNova is Altura + 1,
	oponente(J,O),
	min(Tab,Alfa,Beta,AlturaNova,AlturaMax,O,RetornoAlt),
	maior_ini([Tab,RetornoAlt] , [TAtual,Alfa], [TNovo,AlfaNovo]),
	inicia_max_inner(Cauda,AlfaNovo,Beta,Altura,AlturaMax,J,TNovo,TRes).

inicia_max_inner([],_,_,_,_,_,TAtual,TAtual) :- !.

%---FAE


fae([ [PA], [C1,C2,C3,C4], [C5,C6,C7,C8], [PB]],J,ResTot) :- 
	local(L),
	signal(L,Sig),
	ResOuter is 3*Sig*(PA - PB),
	fae_inner([C1,C2,C3,C4,C5,C6,C7,C8],J,L,ResInner),
	ResTot is ResInner + ResOuter,
	!.

fae_inner([],_,_,0) :- !.

%Maq joga

fae_inner([Head | Tail], J, L, Res) :-
	not(Head = 0),
	not(Head = 1),
	fae_inner(Tail,J,L,Res),!.

fae_inner([Head | Tail], J, L,Res) :-
	J = L,
	Head = 1,
	fae_inner(Tail,J,L,ResInner),
	Res = ResInner + 2.

fae_inner([Head | Tail], J, L, Res) :-
	J = L,
	Head = 0,
	fae_inner(Tail,J,L,ResInner),
	Res = ResInner - 1.

%Opon joga

fae_inner([Head | Tail], J, L,Res) :-
	not(J = L),
	Head = 1,
	fae_inner(Tail,J,L,ResInner),
	Res = ResInner - 2.

fae_inner([Head | Tail], J, L, Res) :-
	not(J = L),
	Head = 0,
	fae_inner(Tail,J,L,ResInner),
	Res = ResInner + 1.




%--main

plausivel(T,J,AlturaMax,Proximo) :-
	assert(local(J)),
	findall(S,adjacente(T,J,S),Adj),
	inicia_max(Adj,T,J,AlturaMax,Proximo),
	retract(local(J)),!.