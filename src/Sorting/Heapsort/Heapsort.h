#pragma once

#include <Sorting/Sorting.h>

/*
Heapsort:

Para esse algoritmo, entenda a lista como uma �rvore bin�ria:
lista = {A(0), B(1), C(2), D(3), E(4), F(5), G(6)}

			A(0)
	B(1)			C(2)
D(3)	E(4)	F(5)	G(6)

Para cada posi��o [x] da lista, seus filhos (se eles existirem na �rvore) est�o nas posi��es:
[2x + 1] (filho � esquerda)
[2x + 2] (filho � direita)

1) A posi��o inicial � o index da �ltima sub-arvore (n�o necessariamente ela precisa ter filhos).
2) Verifique se o pai da sub-�rvore inicial � maior que os seus filhos. Caso n�o seja, troque-os de lugar
3) Em caso de troca de lugar, verifique todas as sub-arvores abaixo do filho trocado
4) Ap�s verificar todas as sub-�rvores, volte uma posi��o na �rvore para repetir o processo com todas as outras sub-�rvores
5) Ao chegar na raiz (que � o primeiro elemento da lista e dever� conter o maior elemento da �rvore), troque de lugar com o �ltimo elemento da lista.
6) O elemento enviado para �ltima posi��o da lista j� est� na sua posi��o correta e n�o precisar� ser mais avaliado.
7) Repita a an�lise da �rvore, agora tendo como posi��o inicial a raiz da �rvore e como posi��o final a posi��o imediatamente anterior ao do elemento trocado no passo anterior

Complexidade:
Melhor caso: O[n * log(n)]
Pior caso: O[n * log(n)]

*/

class Heapsort : public Sorting {

private:

public:

	Heapsort(void);
	Heapsort(float* lista_desordenada, int tamanho);
	~Heapsort(void);

	void heap(int posicao, int tamanhoMaximo);

	void ordenar(void);

};

