#pragma once

#include <Sorting/Sorting.h>

/*
Insertionsort:

1) Inicie a chave com o segundo elemento da lista e compare com todos os seus anteriores (no inicio, só há um elemento antes)
2) Caso o elemento anterior seja menor que a chave, troque sua posição com a posição da chave.
3) Ao chegar ao inicio da lista, incremente a posição da chave e repita o processo até que a posição da chave tenha percorrido toda a lista

Complexidade:
Melhor caso: O[n] (Caso a lista já esteja ordenada e nenhuma troca seja feita)
Pior caso: O[n * n] (Caso a lista esteja ordenada na ordem inversa) 

*/

class Insertionsort : public Sorting {

private:

public:

	Insertionsort(void);
	Insertionsort(float* listaDesordenada, int tamanhoDaLista);
	~Insertionsort(void);

	void ordenar(void);

};
