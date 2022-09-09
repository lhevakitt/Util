#include "Selectionsort.h"


Selectionsort::Selectionsort(void) : Sorting() {}

Selectionsort::Selectionsort(float* lista_desordenada, int tamanho) : Sorting(lista_desordenada, tamanho) {}

Selectionsort::~Selectionsort(void) {}


void Selectionsort::ordenar(void) {

	float valor = 0.0;
	float menorValor = 0.0;

	int posicao = 0;
	int posicaoDoMenor = 0;
	int inicio = 0;

	bool sair = false;

	//O loop continua at� que toda a lista seja percorrida pelo menos uma vez
	while (!sair) {

		posicaoDoMenor = -1;
		menorValor = FLT_MAX;

		//Loop para percorrer o array procurando pelo menor elemento.
		for (posicao = inicio; posicao < this->tamanho; posicao = posicao + 1) {
			valor = this->lista[posicao];

			//Se um elemento de menor valor for encontrado, sua posi��o � guardada e ele passar� a ser a nova refer�ncia para compara��o com os demais
			if (valor < menorValor) {
				menorValor = valor;
				posicaoDoMenor = posicao;
			}
		}

		//Se foi encontrado um elemento menor, ele troca de posi��o com o primeiro elemento da lista n�o-ordenada
		if (posicaoDoMenor != -1)
			this->swap(inicio, posicaoDoMenor);

		//A vari�vel [inicio] marca a posi��o na lista a partir da qual os elementos ainda n�o foram ordenados
		inicio = inicio + 1;

		//Caso o inicio da lista ordenada seja igual ao tamanho da lista, ela j� est� completamente ordenada
		sair = (inicio == this->tamanho);
	}

	this->ordenada = true;

}