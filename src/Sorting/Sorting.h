#pragma once

#include <iostream>

class Sorting {
	
protected:

	float* lista;

	int tamanho;

	bool ordenada;

public:

	Sorting(void);
	Sorting(float* lista_desordenada, int tamanho_da_lista);
	~Sorting();

	void setLista(float* nova_lista, int tamanho_da_lista);

	void swap(int posicao1, int posicao2);
	bool isListaVazia(void);
	void imprimirLista(void);
	
	virtual void ordenar(void) = 0;
	
};
