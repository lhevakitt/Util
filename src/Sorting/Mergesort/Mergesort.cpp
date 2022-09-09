#include "Mergesort.h"


Mergesort::Mergesort(void) : Sorting() {}

Mergesort::Mergesort(float* lista_desordenada, int tamanho_da_lista) : Sorting(lista_desordenada, tamanho_da_lista) {}

Mergesort::~Mergesort(void) {}


void Mergesort::dividir(float* lista, int inicio, int fim) {

	int tamanho = 0;

	//Se a lista for de tamanho unit�rio, n�o � necess�rio realizar mais divis�es
	if (inicio >= fim)
		return;

	//A lista � dividida pela metade (arredondando para baixo)
	tamanho = (inicio + fim) / 2;

	this->dividir(lista, inicio, tamanho);
	this->dividir(lista, tamanho + 1, fim);

	//Ap�s as divis�es serem conclu�das, as listas s�o "mergeadas" novamente
	this->unir(lista, inicio, tamanho, fim);

}

void Mergesort::unir(float* lista, int inicio, int meio, int fim) {

	float* listaEsquerda = NULL;
	float* listaDireita = NULL;

	int tamanhoEsquerda = meio - inicio + 1;
	int tamanhoDireita = fim - meio;
	int posicaoEsquerda = 0;
	int posicaoDireita = 0;
	int posicao = 0;

	//Listas tempor�rias para armazenar os valores das listas que foram geradas pela divis�o da lista original (parametro 'lista')
	listaEsquerda = new float[tamanhoEsquerda];
	listaDireita = new float[tamanhoDireita];

	//listaEsquerda cont�m os elementos da lista original, da posi��o [inicio] at� a posi��o [meio]
	for (posicaoEsquerda = 0; posicaoEsquerda < tamanhoEsquerda; posicaoEsquerda = posicaoEsquerda + 1)
		listaEsquerda[posicaoEsquerda] = lista[posicaoEsquerda + inicio];

	//listaDireita cont�m os elementos da lista original, da posi��o [meio + 1] at� a posi��o [final]
	for (posicaoDireita = 0; posicaoDireita < tamanhoDireita; posicaoDireita = posicaoDireita + 1)
		listaDireita[posicaoDireita] = lista[posicaoDireita + meio + 1];

	posicaoEsquerda = 0;
	posicaoDireita = 0;
	posicao = inicio;

	//Esse loop � o que faz a ordena��o propriamente da lista
	//As duas listas divididas s�o comparadas entre si e o menor valor entre elas vai para a posi��o na lista de resultado
	while (posicaoEsquerda < tamanhoEsquerda && posicaoDireita < tamanhoDireita) {

		if (listaEsquerda[posicaoEsquerda] < listaDireita[posicaoDireita]) {
			lista[posicao] = listaEsquerda[posicaoEsquerda];
			posicaoEsquerda = posicaoEsquerda + 1;
		}
		else {
			lista[posicao] = listaDireita[posicaoDireita];
			posicaoDireita = posicaoDireita + 1;
		}
		
		posicao = posicao + 1;
	}

	//Como � normal que as listas de divis�o tenham tamanhos diferentes, os valores que n�o foram utilizados na compara��o s�o copiados para a lista resultado
	while (posicaoEsquerda < tamanhoEsquerda) {

		lista[posicao] = listaEsquerda[posicaoEsquerda];
		posicaoEsquerda = posicaoEsquerda + 1;
		posicao = posicao + 1;
	}

	while (posicaoDireita < tamanhoDireita) {

		lista[posicao] = listaDireita[posicaoDireita];
		posicaoDireita = posicaoDireita + 1;
		posicao = posicao + 1;
	}

	delete[] listaDireita;
	delete[] listaEsquerda;
}


void Mergesort::ordenar(void) {

	int inicio = 0;
	int fim = this->tamanho - 1;

	//O m�todo deve atuar inicialmente na lista completa
	this->dividir(this->lista, inicio, fim);

	this->ordenada = true;

}