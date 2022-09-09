#pragma once

#include <Sorting/Sorting.h>

/*
Bubblesort:

1) Percorra a lista, comparando 2 elementos vizinhos, checando sempre se o primeiro [posicao] � menor que o segundo [posicao + 1]
2) Caso o segundo elemento seja maior que o primeiro, troque a posi��o dos dois
3) Repita o processo at� que n�o sejam realizadas mais trocas de posi��o

Complexidade:

Melhor caso: O[n * n]
Pior caso: O[n * n]
*/

class Bubblesort : public Sorting {

private:

public:

	Bubblesort(void);
	Bubblesort(float* lista_desordenada, int tamanho);
	~Bubblesort(void);

	void ordenar(void);

};
