#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	POJ 1316 筛选模拟，先把所有可能解组成一个筛，再把不符合条件的一个个除去
*/
#define N 10000
unsigned g[N];
unsigned sum_of_digits(unsigned n) {
	if (n < 10)
		return n;
	else
		return (n / 10) + sum_of_digits(n % 10);//  /与%可互换
}
void generate_sequence(unsigned n) {	//构造整数n的无限增量序列,g[n]等于n的某一个自数
	while (n)
	{
		unsigned next = n + sum_of_digits(n);
		if (next >= N || g[next] != next)
			return;
		g[next] = n;
		n = next;
	}
}
int main()
{
	unsigned n;
	for (n = 1;n < N;++n)
		g[n] = n;	//假设所有数均为自数
	for (n = 1;n < N;++n)
		generate_sequence(n);
	for (n = 1;n < N;++n)
		if (g[n] == n)
			printf("%u\n", n);
	
	return 0;
}
