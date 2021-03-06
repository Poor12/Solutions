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
using namespace std;

int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int n, p;
	cin >> n >> p;
	vector<int> shuru(n);
	for (int i = 0;i < n;++i)
		cin >> shuru[i];
	sort(shuru.begin(), shuru.end());
	int maxnum = 0;
	int l, r;
	for (int i = 0;i < n;++i)
	{
		l = i;
		r = n - 1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (shuru[m] <= shuru[i] * p)
			{
				maxnum = max(maxnum, m - i + 1);
				l = m + 1;
			}
			else
				r = m - 1;
		}
	}
	cout << maxnum << endl;
	return 0;
}