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
