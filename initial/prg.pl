somatoria([],0).

somatoria([X | Y] , S) :-
	somatoria(Y,SY),
	S is X + SY.    

concatenadas([],L,L).

concatenadas([X | Cauda1],L2,[X | Cauda3]) :-
	concatenadas(Cauda1,L2,Cauda3).


pertence_a(X,[C |_]) :-
	X = C.

pertence_a(X,[_ | Cd]) :-
	pertence_a(X,Cd).	

elemento_repetido([],[]).

elemento_repetido([C | Cd],[C | Z]) :-
	pertence_a(C, Cd),
	elemento_repetido(Cd,Z),
	not(pertence_a(C,Z)).

elemento_repetido([_| Cd],Z) :-
	elemento_repetido(Cd,Z).

intercalada([],L,L).

intercalada(L,[],L).

intercalada([C1 | Cd1], [C2 | Cd2], [C1, C2 | L]) :-
	intercalada(Cd1,Cd2,L).

insercao_ord(X,[],[X]).

insercao_ord(X,[C | Cd],[ X,C| Cd]) :-
	X =< C.

insercao_ord(X,[C | Cd], [C | L]) :-
	insercao_ord(X,Cd,L).

ordenada([],[]).

ordenada([C | Cd],L) :-
	ordenada(Cd,L2),
	insercao_ord(C,L2,L).

remove(_,[],[]).

remove(X,[C | Cd],[C | L]) :-
	not(X = C),
	remove(X,Cd,L).

remove(X,[C | Cd], L) :-
	X = C,
	remove(X,Cd,L).

tem_interseccao([Cx | _],Y) :-
	pertence_a(Cx,Y),
	!.

tem_interseccao([ _ | Cdx], Y) :-
	tem_interseccao(Cdx,Y).

uniao([],L,L).

uniao([Cx | Cdx], L2, [Cx |Z]) :-
	uniao(Cdx,L2,Z),
	not(pertence_a(Cx,Z)).

uniao([ _ | Cdx], L2, Z) :-
	uniao(Cdx,L2,Z).


subcultura_aux(X,[],[X]).

subcultura_aux(X,[C | Cd], [ Z | Cd]) :-
	tem_interseccao(X,C),
	uniao(X,C,Z), !.

subcultura_aux(X,[C | Cd],[C | LS2]) :-
	subcultura_aux(X,Cd,LS2).


subcultura([],[]).

subcultura([C | Cd], S) :-
	subcultura(Cd,S2),
	subcultura_aux(C,S2,S).


