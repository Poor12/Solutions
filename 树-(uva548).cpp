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
using namespace std;
const int maxnv = 10000 + 10;//直接用权值作为编号
int in_order[maxnv], post_order[maxnv], lch[maxnv], rch[maxnv];
int n;
int best, best_sum;
bool read_list(int* a)
{
	string line;
	if (!getline(cin, line))
		return 0;
	stringstream ss(line);
	n = 0;
	int x;
	while (ss >> x)
		a[n++] = x;
	return n > 0;
}
int build(int l1, int r1, int l2, int r2)
{
	if (l1 > r1)
		return 0;
	int root = post_order[r2];
	int p = l1;
	while (in_order[p] != root)
		p++;
	int cnt = p - l1;//左子树节点个数
	lch[root] = build(l1, p - 1, l2, l2 + cnt - 1);
	rch[root] = build(p + 1, r1, l2 + cnt, r2 - 1);
	return root;
}
void dfs(int u, int sum)
{
	sum += u;
	if (!lch[u] && !rch[u])
	{
		if (sum < best_sum || (sum == best_sum && u < best))
		{
			best = u;
			best_sum = sum;
		}
	}
	if (lch[u])
		dfs(lch[u], sum);
	if (rch[u])
		dfs(rch[u], sum);
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	while (read_list(in_order))
	{
		read_list(post_order);
		build(0, n - 1, 0, n - 1);
		best_sum = 1000000000;
		dfs(post_order[n - 1], 0);
		cout << best << "\n";
	}
	return 0;
}