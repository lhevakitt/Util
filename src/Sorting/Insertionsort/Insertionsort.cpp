#include "Insertionsort.h"


Insertionsort::Insertionsort(void) : Sorting() {}

Insertionsort::Insertionsort(float* lista_desordenada, int tamanho) : Sorting(lista_desordenada, tamanho) {}

Insertionsort::~Insertionsort(void) {}


void Insertionsort::ordenar(void) {

	float chave = 0.0;

	int i = 0;
	int j = 0;

	bool listaVazia = this->isListaVazia();

	//� preciso garantir que a lista possui pelo menos 2 itens
	if (listaVazia || this->tamanho < 2)
		return;

	//[i] � a posi��o da chave na lista n�o ordenada. [j + 1] ser� a posi��o da chave na lista ordenada
	//Caso a lista j� esteja ordenada, [i] = [j + 1] para todos os casos
	for (i = 1; i < tamanho; i = i + 1) {

		//A chave � o item que est� sendo ordenado no momento. Ele ser� comparado com todos os elementos anteriores
		chave = this->lista[i];
		j = i - 1;

		//Enquanto houver elementos anteriores � chave maiores do que o seu valor, suas posi��es s�o trocadas.
		while (j >= 0 && this->lista[j] > chave) {
			this->lista[j + 1] = this->lista[j];
			j = j - 1;			
		}

		//Quando n�o ocorrer troca de posi��o, a chave estar� na sua posi��o correta.
		this->lista[j + 1] = chave;
	}

	this->ordenada = true;
}