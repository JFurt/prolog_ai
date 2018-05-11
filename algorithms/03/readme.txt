As funções foram implementadas conforme foi requisitado na especificação.
As funções extras usadas foram:
	compara(unsigned int *S, unsigned int n):
		É passada para função de achar subconjuntos para ser aplicada
		em todos os subconjuntos. Usa variáveis globais para o peso, valor,
		melhor combinação, tamanho da melhor combinação.	
	subconjuntos(unsigned int n, unsigned int p, unsigned int a, processa)
		Faz a parte recursiva da função de achar subconjuntos e é chamada
		por processa_subconjuntos (especificada), usa uma variável global
		S para guardar o subconjunto atual e chama a função processa para
		todos os subconjuntos. 	
	
