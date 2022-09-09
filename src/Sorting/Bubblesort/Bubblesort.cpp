#include "Bubblesort.h"


Bubblesort::Bubblesort(void) : Sorting() {}

Bubblesort::Bubblesort(float* lista_desordenada, int tamanho) : Sorting(lista_desordenada, tamanho) {}

Bubblesort::~Bubblesort(void) {}


void Bubblesort::ordenar(void) {

	int posicao = 0;

	bool sair = false;

	//O loop continua at� que n�o seja realizada nenhuma troca de posi��o
	while (!sair) {

		//Se nenhuma troca for feita, o loop encerra ao final da checagem
		sair = true;

		//Percorrendo o array at� a pen�ltima posi��o. Cada posi��o � comparada com o elemento � sua frente.
		for (posicao = 0; posicao < this->tamanho - 1; posicao = posicao + 1) {

			//Se o elemento [posicao] for maior que o da sua frente [posicao + 1], eles trocam de lugar
			if (this->lista[posicao] > this->lista[posicao + 1]) {
				this->swap(posicao, posicao + 1);
				sair = false;
			}
		}
	}

	this->ordenada = true;
}