#pragma once

#include <Sorting/Sorting.h>

/*
Quicksort:

1) Selecione uma posi��o da lista para servir de pivot para compara��o
2) Percorra o array, deixando os elementos que s�o menores que o pivot � sua esquerda e os que s�o maiores � sua direita
3) Quando essa checagem for finalizada, repita o processo com as parti��es � esquerda e � direita do pivot
4) Parti��es unit�rias ou vazias j� est�o ordenadas

Complexidade:
Melhor caso: O[n * log(n)] (Quando o pivot divide a lista em n/2 partes exatamente)
Pior caso: O[n * n] (Quando o pivot � o maior ou o menor item da lista)

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
