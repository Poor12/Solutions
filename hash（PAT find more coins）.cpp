#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int hash[1010] = { 0 };
	int x, y, a, i;
	cin >> x >> y;
	for (i = 0;i < x;++i)
	{
		cin >> a;
		hash[a]++;
	}
	for (i = 1;i < y;++i)
	{
		if (hash[i] && hash[y - i])
		{
			if (i != y - i)
				break;
			else if (i == y - i && hash[i] >= 2)
				break;
		}
	}
	if (i == y)
		cout << "No Solution";
	else
		cout << i << " " << y - i;
	return 0;
}
