#include "Mergesort.h"


Mergesort::Mergesort(void) : Sorting() {}

Mergesort::Mergesort(float* lista_desordenada, int tamanho_da_lista) : Sorting(lista_desordenada, tamanho_da_lista) {}

Mergesort::~Mergesort(void) {}


void Mergesort::dividir(float* lista, int inicio, int fim) {

	int tamanho = 0;

	//Se a lista for de tamanho unitário, não é necessário realizar mais divisões
	if (inicio >= fim)
		return;

	//A lista é dividida pela metade (arredondando para baixo)
	tamanho = (inicio + fim) / 2;

	this->dividir(lista, inicio, tamanho);
	this->dividir(lista, tamanho + 1, fim);

	//Após as divisões serem concluídas, as listas são "mergeadas" novamente
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

	//Listas temporárias para armazenar os valores das listas que foram geradas pela divisão da lista original (parametro 'lista')
	listaEsquerda = new float[tamanhoEsquerda];
	listaDireita = new float[tamanhoDireita];

	//listaEsquerda contém os elementos da lista original, da posição [inicio] até a posição [meio]
	for (posicaoEsquerda = 0; posicaoEsquerda < tamanhoEsquerda; posicaoEsquerda = posicaoEsquerda + 1)
		listaEsquerda[posicaoEsquerda] = lista[posicaoEsquerda + inicio];

	//listaDireita contém os elementos da lista original, da posição [meio + 1] até a posição [final]
	for (posicaoDireita = 0; posicaoDireita < tamanhoDireita; posicaoDireita = posicaoDireita + 1)
		listaDireita[posicaoDireita] = lista[posicaoDireita + meio + 1];

	posicaoEsquerda = 0;
	posicaoDireita = 0;
	posicao = inicio;

	//Esse loop é o que faz a ordenação propriamente da lista
	//As duas listas divididas são comparadas entre si e o menor valor entre elas vai para a posição na lista de resultado
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

	//Como é normal que as listas de divisão tenham tamanhos diferentes, os valores que não foram utilizados na comparação são copiados para a lista resultado
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

	//O método deve atuar inicialmente na lista completa
	this->dividir(this->lista, inicio, fim);

	this->ordenada = true;

}