#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	Z字形编排-图像编排
*/
#define s 8
int main()
{
	int matrix[s][s] = { 0 };//原矩阵
	int a[s][s] = { 0 };//新矩阵
	int i, j, x, y, value = 0;
	int *p = &matrix[0][0];
	for (i = 0;i < s*s;i++)
		*p++ = i;
	cout << "原始矩阵如下：" << endl;
	for (i = 0;i < s;++i) {
		for (j = 0;j < s;++j) {
			cout << setw(4) << *(*(matrix + i) + j);
		}
		cout << endl;
	}
	i = 0;j = 0;
	for (x = 0;x < s;++x) {
		for (y = 0;y < s;++y) {
			*(*(a + i) + j) = *(*(matrix + x) + y);
			if ((i == 0 || i == 7) && j % 2 == 0) {
				j++;
			}
			else if ((j == 0 || j == 7) && i % 2 == 1) {
				i++;
			}
			else
			{
				if ((i + j) % 2 == 0) {
					i--;
					j++;
				}
				else if((i + j) % 2 == 1)
				{
					i++;
					j--;
				}
			}
		}
	}
	cout << "编排之后的矩阵如下：" << endl;
	for (i = 0;i < s;++i) {
		for (j = 0;j < s;++j) {
			cout << setw(4) << *(*(a + i) + j);
		}
		cout << endl;
	}

	return 0;
}
