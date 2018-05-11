coord(a,[15,160]).
coord(b,[230,45]).
coord(c,[145,15]).
coord(d,[90,15]).
coord(e,[295,20]).
coord(f,[175,235]).
coord(g,[215,15]).
coord(h,[295,60]).
coord(i,[255,185]).
coord(l,[75,65]).
coord(m,[75,35]).
coord(n,[195,205]).
coord(o,[45,210]).
coord(p,[170,70]).
coord(r,[115,105]).
coord(s,[95,135]).
coord(t,[20,95]).
coord(u,[255,60]).
coord(v,[275,120]).
coord(z,[35,190]).

caminho(e,h,86).
caminho(h,u,98).
caminho(u,b,85).
caminho(u,v,142).
caminho(b,g,90).
caminho(v,i,92).
caminho(i,n,87).
caminho(b,p,101).
caminho(b,f,211).
caminho(p,c,138).
caminho(p,r,97).
caminho(c,r,146).
caminho(c,d,120).
caminho(f,s,99).
caminho(r,s,80).
caminho(d,m,75).
caminho(m,l,70).
caminho(l,t,111).
caminho(t,a,118).
caminho(a,z,75).
caminho(z,o,71).
caminho(s,a,140).
caminho(s,o,151).

% Util
pertence_a_estr(X,[t(_,_,X)|_]) :-
	!.

pertence_a_estr(X,[_|C]) :-
	pertence_a_estr(X,C).

corrige_monotonicidade(F,Fpai,F) :-
	F > Fpai,!.

corrige_monotonicidade(_,Fpai,Fpai) :- !.


imprime_trajetoria([t(_,_,_ei)]) :-
	write('Estado Inicial: '),
	write(_ei),
	write('.\n'),
	!.

imprime_trajetoria([t(_,_,_n1) | _cauda]) :-
	imprime_trajetoria(_cauda),
	write('vai para a cidade: '),
	write(_n1),
	write('.\n').


tem_caminho_com_custo(_n1,_n2,_custo) :- 
	caminho(_n1,_n2,_custo).

tem_caminho_com_custo(_n1,_n2,_custo) :- 
	caminho(_n2,_n1,_custo).

dist(_n1,_n2,_resultado) :-
	coord(_n1,[_x1,_y1]),
	coord(_n2,[_x2,_y2]),
	_resultado is sqrt((_x1 - _x2)*(_x1 - _x2) + (_y1 - _y2)*(_y1 - _y2)).



atualiza_custo_atual(_custoTrajetoria) :-
	retractall(custo_atual(_)),
	asserta(custo_atual(_custoTrajetoria) :- !),
	!,false.

atualiza_custo_atual_falseless(_custoTrajetoria) :-
	retractall(custo_atual(_)),
	asserta(custo_atual(_custoTrajetoria) :- !).


h(_n1,_ef,Resultado) :-
	dist(_n1,_ef,Resultado),!.


produz_ciclo([_noAtual | _trajeto]) :-
	pertence_a_estr(_noAtual,_trajeto).

monta_trajetoria_prox_passo([t(Fpai,Gpai,_noAtual) |_trajetoria],[t(F,G,_proxNo), t(Fpai,Gpai,_noAtual) | _trajetoria],_ef) :-
	tem_caminho_com_custo(_noAtual,_proxNo,_custo_caminho),
	not(produz_ciclo([_proxNo,t(Fpai,Gpai,_noAtual) | _trajetoria])),
	h(_proxNo,_ef,_custo_heur),
	G is Gpai + _custo_caminho,
	_custo_f is G + _custo_heur,
	corrige_monotonicidade(_custo_f,Fpai,F).

busca_com_custo_maximo([t(F,G,_noAtual) | _trajetoria],_ef,_custoMaximo,[t(F,G,_noAtual) | _trajetoria]) :-
	not(F > _custoMaximo),
	_noAtual = _ef,
	!.

busca_com_custo_maximo([t(F,G,_noAtual) | _trajetoria],_ef,_custoMaximo,_trajetoriaOtima) :-
	not(F > _custoMaximo),
	monta_trajetoria_prox_passo([t(F,G,_noAtual) | _trajetoria], _proxTrajetoria,_ef),
	busca_com_custo_maximo(_proxTrajetoria,_ef,_custoMaximo,_trajetoriaOtima),!.

busca_com_custo_maximo([t(F,_,_) | _],_,_custoMaximo,_) :-
	F > _custoMaximo,
	custo_atual(_custoAtual),
	F < _custoAtual,
	atualiza_custo_atual(F),
	false.

busca_geral(_ei,_ef,_trajetoriaOtima,_maximoVariante) :-
	h(_ei,_ef,H),
	busca_com_custo_maximo([t(H,0,_ei)],_ef,_maximoVariante,_trajetoriaOtima),
	!.


busca_geral(_ei,_ef,_trajetoriaOtima,_) :-
	custo_atual(_custoAtual),
	atualiza_custo_atual_falseless(10000),
	busca_geral(_ei,_ef,_trajetoriaOtima,_custoAtual).

ida(_ei,_ef) :-
	asserta(custo_atual(10000) :- !),
	busca_geral(_ei,_ef,_trajetoriaOtima,0),
	imprime_trajetoria(_trajetoriaOtima).




