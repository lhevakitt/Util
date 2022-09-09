#include "Quicksort.h"


Quicksort::Quicksort(void) : Sorting() {}

Quicksort::Quicksort(float* lista_desordenada, int tamanho_da_lista) : Sorting(lista_desordenada, tamanho_da_lista) {}

Quicksort::~Quicksort(void) {}


int Quicksort::getPosicaoPivot(int inicio, int fim) {

	int retorno = -1;
	bool vazia = this->isListaVazia();

	//Se a lista estiver vazia, o pivot n�o pode ser calculado
	if (vazia)
		return retorno;

	//Por enquanto, a posi��o do pivot ser� sempre a posi��o na metade do array
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

	//[i] � um �ndice crescente. [j] � um decrescente. Quando eles se cruzarem (j < i) o array inteiro j� ter� sido percorrido
	while (i <= j) {

		//Elementos que est�o antes do pivot e que s�o menores que ele permanecem no lugar
		while (this->lista[i] < pivot && i < fim)
			i = i + 1;

		//Elementos que est�o depois do pivot e que s�o maiores do que ele permanecem no lugar
		while (this->lista[j] > pivot && j > inicio)
			j = j - 1;
		
		//Caso haja um elemento antes do pivot que seja maior e um elemento depois que seja menor que o pivot, eles s�o trocados de lugar
		if (i <= j) {
			this->swap(i, j);

		//Com a troca, os elementos [i] e [j] n�o precisam mais ser avaliados no pr�ximo loop, pois eles est�o nos seus devidos lugares em rela��o ao pivot
			i = i + 1;
			j = j - 1;
		}
	}
	
	//Analisando a parti��o do array que � maior que o pivot atual
	if (i < fim) {
		novoPivot = this->getPosicaoPivot(i, fim);
		this->comparar(novoPivot, i, fim);
	}

	//Analisando a parti��o do array que � menor que o pivot atual
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

	//O in�cio do algoritmo seleciona um pivot e particiona a lista inteira.
	posicaoPivot = this->getPosicaoPivot(0, this->tamanho - 1);
	this->comparar(posicaoPivot, 0, this->tamanho - 1);

	this->ordenada = true;
}