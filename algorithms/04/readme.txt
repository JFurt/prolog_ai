Caixeiro Viajante:

As funções que já existiam para tratar o problema
do caixeiro viajante foram mantidas as mesmas
(cv_le_instancia, cv_libera_instancia, cv_ee, cv_compara e etc).

As funções novas implementadas foram cv_bb que chama a função
processa_permutacoes_bb que por sua vez inicializa algumas variáveis
e chama a função todas_permutacoes_bb que é a função que resolve
recursivamente o problema.

Para podar a geração de permutações não frutiferas foram usadas algumas técnicas:

	Caso haja algum arco inexistente (cv_infinito) todas as permutações que resultam
	desta não são feitas.

	Caso a soma dos valores dos arcos já existentes na permutação for maior do que
	a melhor permutação, todas as permutações subsequentes não são geradas

	Caso a soma dos arcos mínimos dos nodos que não estão na permutação atual
	mais o valor da permutação atual for maior do que a melhor permutação já encontrada
	todas as permutações resultantes desta não são geradas.

	Caso não seja possível gerar um circuito euleriano a partir da permutação atual
	(se existir algum nó que ainda não está na permutação com um grau de entrada ou saída
	igual a 0), todas as permutações subsequentes não são geradas.

Tais 'podas' são implementadas na função cv_heuristica, que retorna 1 caso uma poda seja possível.



Mochila


As funções que já existiam para tratar o problema
da mochila foram mantidas as mesmas
(mochila_le_instancia, mochila_libera_instancia, mochila_ee, compara e etc).

As funções novas implementadas foram mochila_bb que chama a função processa_subconjuntos_bb
que por sua vez inicia algumas variáveis globais e chama a função subconjuntos_bb que
resolve o problema recursivamente.

Para podar a geração de subconjuntos que não levariam a uma solução ótima foram usadas as técnicas:
	
	Caso a soma dos pesos dos itens da mochila já excedam a capacidade máxima da mochila
	o subconjunto e todos seus descendentes são abandonados.

	Como limitante superior foi calculado o valor da solução para o problema da mochila continuo ([0,1]) para os itens que não pertencem a solução atual, com o peso máximo W = W - peso(SolucaoAtual). Tal cálculo foi feito através do algoritmo guloso (e ótimo) apresentado em sala.





