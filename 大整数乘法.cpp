#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	大整数乘法
*/
#define s 5
int* multi(int *num1, int size, int *num2, int size1) {
	int ss = size + size1;
	int* ret = new int[ss];
	memset(ret, 0, sizeof(int)*ss);
	for (int i = size1 - 1;i >= 0;--i) {
		int k = size1 - i - 1;
		for (int j = size - 1;j >= 0;--j) {
			ret[k++] += num1[i] * num2[j];
		}
	}
	for (int i = 0;i < size;++i) {
		if (ret[i] >= 10) {
			ret[i + 1] += ret[i] / 10;
			ret[i] %= 10;
		}
	}
	return ret;
}
int main()
{
	int num1[s] = {1,1,1,1,1};
	int num2[s] = {1,1,1,2,2};
	int* ret = multi(num1, s, num2, s);
	int flag = 0;
	for (int i = s * 2 - 1;i >= 0;--i) {
		if (flag==0&&ret[i] != 0)
			flag = 1;
		if(flag)
			cout <<ret[i];
	}
	delete[]ret;
	return 0;
}
