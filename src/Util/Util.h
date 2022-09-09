#pragma once

#include <vector>

using namespace std;

namespace Util {

	int calcularSoma(vector<int>& lista) {

		int tamanho = (int)lista.size();
		int retorno = 0;

		for (int i = 0; i < tamanho; i++)
			retorno = retorno + lista[i];

		return retorno;
	}

}
