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
#define n 100005
int mp[n];
int ans[n], cnt[n], an[n];

int main() {
	//freopen("D:\\data.txt", "r", stdin);
	int a, b;
	int nn, m, i, p;
	memset(ans, -1, sizeof(ans));
	memset(mp, -1, sizeof(mp));
	scanf("%d", &nn);
	for (i = 0;i < nn;++i)
	{
		cin >> a >> b;
		mp[a] = b;
		mp[b] = a;
	}
	scanf("%d", &m);
	for (i = 0;i < m;++i)
	{
		scanf("%d", &p);
		ans[p] = 0;
		cnt[i] = p;
	}
	int k = 0;
	for (i = 0;i < m;++i)
	{
		if (mp[cnt[i]] >= 0 && ans[mp[cnt[i]]] == 0)
			continue;
		else
			an[k++] = cnt[i];
	}
	sort(an, an + k);
	printf("%d\n", k);
	if (k > 0)
		printf("%05d", an[0]);
	for (i = 1;i < k;++i)
		printf(" %05d", an[i]);
	if (k > 0)
		printf("\n");
	return 0;
}