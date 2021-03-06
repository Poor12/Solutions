#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;


const int MAX = 10010;
typedef struct node* Tree;
struct node {
	Tree left, right;
	int data;
	node(int d) {
		data = d;
		left = right = nullptr;
	}
};

int M, N, K;
int in[MAX];
int pre[MAX];
unordered_map<int, int> posin;
int U, V, A, posU, posV;
int findU, findV;

Tree CreatTree(int preL, int preR, int inL, int inR);
void outputnotfind();
void findA(Tree root);


int main() {
	scanf("%d%d", &M, &N);
	int i;
	for (i = 0;i < N;++i) {
		scanf("%d", &in[i]);
		posin[in[i]] = i;
	}
	for (i = 0;i < N;++i) {
		scanf("%d", &pre[i]);
	}

	Tree root = nullptr;
	root = CreatTree(0, N - 1, 0, N - 1);
	//	printf("%d",root->data);
	for (i = 0;i < M;++i) {
		scanf("%d%d", &U, &V);
		findU = posin.count(U);
		findV = posin.count(V);
		if (findU == 0 || findV == 0) {
			outputnotfind();
			continue;
		}
		posU = posin[U];
		posV = posin[V];
		findA(root);
		if (A != U && A != V) {
			printf("LCA of %d and %d is %d.\n", U, V, A);
			continue;
		}
		if (A == U) {
			printf("%d is an ancestor of %d.\n", U, V);
			continue;
		}
		else {
			printf("%d is an ancestor of %d.\n", V, U);
		}
	}
	return 0;

}

Tree CreatTree(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return nullptr;
	}
	if (preL == preR) {
		return new struct node(pre[preL]);
	}
	int mypos = posin[pre[preL]];
	int leftlen = mypos - inL;
	Tree T = new struct node(pre[preL]);
	T->left = CreatTree(preL + 1, preL + leftlen, inL, mypos - 1);
	T->right = CreatTree(preL + leftlen + 1, preR, mypos + 1, inR);
	return T;
}


void outputnotfind() {
	if (!findU && !findV) {
		printf("ERROR: %d and %d are not found.\n", U, V);
		return;
	}
	if (findU == 0) {
		printf("ERROR: %d is not found.\n", U);
	}
	else {
		printf("ERROR: %d is not found.\n", V);
	}
}

void findA(Tree root)
{
	if (!root)
		return;
	A = root->data;
	int posroot = posin[A];
	if (posU == posroot || posV == posroot)
		return;
	if (posU<posroot&&posV>posroot)
		return;
	if (posU > posroot&&posV < posroot)
		return;
	if (posU < posroot&&posV < posroot)
		findA(root->left);
	else
	{
		findA(root->right);
	}
}