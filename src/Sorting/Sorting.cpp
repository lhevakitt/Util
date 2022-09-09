#include "Sorting.h"


Sorting::Sorting(void) {

	this->lista = NULL;
	this->tamanho = 0;
	this->ordenada = false;

}

Sorting::Sorting(float* lista_desordenada, int tamanho_da_lista) {

	this->setLista(lista_desordenada, tamanho_da_lista);
	this->ordenada = false;

}

Sorting::~Sorting() {

	if (this->lista != NULL)
		delete[] this->lista;
}


void Sorting::setLista(float* nova_lista, int tamanho_da_lista) {

	if (nova_lista == NULL || tamanho_da_lista <= 0) {
		printf("Lista vazia!");
		return;
	}

	this->lista = new float[tamanho_da_lista];

	for (int x = 0; x < tamanho_da_lista; x = x + 1) {
		this->lista[x] = nova_lista[x];
	}

	this->tamanho = tamanho_da_lista;
}


void Sorting::swap(int posicao1, int posicao2) {

	float valor = 0.0;

	if (posicao1 < 0 || posicao2 < 0 || posicao1 >= this->tamanho || posicao2 >= this->tamanho)
		return;

	valor = this->lista[posicao1];
	this->lista[posicao1] = this->lista[posicao2];
	this->lista[posicao2] = valor;

}

bool Sorting::isListaVazia(void) {

	return (this->lista == NULL) || (this->tamanho <= 0);
}

void Sorting::imprimirLista(void) {

	bool vazia = this->isListaVazia();

	if (vazia) {
		printf("\n---------------------\n");
		printf("A lista está vazia!\n");
		printf("\n---------------------\n");
		return;
	}
		
	printf("\n---------------------\n");
	if (this->ordenada)
		printf("Lista ordenada:");
	else
		printf("Lista que sera ordenada:");
	printf("\n---------------------\n");

	for (int x = 0; x < this->tamanho; x = x + 1) {
		printf("[%d] - %.0f\n", x, this->lista[x]);
	}

	printf("\n---------------------\n");
}