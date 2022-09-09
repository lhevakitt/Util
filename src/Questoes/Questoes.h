#pragma once

#include <map>
#include <vector>

using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

typedef struct node
{
	int val;
	struct node* left;
	struct node* right;
	int ht;
} node;

namespace Questoes {

	vector<int> initVector(void) {
		vector<int> retorno;
		retorno.push_back(1);
		return retorno;
	}
	static vector<int> buffer = initVector();

	/*
	Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
	You may assume that each input would have exactly one solution, and you may not use the same element twice.
	You can return the answer in any order.
	*/
	void twoSum(vector<int>& nums, int target) {

		vector<int> retorno;
		map<int,int> mapa;
		map<int, int>::iterator it;

		int tamanho = 0;
		int posicao = 0;
		int numero = 0;
		int diferenca = 0;
		int chave = 0;

		tamanho = (int)nums.size();
		for (posicao = 0; posicao < tamanho; posicao++) {
			numero = nums[posicao];
			diferenca = target - numero;
			it = mapa.find(diferenca);
			
			if (it != mapa.end()) {
				chave = mapa[diferenca];
				printf("[%d]%d + [%d]%d ", nums[posicao], posicao, nums[chave], chave);
				retorno.push_back(posicao);
				retorno.push_back(chave);
				break;
			}
			else
				mapa.insert(make_pair(numero, posicao));
		}
	}

	/*
	In MS-Paint, when we take the brush to a pixel and click, the color of the region of that pixel is replaced with a new selected color. 
	Following is the problem statement to do this task. 
	Given a 2D screen, location of a pixel in the screen and a color, replace color of the given pixel and all adjacent same colored pixels
	with the given color.
	*/
	void vizinhos(vector<vector<int>>& matriz, int x0, int y0, int novaCor, int corAntiga, vector<tuple<int, int>>& pixelsAlterados) {

		vector<int> linha;
		int cor = 0;

		matriz[x0][y0] = novaCor;
	
		for (int i = -1; i <= 1; i++) {
			
			if (x0 + i < 0 || x0 + i >= matriz.size())
				continue;

			linha = matriz[x0 + i];

			for (int j = -1; j <= 1; j++) {
				
				if (y0 + j < 0 || y0 + j >= linha.size())
					continue;
				
				cor = linha[y0 + j];

				if (cor == corAntiga) {
					tuple<int, int> ponto(x0 + i, y0 + j);
					pixelsAlterados.push_back(ponto);
				}
			}
		}
	}
	void floodFill(vector<vector<int>> matriz, int x0, int y0, int novaCor) {

		int x = 0;
		int y = 0;

		for (x = 0; x < matriz.size(); x++) {
			for (y = 0; y < matriz[x].size(); y++) {
				printf("%d, ", matriz[x][y]);
			}
			printf("\n");
		}
		printf("\n\n");

		vector<tuple<int,int>> pixelsAlterados;
		int cor = matriz[x0][y0];
				
		tuple<int, int> ponto(x0, y0);
		pixelsAlterados.push_back(ponto);

		do {

			ponto = pixelsAlterados[0];
			pixelsAlterados.erase(pixelsAlterados.begin());
			x = get<0>(ponto);
			y = get<1>(ponto);
			vizinhos(matriz, x, y, novaCor, cor, pixelsAlterados);

		} while (pixelsAlterados.size() > 0);

		for (x = 0; x < matriz.size(); x++) {
			for (y = 0; y < matriz[x].size(); y++) {
				printf("%d, ", matriz[x][y]);
			}
			printf("\n");
		}
	}

	/*
	Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
	https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
	*/
	int countKDifference(vector<int>& nums, int k) {

		int retorno = 0;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i+1; j < nums.size(); j++) {
			
				int diff = abs(nums[i] - nums[j]);

				if (diff == k)
					retorno++;
			}
		}

		printf("%d\n", retorno);
		return retorno;
	}

	/*
	Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, 
	such that nums[i] == nums[j] and (i * j) is divisible by k.
	https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/
	*/
	int countPairs(vector<int>& nums, int k) {

		int retorno = 0;
		bool ok1 = false;
		bool ok2 = false;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				ok1 = (nums[i] == nums[j]);
				if (!ok1)
					continue;
				ok2 = (i * j) % k == 0;

				if (ok1 && ok2)
					retorno++;
			}
		}

		printf("%d ", retorno);
		return retorno;
	}

	/*
	Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
	shows the first 11 ugly numbers. By convention, 1 is included. 
	Given a number n, the task is to find n’th Ugly number.
	https://www.geeksforgeeks.org/ugly-numbers/
	*/

	int uglyNumber(int n) {

		int tamanho = (int)buffer.size();
		int retorno = -1, ultimo = 0, numero = 0, proximoNumero = 0;

		bool ok2, ok3, ok5 = false;

		if (n > tamanho) {
			ultimo = buffer[tamanho - 1];
			for (int i = ultimo + 1; tamanho < n; i++) {
				
				numero = i;
				
				do {

					ok2 = ((numero % 2) == 0);
					ok3 = ((numero % 3) == 0);
					ok5 = ((numero % 5) == 0);

					proximoNumero = numero;

					if (ok2) 
						proximoNumero = proximoNumero / 2;
					if (ok3)
						proximoNumero = proximoNumero / 3;
					if (ok5)
						proximoNumero = proximoNumero / 5;
					
					numero = proximoNumero;

					if (numero == 1) {
						buffer.push_back(i);
						tamanho++;
						break;
					}
				} while (ok2 || ok3 || ok5);

			}
		}
		
		retorno = buffer[n - 1];
		
		for (int i = 0; i < buffer.size(); i++)
			printf("%d, ", buffer[i]);
		printf("\n[%d] = %d\n\n", n, retorno);
		return retorno;

	}

	/*
	The Catalan numbers are a sequence of natural numbers that occur in various counting problems, often involving recursively defined objects
	The nth Catalan number can be expressed directly in terms of binomial coefficients by
	C(n)= (2n)! / [ (n + 1)! * n! ] ou
	C(n) = C(n-1) * [2*(2n+1)] / (n+2)
	https://en.wikipedia.org/wiki/Catalan_number
	*/
	int nthCatalanNumber(int n) {

		int tamanho = (int)buffer.size();
		int retorno = -1, ultimo = 0, proximo = 0;

		if (n > tamanho) {

			for (int i = tamanho; tamanho < n; i++) {
				ultimo = buffer[i - 1];
				proximo = ultimo * (2 * (2 * i + 1)) / (i + 2);
				buffer.push_back(proximo);
				tamanho++;
			}
		}

		retorno = buffer[n - 1];

		for (int i = 0; i < buffer.size(); i++)
			printf("%d, ", buffer[i]);
		printf("\n[%d] = %d\n\n", n, retorno);
		return retorno;
	}

	/*
	You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. 
	You can change the height of a stack by removing and discarding its topmost cylinder any number of times.
	Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. 
	This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, 
	then return the height.
	https://www.hackerrank.com/challenges/equal-stacks/problem?isFullScreen=true
	*/

	int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {

		vector<vector<int>*> pilhas;
		vector<int>* pilhaAtual = NULL;
		int* topoAtual = NULL, *tamanhoAtual = NULL, *somaAtual = NULL;
		int topo1, topo2, topo3, soma1, soma2, soma3, tamanho1, tamanho2, tamanho3, index, menor, retorno = -1;
		bool ok = false;
		bool sair = false;

		pilhas.push_back(&h1);
		pilhas.push_back(&h2);
		pilhas.push_back(&h3);

		topo1 = 0;
		topo2 = 0;
		topo3 = 0;
		tamanho1 = (int)h1.size();
		tamanho2 = (int)h2.size();
		tamanho3 = (int)h3.size();
		soma1 = Util::calcularSoma(h1);
		soma2 = Util::calcularSoma(h2);
		soma3 = Util::calcularSoma(h3);

		menor = soma1 < soma2 ? soma1 : soma2;
		menor = menor < soma3 ? menor : soma3;

		while (retorno == -1 && !sair) {

			retorno = menor;

			for (index = 0; (index < 3) && (!sair); index++) {

				pilhaAtual = pilhas[index];

				switch (index) {
				case 0:
					topoAtual = &topo1;
					tamanhoAtual = &tamanho1;
					somaAtual = &soma1;
					break;
				case 1:
					topoAtual = &topo2;
					tamanhoAtual = &tamanho2;
					somaAtual = &soma2;
					break;
				case 2:
					topoAtual = &topo3;
					tamanhoAtual = &tamanho3;
					somaAtual = &soma3;
					break;
				}

				ok = ((*somaAtual) == menor);
			
				if (!ok) {

					while ((*topoAtual) < (*tamanhoAtual) && (*somaAtual) > menor) {
						(*somaAtual) -= pilhaAtual->at((*topoAtual));
						(*topoAtual)++;
					}

					if ((*somaAtual) > menor) {
						sair = true;
						retorno = 0;
					}

					if ((*somaAtual) < menor) {
						menor = (*somaAtual);
						retorno = -1;
						break;
					}
				}
			}
		}

		printf("%d\n", retorno);
		return retorno;

	}

	/*
	Alexa has two stacks of non-negative integers, stack  and stack  where index  denotes the top of the stack. 
	Alexa challenges Nick to play the following game:

	In each move, Nick can remove one integer from the top of either stack  or stack .
	Nick keeps a running sum of the integers he removes from the two stacks.
	Nick is disqualified from the game if, at any point, his running sum becomes greater than some integer  given at the beginning of the game.
	Nick's final score is the total number of integers he has removed from the two stacks.
	Given a, b, and maxSum for g games, find the maximum possible score Nick can achieve.
	https://www.hackerrank.com/challenges/game-of-two-stacks/problem?h_r=next-challenge&h_v=zen
	*/
	int twoStacks(int maxSum, vector<int> a, vector<int> b) {

		int retorno = 0;

		vector<int>* pilhaConferida = NULL, *pilhaAtual = NULL;
		int* somaAtual = NULL, *iAtual = NULL, *iConferido = NULL, *sizeAtual = NULL;
		int somaA, somaB, iA, iB, sizeA, sizeB;
		bool ok = false;

		iA = 0;
		iB = 0;
		sizeA = (int)a.size();
		sizeB = (int)b.size();
		somaA = Util::calcularSoma(a);
		somaB = Util::calcularSoma(b);

		if (somaA < somaB) {
			somaAtual = &somaA;
			iA = sizeA;
			iConferido = &iA;
			pilhaConferida = &a;
			iAtual = &iB;
			pilhaAtual = &b;
			sizeAtual = &sizeB;
		}
		else {
			somaAtual = &somaB;
			iB = sizeB;
			iConferido = &iB;
			pilhaConferida = &b;
			iAtual = &iA;
			pilhaAtual = &a;
			sizeAtual = &sizeA;
		}

		while ((*somaAtual) <= maxSum && (*iAtual) < (*sizeAtual)) {
			if ((*somaAtual) <= maxSum && iA + iB > retorno)
				retorno = iA + iB;
			(*somaAtual) += pilhaAtual->at(*iAtual);
			(*iAtual)++;
		}

		while ((*somaAtual) > maxSum && (*iConferido) > 0) {
			(*iConferido)--;
			(*somaAtual) -= pilhaConferida->at(*iConferido);

			while ((*somaAtual) <= maxSum && (*iAtual) < (*sizeAtual)) {
				if ((*somaAtual) <= maxSum && iA + iB > retorno)
					retorno = iA + iB;
				(*somaAtual) += pilhaAtual->at(*iAtual);
				(*iAtual)++;
			}
		}

		return retorno;
	}


	void f3(int x, int y, vector<vector<int>>& matriz, int* LA, int N, vector<int>& retorno) {

		//int i = f1(x, (*LA), N);
		//vector<int> linha = matriz[i];
		//int j = y % linha.size();
		////(*LA) = matriz[i][j];
		////retorno.push_back(*LA);
		//printf("x=%d, y=%d, i=%d, j=%d, size=%d\n", x, y, i, j, matriz.size());
	}

	vector<int> dynamicArray(int n, vector<vector<int>> queries) {

		int LA = 0;
		vector<vector<int>> matriz(n);
		vector<int> retorno;

		int i = 0, j = 0;

		for (int q = 0; q < queries.size() - 1; q++) {
			int op = queries[q][0];
			int x = queries[q][1];
			int y = queries[q][2];

			if (op == 1) {
				i = (x ^ LA) % n;
				matriz[i].push_back(y);
			}
			else {
				i = (x ^ LA) % n;
				j = y % matriz[i].size();
				LA = matriz[i][j];
				retorno.push_back(LA);
			}
		}

		return retorno;
	}

	long arrayManipulation(int n, vector<vector<int>> queries) {

		vector<long> R(n, 0);
		long max = INT32_MIN;
		int a, b;
		long k = 0;
		for (int i = 0; i < queries.size(); i++) {
			a = queries[i][0] - 1;
			b = queries[i][1] - 1;
			k = queries[i][2];

			for (int j = a; j <= b; j++) {
				R[j] += k;
				if (R[j] > max) {
					max = R[j];
				}
			}
		}

		printf("%d\n", max);
		return max;
	}

	
	/*
	Given the pointer to the head node of a linked list, change the next pointers of the nodes so that their order is reversed. 
	The head pointer given may be null meaning that the initial list is empty.
	https://www.hackerrank.com/challenges/reverse-a-linked-list/problem?isFullScreen=true&h_r=next-challenge&h_v=zen
	*/
	//Variaveis
	SinglyLinkedListNode * novoH = NULL, *temp = NULL;
	//Método
	SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {

		if (llist->next != NULL) {
			reverse(llist->next);
		}
		if (novoH == NULL) {
			novoH = llist;
		}
		else {
			temp = novoH;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = llist;
			llist->next = NULL;
		}
		return novoH;
	}

	/*
	An AVL tree (Georgy Adelson-Velsky and Landis' tree, named after the inventors) is a self-balancing binary search tree. 
	In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, 
	rebalancing is done to restore this property.

	We define balance factor for each node as :
	balanceFactor = height(left subtree) - height(right subtree)
	
	The balance factor of any node of an AVL tree is in the integer range [-1,+1]. 
	If after any modification in the tree, the balance factor becomes less than −1 or greater than +1, 
	the subtree rooted at this node is unbalanced, and a rotation is needed.
	
	You are given a pointer to the root of an AVL tree. 
	You need to insert a value into this tree and perform the necessary rotations to ensure that it remains balanced.
	https://www.hackerrank.com/challenges/self-balancing-tree/problem?isFullScreen=true
	*/
	
	void R1(node *root, bool left) {
		
		node *temp = NULL;

		if (left) {
			temp = root;
			root = root->left;
			root->right = temp;
			temp->left = NULL;
		}
		else {
			temp = root;
			root = root->right;
			root->left = temp;
			temp->right = NULL;
		}
		temp->ht = 0;
		root->ht = 0;
	}
	void R2(node *root, bool left) {

		node *temp = NULL;

		if (left) {
			temp = root;
			root = root->left->right;
			root->right = temp;
			root->left = temp->left;
			temp->left->right = NULL;
			temp->left = NULL;
		}
		else {
			temp = root;
			root = root->right->left;
			root->left = temp;
			root->right = temp->right;
			temp->right->left = NULL;
			temp->right = NULL;
		}
		root->ht = 0;
		root->left->ht = 0;
		root->right->ht = 0;
	}
	void rotate(node *root, bool left) {
		
		int b1 = root->ht;
		int b2 = 0;

		b2 = (b1 == -1) ? root->right->ht : root->left->ht;

		if (b1 == -1 && b2 == -1) {
			R1(root, false);
		}
		else if (b1 == 1 && b2 == 1) {
			R1(root, true);
		} 
		else if (b1 = -1 && b2 == 1) {
			R2(root, true);
		}
		else if (b1 == 1 && b2 == -1) {
			R2(root, false);
		}

	}
	int insertVal(node *root, int val, bool left) {

		int retorno = 0;

		if (root == NULL) {
			return 0;
		}

		if (left) {

			if (root->left == NULL) {
				root->left = new node();
				root->left->val = val;
				root->left->ht = 0;
				root->ht += 1;
				retorno = root->ht;
			}
			else {
				if (val > root->right->val) {
					retorno = insertVal(root->right, val, false);
					if (retorno + root->ht == 2) {
						rotate(root, false);
					}
					else {
						root->ht = retorno;
					}
				}
				else {
					retorno = insertVal(root->left, val, true);
					if (retorno + root->ht == 2) {
						rotate(root, true);
					}
					else {
						root->ht = retorno;
					}
				}
				
			}
		}
		else {

			if (root->right == NULL) {
				root->right = new node();
				root->right->val = val;
				root->right->ht = 0;
				root->ht += -1;
				retorno = root->ht;
			}
			else {
				if (val > root->right->val) {
					retorno = insertVal(root->right, val, false);
					if (retorno + root->ht == -2) {
						rotate(root, false);
					}
					else {
						root->ht = retorno;
					}
				}
				else {
					retorno = insertVal(root->left, val, true);
					if (retorno + root->ht == -2) {
						rotate(root, true);
					}
					else {
						root->ht = retorno;
					}
				}
				
			}
		}

		return retorno;
		
	}
	node * insertAVL(node * root, int val)
	{
		node* retorno;

		if (root == NULL) {
			retorno = new node();
			retorno->val = val;
			retorno->ht = 0;

			return retorno;
		}

		if (val > root->val) {
			insertVal(root, val, false);
		} 
		else {
			insertVal(root, val, true);
		}

		return root;
	}


}


