#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
POJ2739-INPUT
*/
const int n = 10000,maxp=2000;
int prime[maxp], total = 0;
bool isprime(int k) {
	for (int i = 2;i <= sqrt(k);++i) {
		if (k%i == 0)
			return false;
	}
	return true;
}
int main() {
	//建立素数表
	for (int i = 2;i <= n;++i) {
		if (isprime(i))
			prime[total++] = i;
	}
	prime[total] = n + 1;
	int m;
	cin >> m;
	while (m)
	{
		int ans = 0;//组合数
		for (int i = 0;m >= prime[i];++i) {//判断条件从最小的数开始到它本身
			int cnt = 0;//素数和
			for (int j = i;j < total&&cnt < m;++j) {
				cnt += prime[j];
			}
			if (cnt==m)
			{
				++ans;
			}
		}
		cout << ans << endl;
		cin >> m;
	}
	return 0;
}
