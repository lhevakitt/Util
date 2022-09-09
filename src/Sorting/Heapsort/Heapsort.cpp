#include "Heapsort.h"


Heapsort::Heapsort(void) : Sorting() {}

Heapsort::Heapsort(float* lista_desordenada, int tamanho) : Sorting(lista_desordenada, tamanho) {}

Heapsort::~Heapsort(void) {}


void Heapsort::heap(int posicao, int tamanhoMaximo) {

	int raiz = 0;
	int filhoEsquerdo = 0;
	int filhoDireito = 0;

	bool listaVazia = this->isListaVazia();

	//tamanhoMaximo representa o número de elementos não-ordenados que estão presente na lista
	if (posicao >= tamanhoMaximo || listaVazia)
		return;

	//Calculando as posições do pai e dos seus respectivos filhos na lista
	raiz = posicao;
	filhoEsquerdo = 2 * posicao + 1;
	filhoDireito = 2 * posicao + 2;

	//Verificando se o filho à esquerda é maior que o seu pai
	if (this->lista[filhoEsquerdo] > this->lista[raiz] && filhoEsquerdo < tamanhoMaximo)
		raiz = filhoEsquerdo;

	//Verificando se o filho à direita é maior que o seu pai (o filho à direita deveria ser maior que o esquerdo)
	if (this->lista[filhoDireito] > this->lista[raiz] && filhoDireito < tamanhoMaximo)
		raiz = filhoDireito;

	//Se foi encontrado um filho maior que o pai, é necessário reavaliar a sub-árvore
	if (raiz != posicao) {

		//O pai troca de lugar com o filho
		this->swap(posicao, raiz);
		//A sub-árvore do filho (que agora é o antigo pai) é reavaliada da mesma forma
		this->heap(raiz, tamanhoMaximo);
	}

}


void Heapsort::ordenar(void) {

	float valor = 0.0;

	int raiz = 0;

	//Primeiro se verifica todas as subárvores afim de se encontrar o maior elemento da lista e posicioná-lo na raíz da árvore [0].
	for (raiz = this->tamanho / 2; raiz >= 0; raiz = raiz - 1)
		this->heap(raiz, this->tamanho);

	//Para cada execução da heap, um elemento será sempre colocado na sua posição correta. Ele será sempre enviado para o final da lista não-ordenada
	for (raiz = this->tamanho - 1; raiz >= 0; raiz = raiz - 1) {

		//A primeira posição da lista [0] contém o maior item encontrado. Ele será enviado para a última posição da lista não-ordenada [raiz] 
		this->swap(0, raiz);
		//Toda a árvore será reavaliada, a partir da posição inicial até a última posição da lista não-ordenada [raiz]
		//Como essa posição não é inclusiva, o elemento da lista na posição [raiz] não será mais avaliado, pois ele já está no lugar correto.
		this->heap(0, raiz);
	}

	this->ordenada = true;
}