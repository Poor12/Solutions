#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
#include <string>
#include <iomanip>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<int> result;
vector<int> Max;
int main() {
	freopen("D:\\data.txt", "r", stdin);
	cin >> n;
	int x = ceil(sqrt(n));
	for (int i = 2;i < x;++i)
	{
		result.clear();
		int k = n;
		int j = i;
		while (k%j == 0)
		{
			result.push_back(j);
			k = k / j;
			j++;
		}
		if (result.size() > Max.size())
			Max = result;
	}
	if (Max.size() == 0)
	{
		cout << 1 << endl;
		cout << n;
	}
	else
	{
		cout << Max.size() << endl;
		for (int i = 0;i < Max.size();++i)
			cout << (i == 0 ? "" : "*") << Max[i];
	}
}