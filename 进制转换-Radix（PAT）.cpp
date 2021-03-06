#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <iterator>
#include <limits>
#include <queue>
#include <cstdio>
#include <limits.h>
const int maxn = 10001;
int a[maxn], dp[maxn];
long long int transform(string s, long long m) {
	long long sum = 0;
	for (auto it = s.begin();it != s.end();++it) {
		if (*it <= '9'&&*it >= '0')
			sum = sum * m + (*it) - '0';
		else
		{
			sum = sum * m + (*it) - 'a' + 10;
		}
	}
	return sum;
}//m进制数转换为十进制数
long long find_radix(long long int num, string s2) {
	char it = *max_element(s2.begin(), s2.end());
	long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
	long long high = max(num, low);
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long t = transform(s2, mid);
		if (t > num) high = mid - 1;
		else if (t == num) return mid;
		else low = mid + 1;
	}
	return -1;
}
int main() {
	string n1, n2;
	int tag;
	long long m;
	cin >> n1 >> n2 >> tag >> m;
	long long sum, res;
	if (tag == 1) {
		sum = transform(n1, m);
		res = find_radix(sum, n2);
	}
	else
	{
		sum = transform(n2, m);
		res = find_radix(sum, n1);
	}
	if (res == -1)
		cout << "Impossible";
	else cout << res;
	return 0;
}