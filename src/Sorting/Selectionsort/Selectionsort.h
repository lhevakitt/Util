#pragma once

#include <Sorting/Sorting.h>
#include <float.h>

/*
Selectionsort:

1) Percorra a lista não-ordenada para encontrar o menor elemento
2) Coloque o menor elemento na primeira posição da lista ordenada
3) Repita o processo para todos os demais elementos, até que a lista não-ordenada esteja vazia (e a lista ordenada esteja completa)

Complexidade:
Melhor caso: O[n * n] (o array já está ordenado, mas ainda sim é necessário conferir todos os elementos)
Pior caso:  O[n * n]

*/

class Selectionsort : public Sorting {

private:

public:

	Selectionsort(void);
	Selectionsort(float* lista_desordenada, int tamanho);
	~Selectionsort(void);

	void ordenar(void);

};
