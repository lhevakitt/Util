#pragma once

#include <Sorting/Sorting.h>

/*
Quicksort:

1) Selecione uma posição da lista para servir de pivot para comparação
2) Percorra o array, deixando os elementos que são menores que o pivot à sua esquerda e os que são maiores à sua direita
3) Quando essa checagem for finalizada, repita o processo com as partições à esquerda e à direita do pivot
4) Partições unitárias ou vazias já estão ordenadas

Complexidade:
Melhor caso: O[n * log(n)] (Quando o pivot divide a lista em n/2 partes exatamente)
Pior caso: O[n * n] (Quando o pivot é o maior ou o menor item da lista)

*/

class Quicksort : public Sorting {

private:

public:

	Quicksort();
	Quicksort(float* lista_desordenada, int tamanho_da_lista);
	~Quicksort();

	int getPosicaoPivot(int inicio, int fim);
	void comparar(int posicaoPivot, int inicio, int fim);

	void ordenar(void);

};
