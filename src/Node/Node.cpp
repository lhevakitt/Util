#include "Node.h"


Node::Node(void) {

	this->criarNode(0, -1);
}

Node::Node(int valor, int alturaNaArvore) {

	this->criarNode(valor, alturaNaArvore);
}

Node::~Node(void) {}


void Node::criarNode(int valor, int alturaNaArvore) {
	
	this->data = valor;
	this->left = NULL;
	this->right = NULL;

	this->altura = alturaNaArvore + 1;
	this->distanciaAoCentro = 0;
}


void Node::setNodeEsquerdo(Node* node) { this->left = node; }

void Node::setNodeDireito(Node* node) { this->right = node; }

void Node::setNodeEsquerdo(int valor, int alturaNaArvore, int distanciaDoPai) {

	if (this->left == NULL)
		this->left = new Node(valor, alturaNaArvore);

	this->left->setDistanciaAoCentro(distanciaDoPai - 1);
}

void Node::setNodeDireito(int valor, int alturaNaArvore, int distanciaDoPai) {
	
	if (this->right == NULL)
		this->right = new Node(valor, alturaNaArvore);

	this->right->setDistanciaAoCentro(distanciaDoPai + 1);
}

void Node::setAltura(int valor) { this->altura = valor; }

void Node::setDistanciaAoCentro(int valor) { this->distanciaAoCentro = valor; }


Node* Node::getNodeEsquerdo(void) {	return this->left; }

Node* Node::getNodeDireito(void) { return this->right; }

int Node::getData(Node* node) {
	
	int retorno = -1;

	if (node == NULL)
		return retorno;
	
	retorno = node->data;

	return retorno;
}

int Node::getAltura(Node* node) {
	
	int retorno = -1;

	if (node == NULL)
		return retorno;

	retorno = node->altura;
	return retorno;
}

int Node::getDistanciaAoCentro(Node* node) {

	int retorno = -1;

	if (node == NULL)
		return retorno;

	retorno = node->distanciaAoCentro;

	return retorno;
}


void Node::inserir(int valor) {

	if (this->data != 0) {
		if (valor > this->data) {
			if (this->right == NULL)
				this->setNodeDireito(valor, this->altura, this->distanciaAoCentro);
			else
				this->right->inserir(valor);
		}
		else {
			if (this->left == NULL)
				this->setNodeEsquerdo(valor, this->altura, this->distanciaAoCentro);
			else
				this->left->inserir(valor);
		}
	}
	else {
		this->data = valor;
	}
}

void Node::construirSubArvore(Node* raiz, vector<vector<int>>& dados) {

	queue<Node*>* fila = NULL;

	Node* pai = NULL;
	Node* filho = NULL;
		
	int valorEsquerdo = 0;
	int valorDireito = 0;
	int alturaDoPai = 0;
	int distanciaDoPai = 0;

	if (dados.empty() || this->data == -1)
		return;

	fila = new queue<Node*>();
	fila->push(raiz);

	while (! fila->empty() && ! dados.empty()) {

		pai = fila->front();
		fila->pop();

		valorEsquerdo = dados[0][0];
		valorDireito = dados[0][1];

		dados.erase(dados.begin());
		
		alturaDoPai = pai->getAltura(pai);
		distanciaDoPai = pai->getDistanciaAoCentro(pai);

		if (valorEsquerdo != -1) {
			pai->setNodeEsquerdo(valorEsquerdo, alturaDoPai, distanciaDoPai);
			filho = pai->getNodeEsquerdo();
			fila->push(filho);
		}

		if (valorDireito != -1) {
			pai->setNodeDireito(valorDireito, alturaDoPai, distanciaDoPai);
			filho = pai->getNodeDireito();
			fila->push(filho);
		}
	}

	delete fila;

}


int Node::getAlturaDaArvore(Node* root) {

	int retorno = -1;

	Node* left = NULL;
	Node* right = NULL;
	int alturaEsquerda = 0;
	int alturaDireita = 0;

	if (root == NULL)
		return retorno;

	left = root->getNodeEsquerdo();
	right = root->getNodeDireito();
	alturaEsquerda = root->getAlturaDaArvore(left);
	alturaDireita = root->getAlturaDaArvore(right);

	retorno = alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita;
	retorno = retorno + 1;

	return retorno;
}

void Node::trocarNodes(Node* raiz, int alturaDesejada) {

	Node* nodeEsquerdo = NULL;
	Node* nodeDireito = NULL;

	int altura = 0;

	if (raiz == NULL)
		return;

	altura = raiz->getAltura(raiz);
	nodeEsquerdo = raiz->getNodeEsquerdo();
	nodeDireito = raiz->getNodeDireito();

	if (altura % alturaDesejada == 0) {
		raiz->setNodeEsquerdo(nodeDireito);
		raiz->setNodeDireito(nodeEsquerdo);
	}

	nodeEsquerdo->trocarNodes(nodeEsquerdo, alturaDesejada);
	nodeDireito->trocarNodes(nodeDireito, alturaDesejada);

}


void Node::imprimirArvore(void) {

	printf("[Nivel %d] %d\n", this->altura, this->data);

	if (this->left != NULL)
		this->left->imprimirArvore();

	if (this->right != NULL)
		this->right->imprimirArvore();
}

void Node::imprimirArvorePorNivel(Node* raiz) {

	queue<Node*>* fila = NULL;

	Node* pai = NULL;
	Node* filho = NULL;

	int valor = 0;

	fila = new queue<Node*>();
	fila->push(raiz);

	while (!fila->empty()) {

		pai = fila->front();
		fila->pop();
		
		valor = pai->getData(pai);
		printf("%d ", valor);

		filho = pai->getNodeEsquerdo();
		if (filho != NULL)
			fila->push(filho);
		
		filho = pai->getNodeDireito();
		if (filho != NULL)
			fila->push(filho);
	}

	delete fila;

}

void Node::imprimirArvoreTransversal(Node* raiz) {

	Node* esquerdo = NULL;
	Node* direito = NULL;

	int valor = 0;

	if (raiz == NULL)
		return;

	esquerdo = raiz->getNodeEsquerdo();
	direito = raiz->getNodeDireito();
	valor = raiz->getData(raiz);

	raiz->imprimirArvoreTransversal(esquerdo);
	printf("%d ", valor);
	raiz->imprimirArvoreTransversal(direito);

}

void Node::imprimirVisaoVertical(Node* raiz) {

	//https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/

	map<int, vector<Node*>*> tabela;
	map<int, vector<Node*>*>::iterator it;
	vector<Node*>* lista = NULL;
	vector<Node*>::iterator it2;
	queue<Node*>* fila = NULL;
	
	Node* pai = NULL;
	Node* filho = NULL;

	int distancia = 0;
	int valor = 0;

	if (raiz == NULL)
		return;

	fila = new queue<Node*>();
	fila->push(raiz);

	while (!fila->empty()) {

		pai = fila->front();
		fila->pop();

		distancia = pai->getDistanciaAoCentro(pai);
		it = tabela.find(distancia);

		if (it == tabela.end()) {
			lista = new vector<Node*>();
			tabela.insert(make_pair(distancia, lista));
		}
		else
			lista = tabela.at(distancia);

		lista->push_back(pai);

		filho = pai->getNodeEsquerdo();
		if (filho != NULL)
			fila->push(filho);

		filho = pai->getNodeDireito();
		if (filho != NULL)
			fila->push(filho);
	}

	for (it = tabela.begin(); it != tabela.end(); it++) {
		distancia = it->first;
		lista = it->second;

		printf("[%d] - ", distancia);
		for (it2 = lista->begin(); it2 != lista->end(); it2++) {
			pai = (*it2);
			valor = pai->getData(pai);

			printf("%d ", valor);
		}
		printf("\n");
	}

	delete lista;
	delete fila;
}

void Node::imprimirTopView(Node* raiz) {

	//https://www.hackerrank.com/challenges/tree-top-view/problem

	map<Node*, int> mapa;
	map<int, Node*> visao;
	queue<Node*>* fila = new queue<Node*>();
	int distancia = 0;

	fila->push(raiz);
	mapa.insert(make_pair(raiz, distancia)); //Mapa para calcular a distancia de cada Node ao centro da árvore 
	visao.insert(make_pair(distancia, raiz));//Mapa com os Nodes que serão impressos ao final

	while (!fila->empty()) {

		Node* temp = fila->front();
		Node* candidato = NULL;
		fila->pop();
		int distanciaPai = mapa[temp];

		if (temp->left != NULL) {
			fila->push(temp->left);
			mapa.insert(make_pair(temp->left, distanciaPai - 1));
			if (visao.find(distanciaPai - 1) == visao.end())
				visao.insert(make_pair(distanciaPai - 1, temp->left));
		}
		if (temp->right != NULL) {
			fila->push((temp->right));
			mapa.insert(make_pair(temp->right, distanciaPai + 1));
			if (visao.find(distanciaPai + 1) == visao.end())
				visao.insert(make_pair(distanciaPai + 1, temp->right));
		}
	}

	map<int, Node*>::iterator it;
	for (it = visao.begin(); it != visao.end(); it++) {
		printf("[%d] %d ", it->first, it->second->data);
	}

	delete fila;

}