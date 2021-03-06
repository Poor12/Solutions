
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
//组合数
long long C(int n, int m)
{
	if (m < n - m)
		m = n - m;
	long long ans = 1;
	for (int i = m + 1;i <= n;++i)
		ans *= i;
	for (int i = 1;i <= n - m;++i)
		ans /= i;
	return ans;
}
int is_prime(int n)
{
	if (n <= 1)
		return 0;
	int m = floor(sqrt(n) + 0.5);
	for (int i = 2;i <= m;++i)
		if (n%i == 0)
			return 0;
	return 1;
}
void swap(int *a, int *b)
{
	int *t = 0;
	*t = *a;
	*a = *b;
	*b = *t;
}
//数组作为参数和返回值
//计算左闭右开区间内的元素和
int sum(int *begin, int *end)
{
	int n = end - begin;
	int ans = 0;
	for (int i = 0;i < n;++i)
		ans += begin[i];
	return ans;
}
int sum2(int *begin, int *end)
{
	int *p = begin;
	int ans = 0;
	for (int *p = begin;p != end;++p)
		ans += *p;
	return ans;
}