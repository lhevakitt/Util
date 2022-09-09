// _Teste_.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <time.h>
#include <Util.h>
#include <Questoes.h>

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

	Util::iniciar_lista(&lista, tamanho);

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

void Teste_SwapNodes(void) {

	//https://www.hackerrank.com/challenges/swap-nodes-algo/problem

	vector<vector<int>> indexes;
	vector<int> filhos;
	vector<int> queries;

	int tamanho = 0;
	int posicao = 0;
	int altura = 0;
	int valor = 0;
	
	Util::ler_arquivo_2("entradas/swappingNodes.txt", indexes, queries);

	Node* raiz = NULL;

	raiz = new Node();
	raiz->inserir(valor);
	raiz->setAltura(1);
	raiz->construirSubArvore(raiz, indexes);
	raiz->imprimirArvore();
	
	tamanho = (int)queries.size();
	for (posicao = 0; posicao < tamanho; posicao = posicao + 1) {
		altura = queries[posicao];
		raiz->trocarNodes(raiz, altura);

		printf("\nImprimir Arvore transversal\n");
		raiz->imprimirArvoreTransversal(raiz);
		printf("\n----------------------------\n");
	}

	raiz->imprimirVisaoVertical(raiz);

	delete raiz;	

}

void Teste_Brackets(void) {

	vector<string> entradas;
	vector<string> saidas;

	vector<string>::iterator it;

	int linhas = 0;
	int linha = 0;

	Util::ler_arquivo("entradas/input04.txt", entradas);
	linhas = Util::ler_arquivo("entradas/output04.txt", saidas);

	string teste = "[()][{}()][](){}([{}(())([[{}]])][])[]([][])(){}{{}{[](){}}}()[]({})[{}{{}([{}][])}]";

	Heap<char>* heap = NULL;
	
	int acertou = 0;
	int errou = 0;
	char valor = 0;
	bool erro = false;

	string resposta;
	string resultado;
	string entrada;

	heap = new Heap<char>(100);

	for (linha = 0; linha < linhas; linha++) {
		
		heap->resetarHeap();
		//entrada = teste;
		entrada = entradas[linha];
		resposta = saidas[linha];
		erro = false;

		for (int i = 0; i < entrada.length() && !erro; i++) {

			valor = entrada[i];

			switch (valor) {
			case '{':
			case '[':
			case '(':
				heap->inserir(valor);
				break;

			case '}':
				valor = heap->remover();
				erro = (valor != '{');
				break;
			case ']':
				valor = heap->remover();
				erro = (valor != '[');
				break;
			case ')':
				valor = heap->remover();
				erro = (valor != '(');
				break;
			}
		}

		erro = erro || (heap->getNumeroDeElementos() != 0);

		if (erro)
			resultado = "NO";
		else
			resultado = "YES";

		if (resultado.compare(resposta) == 0) {
			printf("[Linha %02d] Acertou! %s - %s\n", linha, resultado.c_str(), resposta.c_str());
			acertou++;
		}
		else {
			printf("[Linha %02d] ERROU! %s - %s\n", linha, resultado.c_str(), resposta.c_str());
			errou++;
		}
	}

	delete heap;
}


void Teste_Questoes(void) {

	vector<vector<int>> matriz;
	vector<int> numeros;
	vector<int> numeros2;
	vector<int> numeros3;

	int valor, resultado, resposta, certo = 0, errado = 0;
	//----------------------------------

	int n = 10;
	vector<vector<int>> queries;
	queries.push_back({ 2,6,8 });
	queries.push_back({ 3,5,7 });
	queries.push_back({ 1,8,1 });
	queries.push_back({ 5,9,15 });
	Questoes::arrayManipulation(n, queries);

	return;
	//----------------------------------


	numeros.push_back(2);
	numeros.push_back(3);
	numeros.push_back(7);
	numeros.push_back(8);
	numeros.push_back(11);
	//Questoes::twoSum(numeros, 9);
	numeros.clear();

	//----------------------------------

	for (int i = 0; i < 8; i++) {
		vector<int> linha;
		for (int j = 0; j < 8; j++) {
			valor = rand() % 3;
			linha.push_back(valor);
		}
		matriz.push_back(linha);
	}
	//Questoes::floodFill(matriz, 0, 0, 3);
	matriz.clear();

	//----------------------------------

	numeros.push_back(3);
	numeros.push_back(2);
	numeros.push_back(1);
	numeros.push_back(5);
	numeros.push_back(4);
	//Questoes::countKDifference(numeros, 2);
	numeros.clear();

	//----------------------------------

	numeros.push_back(3);
	numeros.push_back(1);
	numeros.push_back(2);
	numeros.push_back(2);
	numeros.push_back(2);
	numeros.push_back(1);
	numeros.push_back(3);
	//Questoes::countPairs(numeros, 2);
	numeros.clear();

	//-----------------------------------
	
	Util::equalStacksFile("entradas/equalStacks.txt", numeros, numeros2, numeros3);
	//Questoes::equalStacks(numeros, numeros2, numeros3);

	//-----------------------------------

	vector<vector<int>> twoStacksA, twoStacksB;
	vector<int> twoStacksMaxSums;
	vector<int> twoStacksRespostas;
	Util::twoStacks("entradas/twoStacks2.txt", twoStacksMaxSums, twoStacksA, twoStacksB);
	Respostas::twoStacks("saidas/twoStacks2.txt", twoStacksRespostas);

	for (int i = 0; i < twoStacksRespostas.size(); i++) {

		resposta = twoStacksRespostas[i];
		resultado = Questoes::twoStacks(twoStacksMaxSums[i], twoStacksA[i], twoStacksB[i]);

		if (resposta == resultado) {
			printf("[%d] CERTO!!\nResposta = %d\nResultado = %d\n\n", i, resposta, resultado);
			certo++;
		}			
		else {
			printf("[%d] ERRADO\nResposta = %d\nResultado = %d\n\n", i, resposta, resultado);
			errado++;
		}
			
	}

	//-----------------------------------

	for (int i = 0; i < 1; i++) {
		int numero = rand() % 10 + 1;
		//Questoes::uglyNumber(numero);
		//Questoes::nthCatalanNumber(numero);
	}

	//-----------------------------------

	printf("//----------------------------------");
	printf("\n[%d] Certos\n[%d] Errados\n", certo, errado);
	printf("//----------------------------------");

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

void teste(void) {
	int n = 2;
	vector<vector<int>> queries;

	queries.push_back({ 1,0,5 });
	queries.push_back({ 1,1,7 });
	queries.push_back({ 1,0,3 });
	queries.push_back({ 2,1,0 });
	queries.push_back({ 2,1,1 });

	Questoes::dynamicArray(n, queries);
}


void teste2(void) {
	
	//int* pilha = new int[100000];
	vector<int>pilha(10000);
	int posicaoAtual = 0, tamanhoAtual = 0, posicao = 0, temp = 0;
	int Q = 0, op = 0, v = 0;
	int min = INT32_MAX;
	cin >> Q;

	for (int q = 0; q < Q; q++) {
		cin >> op;

		if (op == 1) {
			cin >> v;
			
			posicao = posicaoAtual;
			pilha[posicaoAtual] = v;
			posicaoAtual++;

			while (posicaoAtual >= 2 && posicao >= 1 && pilha[posicao - 1] > pilha[posicao]) {
				temp = pilha[posicao - 1];
				pilha[posicao - 1] = pilha[posicao];
				pilha[posicao] = temp;
				posicao--;
			}
		}
		else if (op == 2) {
			cin >> v;
			
			posicao = -1;
			bool achou = false;
			do {
				posicao++;
				achou = pilha[posicao] == v;
			} while (!achou);
			
			posicaoAtual--;
			pilha[posicao] = pilha[posicaoAtual];

			while (posicaoAtual >= 2 && posicao + 1 < posicaoAtual && pilha[posicao] > pilha[posicao + 1]) {
				temp = pilha[posicao - 1];
				pilha[posicao - 1] = pilha[posicao];
				pilha[posicao] = temp;
				posicao++;
			}
			
		}
		else {
			int min = pilha[0];
			printf("%d\n", min);
		}

	}

}


void AVLTree(void) {

	vector<int> entrada = { 3,4,2,5,6 };

	int posicao = 0;
	int tamanho = entrada.size();

	node* raiz = NULL;

	for (posicao = 0; posicao < tamanho; posicao++) {
		raiz = Questoes::insertAVL(raiz, entrada[posicao]);
	}
}

int main()
{
	srand(time(NULL));
	
	AVLTree();
	//teste2();

	//Teste_Sorting<Quicksort>();
	//Teste_Sorting<Insertionsort>();
	//Teste_Sorting<Heapsort>();
	//Teste_Sorting<Mergesort>();
	//Teste_Sorting<Selectionsort>();
	//Teste_Sorting<Bubblesort>();
	//Teste_Heap();
	//Teste_Node();
	//Teste_SwapNodes();
	//Teste_Brackets();
	//Teste_Questoes();
	//oba();

	//Ponteiros();
	//teste();
}

