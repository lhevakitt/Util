#pragma once

#include <stdio.h>
#include <queue>
#include <map>

using namespace std;

/*
Node: 

Um nó de uma árvore binária. Cada nó possui um valor, e uma referência para o seu filho à esquerda (menor) e à direita (maior).
Ao se inserir um novo valor na árvore, é necessário iniciar sempre à partir da raiz e sair comparando com todos os nós até que se encontre a 
posição devida do novo elemento.

Para os estudos, os valores serão reduzidos:
1 < data < 20
1 < numeroDeNodes < 20

*/

class Node {

private:

	int data;
	Node* left;
	Node* right;

	int altura;
	int distanciaAoCentro;

public:

	Node(void);
	Node(int valor, int alturaNaArvore);
	~Node(void);

	void criarNode(int valor, int alturaNaArvore);

	void setNodeEsquerdo(Node* node);
	void setNodeDireito(Node* node);
	void setNodeEsquerdo(int valor, int alturaNaArvore, int distanciaDoPai);
	void setNodeDireito(int valor, int alturaNaArvore, int distanciaDoPai);
	void setAltura(int valor);
	void setDistanciaAoCentro(int valor);

	Node* getNodeEsquerdo(void);
	Node* getNodeDireito(void);
	int getData(Node* node);
	int getAltura(Node* node);
	int getDistanciaAoCentro(Node* node);

	void inserir(int valor);
	void construirSubArvore(Node* raiz, vector<vector<int>>& dados);

	int getAlturaDaArvore(Node* root);
	void trocarNodes(Node* raiz, int alturaDesejada);

	void imprimirArvore(void);
	void imprimirArvorePorNivel(Node* raiz);
	void imprimirArvoreTransversal(Node* raiz);
	void imprimirVisaoVertical(Node* raiz);
	void imprimirTopView(Node* raiz);

};
