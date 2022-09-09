#pragma once

#include <stdint.h>

template <class Elemento>
class Heap {

private:

	Elemento* lista;

	int tamanhoDaLista;
	int numeroDeElementos;

public:

	Heap(void);
	Heap(int tamanhoDaHeap);
	~Heap(void);

	int getNumeroDeElementos(void);

	void expandirLista(void);

	void inserir(Elemento item);
	Elemento remover(void);
	void resetarHeap(void);

};