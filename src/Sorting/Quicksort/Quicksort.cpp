#include "Quicksort.h"


Quicksort::Quicksort(void) : Sorting() {}

Quicksort::Quicksort(float* lista_desordenada, int tamanho_da_lista) : Sorting(lista_desordenada, tamanho_da_lista) {}

Quicksort::~Quicksort(void) {}


int Quicksort::getPosicaoPivot(int inicio, int fim) {

	int retorno = -1;
	bool vazia = this->isListaVazia();

	//Se a lista estiver vazia, o pivot não pode ser calculado
	if (vazia)
		return retorno;

	//Por enquanto, a posição do pivot será sempre a posição na metade do array
	retorno = (fim + inicio) / 2;

	return retorno;
}

void Quicksort::comparar(int posicaoPivot, int inicio, int fim) {

	float pivot = 0.0;
	float valor = 0.0;

	int novoPivot = 0;
	int i = 0;
	int j = 0;

	if (posicaoPivot < 0 || inicio < 0 || fim <= 0 || posicaoPivot >= this->tamanho || inicio >= this->tamanho || fim >= this->tamanho || inicio > fim)
		return;

	pivot = this->lista[posicaoPivot];
	i = inicio;
	j = fim;

	//[i] é um índice crescente. [j] é um decrescente. Quando eles se cruzarem (j < i) o array inteiro já terá sido percorrido
	while (i <= j) {

		//Elementos que estão antes do pivot e que são menores que ele permanecem no lugar
		while (this->lista[i] < pivot && i < fim)
			i = i + 1;

		//Elementos que estão depois do pivot e que são maiores do que ele permanecem no lugar
		while (this->lista[j] > pivot && j > inicio)
			j = j - 1;
		
		//Caso haja um elemento antes do pivot que seja maior e um elemento depois que seja menor que o pivot, eles são trocados de lugar
		if (i <= j) {
			this->swap(i, j);

		//Com a troca, os elementos [i] e [j] não precisam mais ser avaliados no próximo loop, pois eles estão nos seus devidos lugares em relação ao pivot
			i = i + 1;
			j = j - 1;
		}
	}
	
	//Analisando a partição do array que é maior que o pivot atual
	if (i < fim) {
		novoPivot = this->getPosicaoPivot(i, fim);
		this->comparar(novoPivot, i, fim);
	}

	//Analisando a partição do array que é menor que o pivot atual
	if (j > inicio) {
		novoPivot = this->getPosicaoPivot(inicio, j + 1);
		this->comparar(novoPivot, inicio, j + 1);
	}
		
}


void Quicksort::ordenar(void) {

	int posicaoPivot = 0;

	bool listaVazia = this->isListaVazia();

	if (listaVazia)
		return;

	//O início do algoritmo seleciona um pivot e particiona a lista inteira.
	posicaoPivot = this->getPosicaoPivot(0, this->tamanho - 1);
	this->comparar(posicaoPivot, 0, this->tamanho - 1);

	this->ordenada = true;
}