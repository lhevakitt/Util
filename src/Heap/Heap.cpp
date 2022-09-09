#include "Heap.h"

template <class Elemento>
Heap<Elemento>::Heap(void) {

	this->numeroDeElementos = 0;
	this->tamanhoDaLista = 1;
	this->lista = new Elemento[this->tamanhoDaLista];
}

template <class Elemento>
Heap<Elemento>::Heap(int tamanhoDaHeap) {

	this->numeroDeElementos = 0;
	this->tamanhoDaLista = tamanhoDaHeap;
	this->lista = new Elemento[this->tamanhoDaLista];
}

template <class Elemento>
Heap<Elemento>::~Heap(void) {

	delete[](Elemento*) this->lista;
}


template <class Elemento>
int Heap<Elemento>::getNumeroDeElementos(void) {
	return this->numeroDeElementos;
}


template <class Elemento>
void Heap<Elemento>::expandirLista(void) {

	Elemento* novaLista = NULL;

	int acrescimo = 10;

	novaLista = new Elemento[this->tamanhoDaLista + acrescimo];

	for (int posicao = 0; posicao < this->tamanhoDaLista; posicao = posicao + 1)
		novaLista[posicao] = this->lista[posicao];

	delete[] this->lista;

	this->lista = novaLista;
	this->tamanhoDaLista = this->tamanhoDaLista + acrescimo;

}


template <class Elemento>
void Heap<Elemento>::inserir(Elemento item) {

	if (this->numeroDeElementos >= this->tamanhoDaLista)
		this->expandirLista();

	this->lista[this->numeroDeElementos] = item;
	this->numeroDeElementos++;

}

template <class Elemento>
Elemento Heap<Elemento>::remover(void) {


	Elemento retorno;

	if (this->numeroDeElementos == 0)
		return NULL;

	retorno = this->lista[this->numeroDeElementos - 1];
	this->numeroDeElementos--;

	return retorno;
}

template <class Elemento>
void Heap<Elemento>::resetarHeap(void) { this->numeroDeElementos = 0; }