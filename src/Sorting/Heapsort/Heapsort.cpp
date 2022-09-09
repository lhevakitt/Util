#include "Heapsort.h"


Heapsort::Heapsort(void) : Sorting() {}

Heapsort::Heapsort(float* lista_desordenada, int tamanho) : Sorting(lista_desordenada, tamanho) {}

Heapsort::~Heapsort(void) {}


void Heapsort::heap(int posicao, int tamanhoMaximo) {

	int raiz = 0;
	int filhoEsquerdo = 0;
	int filhoDireito = 0;

	bool listaVazia = this->isListaVazia();

	//tamanhoMaximo representa o n�mero de elementos n�o-ordenados que est�o presente na lista
	if (posicao >= tamanhoMaximo || listaVazia)
		return;

	//Calculando as posi��es do pai e dos seus respectivos filhos na lista
	raiz = posicao;
	filhoEsquerdo = 2 * posicao + 1;
	filhoDireito = 2 * posicao + 2;

	//Verificando se o filho � esquerda � maior que o seu pai
	if (this->lista[filhoEsquerdo] > this->lista[raiz] && filhoEsquerdo < tamanhoMaximo)
		raiz = filhoEsquerdo;

	//Verificando se o filho � direita � maior que o seu pai (o filho � direita deveria ser maior que o esquerdo)
	if (this->lista[filhoDireito] > this->lista[raiz] && filhoDireito < tamanhoMaximo)
		raiz = filhoDireito;

	//Se foi encontrado um filho maior que o pai, � necess�rio reavaliar a sub-�rvore
	if (raiz != posicao) {

		//O pai troca de lugar com o filho
		this->swap(posicao, raiz);
		//A sub-�rvore do filho (que agora � o antigo pai) � reavaliada da mesma forma
		this->heap(raiz, tamanhoMaximo);
	}

}


void Heapsort::ordenar(void) {

	float valor = 0.0;

	int raiz = 0;

	//Primeiro se verifica todas as sub�rvores afim de se encontrar o maior elemento da lista e posicion�-lo na ra�z da �rvore [0].
	for (raiz = this->tamanho / 2; raiz >= 0; raiz = raiz - 1)
		this->heap(raiz, this->tamanho);

	//Para cada execu��o da heap, um elemento ser� sempre colocado na sua posi��o correta. Ele ser� sempre enviado para o final da lista n�o-ordenada
	for (raiz = this->tamanho - 1; raiz >= 0; raiz = raiz - 1) {

		//A primeira posi��o da lista [0] cont�m o maior item encontrado. Ele ser� enviado para a �ltima posi��o da lista n�o-ordenada [raiz] 
		this->swap(0, raiz);
		//Toda a �rvore ser� reavaliada, a partir da posi��o inicial at� a �ltima posi��o da lista n�o-ordenada [raiz]
		//Como essa posi��o n�o � inclusiva, o elemento da lista na posi��o [raiz] n�o ser� mais avaliado, pois ele j� est� no lugar correto.
		this->heap(0, raiz);
	}

	this->ordenada = true;
}