#pragma once

#include <Sorting/Sorting.h>
#include <float.h>

/*
Selectionsort:

1) Percorra a lista n�o-ordenada para encontrar o menor elemento
2) Coloque o menor elemento na primeira posi��o da lista ordenada
3) Repita o processo para todos os demais elementos, at� que a lista n�o-ordenada esteja vazia (e a lista ordenada esteja completa)

Complexidade:
Melhor caso: O[n * n] (o array j� est� ordenado, mas ainda sim � necess�rio conferir todos os elementos)
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
