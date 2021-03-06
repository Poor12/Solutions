#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	幻方 一居上行正中央，依次斜填切莫忘，上出框时向下放，右出框时向左放，排重便在下格填，右上排重一个样
*/

int main()
{
	cout << "请输入幻方大小n（奇数）:";
	int n = 1;
	cin >> n;
	cout << endl;
	int **a = new int*[n];
	for (int i = 0;i < n;++i) {
		a[i] = new int[n];
		memset(a[i], 0, n * sizeof(int));
	}
	int row = 0;
	int col = n / 2;
	for (int i = 1;i <= n * n;++i) {
		a[row][col] = i;
		row--;
		col++;
		if (row < 0 && col >= n) 
		{
			col--;
			row += 2;
		}
		else if (row < 0) {
			row = n - 1;
		}
		else if (col >= n) {
			col = 0;
		}
		else if (a[row][col] != 0) {
			col--;
			row += 2;
		}
	}
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j)
			cout << setw(6) << a[i][j];
		cout << endl;
	}
	for (int i = n;i > 0;)
		delete[] a[--i];
	delete[]a;
	return 0;
}