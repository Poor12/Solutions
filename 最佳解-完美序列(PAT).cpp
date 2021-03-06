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
	cin >> n>> p;
	vector<int> shuru(n);
	for (int i = 0;i < n;++i)
		cin >> shuru[i];
	sort(shuru.begin(), shuru.end());
	int maxnum = 0;
	for (int i = 0;i < n;++i)
	{
		while (i + maxnum < n&&shuru[i + maxnum] <= shuru[i] * p)
			maxnum++;
	}
	cout << maxnum << endl;
	return 0;
}