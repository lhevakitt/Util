#pragma once

#include <stdio.h>
#include <queue>
#include <map>

using namespace std;

/*
Node: 

Um n� de uma �rvore bin�ria. Cada n� possui um valor, e uma refer�ncia para o seu filho � esquerda (menor) e � direita (maior).
Ao se inserir um novo valor na �rvore, � necess�rio iniciar sempre � partir da raiz e sair comparando com todos os n�s at� que se encontre a 
posi��o devida do novo elemento.

Para os estudos, os valores ser�o reduzidos:
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
