Trabalho 06 - ci355
Autor: João Furtado Resende

O algoritmo de distância entre arquivos
é baseado no SCM, Subsequencia comum máxima,
onde os elementos dos vetores A e B são as linhas
dos arquivos A e B.

A obtenção da resposta do SCM é feita através da matriz C usada
na Programação Dinâmica do Algoritmo. Tal obtenção é feita caminhando
do final da matriz para o começo e depois invertendo o resultado.

A partir da resposta do SCM são retiradas 'janelas de diferenças' d1 (arquivo A) e d2 (arquivo B),
ou seja, janelas entre os índices de elementos iguais.

Para ajustar estas janelas, linhas são retiradas/colocadas até que elas atinjam
o mesmo tamanho, após isto, as linhas são substituídas.

Tal procedimento é necessário para garantir a minimalidade de operações
para transformar o arquivo A no B.
