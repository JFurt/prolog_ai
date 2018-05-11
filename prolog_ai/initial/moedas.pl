oposto(maior,menor).
oposto(menor,maior).

somatoria([],0).

somatoria([ Cab | Cauda], N) :-
	somatoria( Cauda, NY),
	N is NY + Cab.

compara(Pesq,Pdir,maior) :-
	Pesq > Pdir.

compara(Pesq,Pdir, igual) :-
	Pesq = Pdir.

compara(Pesq,Pdir, menor) :-
	Pesq < Pdir.

pesa(Lesq,Ldir,Resq) :-
	somatoria(Lesq,Pesq),
	somatoria(Ldir,Pdir),
	compara(Pesq,Pdir,Resq).

resolve_1([OK],[E4],[E4, Respes]) :-
	pesa([E4],[OK],Respes).

resolve_2([OK], [E1], [_], P, [E1, P]) :-
	pesa([E1], [OK], P),
	!.

resolve_2([_], [_], [E2], P, [E2, P]).

resolve_3([E1, E2, _], P, [E1, P]) :-
	pesa([E1], [E2] , P),
	!.

resolve_3([E1, E2, E3], P, [E3, P]) :-
	pesa([E1], [E2], igual),
	!.

resolve_3([_,E2,_] , P, [E2, P]).

resolve_4([OK1, OK2, OK3], [E1, E2, E3, E4], R) :-
	pesa([E1, E2, E3], [OK1, OK2, OK3], igual),
	resolve_1([OK1], [E4], R),
	!.

resolve_4([OK1, OK2, OK3], [E1, E2, E3,_], R) :-
	pesa([E1, E2, E3], [OK1, OK2, OK3], P),
	resolve_3([E1, E2, E3], P, R).

resolve_8([OK1,OK2,OK3], [ [E1,E2,E3,E4], [E5,E6,E7,E8] ], P, R) :-
	pesa([E1,OK1,OK2,OK3], [E5, E2, E3, E4], igual),
	oposto(P,Plinha),
	resolve_3([E6, E7, E8], Plinha, R),
	!.

resolve_8([OK1,OK2,OK3], [[E1,E2,E3,E4], [E5,_,_,_]], P, R) :-
	pesa([E1,OK1,OK2,OK3], [E5, E2, E3, E4], P),
	resolve_2([OK1], [E1], [E5], P, R),
	!.

resolve_8([_,_,_] , [[_,E2,E3,E4], [_,_,_,_]], P, R) :-
	resolve_3([E2, E3, E4], P , R).

resolve_geral([C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12], R) :-
	pesa([C1, C2, C3, C4], [C5, C6, C7, C8], igual),
	resolve_4([C1,C2,C3],[C9,C10,C11,C12],R),
	!.

resolve_geral([C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,_], R) :-
	pesa([C1, C2, C3, C4], [C5, C6, C7, C8], P),
	resolve_8([C9, C10, C11], [ [C1,C2,C3,C4], [C5,C6,C7,C8] ], P, R).
	
