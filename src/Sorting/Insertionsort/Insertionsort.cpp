#include "Insertionsort.h"


Insertionsort::Insertionsort(void) : Sorting() {}

Insertionsort::Insertionsort(float* lista_desordenada, int tamanho) : Sorting(lista_desordenada, tamanho) {}

Insertionsort::~Insertionsort(void) {}


void Insertionsort::ordenar(void) {

	float chave = 0.0;

	int i = 0;
	int j = 0;

	bool listaVazia = this->isListaVazia();

	//É preciso garantir que a lista possui pelo menos 2 itens
	if (listaVazia || this->tamanho < 2)
		return;

	//[i] é a posição da chave na lista não ordenada. [j + 1] será a posição da chave na lista ordenada
	//Caso a lista já esteja ordenada, [i] = [j + 1] para todos os casos
	for (i = 1; i < tamanho; i = i + 1) {

		//A chave é o item que está sendo ordenado no momento. Ele será comparado com todos os elementos anteriores
		chave = this->lista[i];
		j = i - 1;

		//Enquanto houver elementos anteriores à chave maiores do que o seu valor, suas posições são trocadas.
		while (j >= 0 && this->lista[j] > chave) {
			this->lista[j + 1] = this->lista[j];
			j = j - 1;			
		}

		//Quando não ocorrer troca de posição, a chave estará na sua posição correta.
		this->lista[j + 1] = chave;
	}

	this->ordenada = true;
}