#pragma once

#include <fstream>
#include <vector>

using namespace std;

namespace Entradas {

	void iniciar_lista(float* lista[], int tamanho) {

		if (tamanho <= 0)
			return;

		std::printf("Criando uma nova lista de tamanho %d\n", tamanho);
		*lista = new float[tamanho];

		for (int x = 0; x < tamanho; x = x + 1) {
			(*lista)[x] = (float)rand();
			std::printf("[%d] - %.0f\n", x, (*lista)[x]);
		}
		(*lista)[0] = 2;
		(*lista)[1] = 4;
		(*lista)[2] = 0;
		//(*lista)[3] = 8;
		//(*lista)[4] = 9;
	}

	int ler_arquivo(string nome, vector<string>& dados) {

		ifstream entrada(nome);

		string linha;
		char buffer[1000];
		int linhas = 0;

		if (!entrada.is_open())
			return linhas;

		entrada >> linhas;

		for (int i = 0; i < linhas; i++) {
			entrada >> buffer;
			linha = string(buffer);

			dados.push_back(linha);
			//printf("%s", linha.c_str());
		}

		entrada.close();

		return linhas;
	}

	void reverseLinkedList(string nome, int& caseTests, vector<vector<int>>& listas) {

		//https://www.hackerrank.com/challenges/reverse-a-linked-list/problem?isFullScreen=true&h_r=next-challenge&h_v=zen

		ifstream arquivo(nome);

		if (!arquivo.is_open())
			return;

		int tamanho = 0, item = 0;
		arquivo >> caseTests;

		for (int i = 0; i < caseTests; i++) {
			arquivo >> tamanho;
			vector<int> lista;

			for (int j = 0; j < tamanho; j++) {
				arquivo >> item;
				lista.push_back(item);
			}
			listas.push_back(lista);
		}
	}

	void swapNodesList(string nome, vector<vector<int>>& dados, vector<int>& operacoes) {

		//https://www.hackerrank.com/challenges/swap-nodes-algo/problem

		ifstream arquivo(nome);

		int numeroDeNodes = 0;
		int numeroDeOperacoes = 0;
		int valor = 0;
		int posicao = 0;

		if (!arquivo.is_open())
			return;

		arquivo >> numeroDeNodes;
		for (posicao = 0; posicao < numeroDeNodes; posicao = posicao + 1) {

			vector<int> filhos;

			arquivo >> valor;
			filhos.push_back(valor);
			arquivo >> valor;
			filhos.push_back(valor);

			dados.push_back(filhos);
		}

		arquivo >> numeroDeOperacoes;
		for (posicao = 0; posicao < numeroDeOperacoes; posicao = posicao + 1) {
			arquivo >> valor;
			operacoes.push_back(valor);
		}

		arquivo.close();
	}

	void equalStacksFile(string nome, vector<int>& h1, vector<int>& h2, vector<int>& h3) {

		//https://www.hackerrank.com/challenges/equal-stacks/problem

		ifstream arquivo(nome);

		if (!arquivo.is_open())
			return;

		int h1Size, h2Size, h3Size, valor;

		arquivo >> h1Size;
		arquivo >> h2Size;
		arquivo >> h3Size;

		for (int i = 0; i < h1Size; i++) {
			arquivo >> valor;
			h1.push_back(valor);
		}
		for (int i = 0; i < h2Size; i++) {
			arquivo >> valor;
			h2.push_back(valor);
		}
		for (int i = 0; i < h3Size; i++) {
			arquivo >> valor;
			h3.push_back(valor);
		}

		arquivo.close();
	}

	void twoStacks(string nome, vector<int>& maxSum, vector<vector<int>>& A, vector<vector<int>>& B) {

		//https://www.hackerrank.com/challenges/game-of-two-stacks/problem?h_r=next-challenge&h_v=zen

		ifstream arquivo(nome);

		if (!arquivo.is_open())
			return;

		A.clear();
		B.clear();

		int numeroDeJogos, valor, index, tamanhoA, tamanhoB;

		arquivo >> numeroDeJogos;

		for (index = 0; index < numeroDeJogos; index++) {

			vector<int> a;
			vector<int> b;

			int maximo = 0;

			arquivo >> tamanhoA;
			arquivo >> tamanhoB;
			arquivo >> maximo;

			maxSum.push_back(maximo);

			for (int i = 0; i < tamanhoA; i++) {
				arquivo >> valor;
				a.push_back(valor);
			}
			A.push_back(a);

			for (int i = 0; i < tamanhoB; i++) {
				arquivo >> valor;
				b.push_back(valor);
			}
			B.push_back(b);

		}

		arquivo.close();

	}

}

namespace Respostas {

	void twoStacks(string nome, vector<int>& respostas) {

		//https://www.hackerrank.com/challenges/game-of-two-stacks/problem?h_r=next-challenge&h_v=zen

		ifstream arquivo(nome);

		int resposta = 0;

		if (!arquivo.is_open())
			return;

		respostas.clear();

		while (!arquivo.eof()) {
			arquivo >> resposta;
			respostas.push_back(resposta);
		}

		arquivo.close();
	}

}