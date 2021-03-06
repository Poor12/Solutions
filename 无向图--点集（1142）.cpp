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
int e[210][210];
int main() {
	int nv, ne, m, ta, tb, k;
	scanf("%d%d", &nv, &ne);
	for (int i = 0;i < ne;++i)
	{
		scanf("%d %d", &ta, &tb);
		e[ta][tb] = e[tb][ta] = 1;
	}
	scanf("%d", &m);
	for (int i = 0;i < m;++i)
	{
		scanf("%d", &k);
		vector<int> v(k);
		int hash[210] = { 0 }, isc = 1, ism = 1;
		for (int j = 0;j < k;++j)
		{
			scanf("%d", &v[j]);
			hash[v[j]] = 1;
		}
		for (int j = 0;j < k;++j)
		{
			if (isc == 0) break;
			for (int l = j + 1;l < k;++l)
			{
				if (e[v[j]][v[l]] == 0)
				{
					isc = 0;
					printf("Not a Clique\n");
					break;
				}
			}
		}
		if (isc == 0) continue;
		for (int j = 1;j <= nv;++j)
		{
			if (hash[j] == 0)
			{
				for (int l = 0;l < k;++l)
				{
					if (e[v[l]][j] == 0) break;
					if (l == k - 1) ism = 0;
				}
			}
			if (ism == 0)
			{
				printf("not maximal\n");
				break;
			}
		}
		if (ism == 1)
			printf("Yes\n");
	}
	return 0;
}
