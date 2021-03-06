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
#define maxn 1000
int sum[maxn];
void build(int p)
{
	int v;
	cin >> v;
	if (v == -1)
		return;
	sum[p] += v;
	build(p - 1);
	build(p + 1);
}
bool init()
{
	int v;
	cin >> v;
	if (v == -1)
		return false;
	memset(sum, 0, sizeof(sum));
	int pos = maxn / 2;//树根的水平位置
	sum[pos] = v;
	build(pos - 1);
	build(pos + 1);
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	int kase = 0;
	while (init())
	{
		int p = 0;
		while (sum[p] == 0)
			++p;//找最左边的叶子
		cout << "Case " << ++kase << ":\n" << sum[p++];
		while (sum[p] != 0)
			cout << " " << sum[p++];
		cout << "\n\n";
	}

	return 0;
}