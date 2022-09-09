// _Teste_.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <time.h>
#include <Util/Util.h>

#include <Sorting/Quicksort/Quicksort.h>
#include <Sorting/Insertionsort/Insertionsort.h>
#include <Sorting/Heapsort/Heapsort.h>
#include <Sorting/Mergesort/Mergesort.h>
#include <Sorting/Selectionsort/Selectionsort.h>
#include <Sorting/Bubblesort/Bubblesort.h>
#include <Heap/Heap.cpp> //Classe Template precisa incluir o .cpp
#include <Node/Node.h>


template <class Metodo>
void Teste_Sorting(void) {

	Metodo* sort = NULL;

	float* lista = NULL;
	int tamanho = 3;

	Entradas::iniciar_lista(&lista, tamanho);

	sort = new Metodo(lista, tamanho);
	
	sort->ordenar();
	sort->imprimirLista();

	delete (Metodo*)sort;
}

void Teste_Heap(void) {

	Heap<int>* heap = new Heap<int>();

	int tamanho = 0;
	int posicao = 0;
	int valor = 0;

	tamanho = heap->getNumeroDeElementos();
	printf("A heap possui %d Elementos\n", tamanho);

	for (posicao = 0; posicao < 5; posicao = posicao + 1)
		heap->inserir(posicao);

	tamanho = heap->getNumeroDeElementos();
	printf("A heap possui %d Elementos:\n", tamanho);

	for (posicao = 0; posicao < 5; posicao = posicao + 1) {
		valor = heap->remover();
		printf("%d ", valor);
	}
		
}

void Teste_Node(void) {

	Node* node = node = new Node();

	int altura = 0;
	int n = 7;
	int data[] = { 3,2,5,1,4,6,7 };

	int posicao = 0;

	for (posicao = 0; posicao < n; posicao = posicao + 1) 
		node->inserir(data[posicao]);
	
	node->imprimirArvore();
	
	altura = node->getAlturaDaArvore(node);
	printf("Altura da arvore: %d\n", altura);

	printf("\n----------------------------\n");
	printf("Imprimir Arvore por nivel\n");
	node->imprimirArvorePorNivel(node);
	printf("\n----------------------------\n");

	printf("Imprimir Arvore transversal\n");
	node->imprimirArvoreTransversal(node);
	printf("\n----------------------------\n");

	printf("Imprimir Visao Vertical\n");
	//node->imprimirVisaoVertical(node);
	printf("\n----------------------------\n");

	printf("Imprimir TopView\n");
	node->imprimirTopView(node);
	printf("\n----------------------------\n");
}

//-----------------------------------

void f1(int a, int& b, int* c) {

	a++;
	b++;
	(*c)++;

}
void Ponteiros(void) {
	
	int a = 0;
	int b = 0;
	int c = 0;

	f1(a, b, &c);

	printf("%d, %d, %d\n", a, b, c);

}


int main()
{
	srand((unsigned int)time(NULL));

	//Teste_Sorting<Quicksort>();
	//Teste_Sorting<Insertionsort>();
	//Teste_Sorting<Heapsort>();
	//Teste_Sorting<Mergesort>();
	//Teste_Sorting<Selectionsort>();
	//Teste_Sorting<Bubblesort>();
	//Teste_Heap();
	//Teste_Node();
	
	//Ponteiros();
}

