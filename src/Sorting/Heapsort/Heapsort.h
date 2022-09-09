#pragma once

#include <Sorting/Sorting.h>

/*
Heapsort:

Para esse algoritmo, entenda a lista como uma árvore binária:
lista = {A(0), B(1), C(2), D(3), E(4), F(5), G(6)}

			A(0)
	B(1)			C(2)
D(3)	E(4)	F(5)	G(6)

Para cada posição [x] da lista, seus filhos (se eles existirem na árvore) estão nas posições:
[2x + 1] (filho à esquerda)
[2x + 2] (filho à direita)

1) A posição inicial é o index da última sub-arvore (não necessariamente ela precisa ter filhos).
2) Verifique se o pai da sub-árvore inicial é maior que os seus filhos. Caso não seja, troque-os de lugar
3) Em caso de troca de lugar, verifique todas as sub-arvores abaixo do filho trocado
4) Após verificar todas as sub-árvores, volte uma posição na árvore para repetir o processo com todas as outras sub-árvores
5) Ao chegar na raiz (que é o primeiro elemento da lista e deverá conter o maior elemento da árvore), troque de lugar com o último elemento da lista.
6) O elemento enviado para última posição da lista já está na sua posição correta e não precisará ser mais avaliado.
7) Repita a análise da árvore, agora tendo como posição inicial a raiz da árvore e como posição final a posição imediatamente anterior ao do elemento trocado no passo anterior

Complexidade:
Melhor caso: O[n * log(n)]
Pior caso: O[n * log(n)]

*/

class Heapsort : public Sorting {

private:

public:

	Heapsort(void);
	Heapsort(float* lista_desordenada, int tamanho);
	~Heapsort(void);

	void heap(int posicao, int tamanhoMaximo);

	void ordenar(void);

};

