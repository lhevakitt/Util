#pragma once

#include <Sorting/Sorting.h>

/*
Mergesort:

1) Divida a lista original pela metade recursivamente até que a divisão da lista retorne 2 listas com 1 elemento cada (divide)
2) Compare as duas listas entre si (compare)
3) Junte novamente as duas listas, colocando o menor elemento na posição inicial da lista resultado (conquer)
4) Se uma das listas acabar antes da outra, copie todos os elementos da lista maior para a lista resultado

Complexidade:
Melhor caso: O[n * log(n)]
Pior caso: O[n * log(n)]

*/

class Mergesort : public Sorting {

private:

public:

	Mergesort(void);
	Mergesort(float* lista_desordenada, int tamanho);
	~Mergesort(void);

	void dividir(float* lista, int inicio, int fim);
	void unir(float* lista, int inicio, int meio, int fim);
	
	void ordenar(void);

};
