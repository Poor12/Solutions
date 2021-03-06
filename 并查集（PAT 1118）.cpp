#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 10010;
int father[maxn];

void init()
{
	for (int i = 0;i < maxn;++i)
		father[i] = i;
	return;
}
int findfather(int a)
{
	if (father[a] == a)
		return a;
	else
		return father[a] = findfather(father[a]);
}
void _union(int a, int b)
{
	if (findfather(a) != findfather(b))
		father[findfather(b)] = findfather(a);
	return;
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	init();
	int n;
	cin >> n;
	int m;
	int max = -1;
	vector<int> s;
	int temp;
	for (int i = 0;i < n;++i)
	{
		cin >> m;
		for (int j = 0;j < m;++j)
		{
			cin >> temp;
			if (temp > max)
				max = temp;
			s.push_back(temp);
		}
		for (int j = 0;j < s.size() - 1;++j)
			_union(s[j], s[j + 1]);
		s.clear();
	}
	int num = 0;
	for (int i = 1;i <= max;++i)
	{
		if (father[i] == i)
			num++;
	}
	cout << num << " " << max << endl;
	int query, a, b;
	cin >> query;
	for (int i = 0;i < query;++i)
	{
		cin >> a >> b;
		if (findfather(a) == findfather(b))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

