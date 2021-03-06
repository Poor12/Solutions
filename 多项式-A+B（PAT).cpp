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
using namespace std;
map<int, float,greater<int>> duoxiang;
typedef pair<int, int> pii;
priority_queue<pii,vector<pii>, greater<pii>> q;
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int k1, k2;
	float ex;
	int co;
	cin >> k1;
	for (int i = 0;i < k1;++i)
	{
		cin >> co >> ex;
		duoxiang[co] = ex;
	}
	cin >> k2;
	for (int i = 0;i < k2;++i)
	{
		cin >> co >> ex;
		if (duoxiang.find(co) == duoxiang.end())
		{
			duoxiang[co] = ex;
		}
		else
		{
			duoxiang[co] += ex;
			if (duoxiang[co] == 0.0)//删除这个key
			{
				duoxiang.erase(co);
			}
		}
	}
	cout << duoxiang.size() << " ";
	for (auto iter=duoxiang.begin();iter!=duoxiang.end();iter++)
	{
		if (iter != duoxiang.begin())
			cout << " ";
		printf("%d %.1f", iter->first, iter->second);
	}
	return 0;
}
