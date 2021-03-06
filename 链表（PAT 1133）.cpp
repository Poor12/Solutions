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
#define M 100005
#define INF 0x7ffffff
struct node
{
	int addr;
	int next;
	int data;
};
node nn[M];
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, i, m;
	int head, k;
	cin >> head >> n >> k;
	int s, e, data;
	while (n--)
	{
		scanf("%d%d%d", &s, &data, &e);
		nn[s].addr = s;
		nn[s].next = e;
		nn[s].data = data;
	}
	vector<node> v1, v2, v3;
	int p = head;
	while (p != -1)
	{
		if (nn[p].data < 0)
			v1.push_back(nn[p]);
		else if (nn[p].data <= k)
			v2.push_back(nn[p]);
		else
			v3.push_back(nn[p]);
		p = nn[p].next;
	}
	v1.insert(v1.end(), v2.begin(), v2.end());
	v1.insert(v1.end(), v3.begin(), v3.end());
	for (i = 0;i < v1.size();++i)
	{
		if (i != v1.size() - 1)
			printf("%05d %d %05d\n", v1[i].addr, v1[i].data, v1[i + 1].addr);
		else
			printf("%05d %d -1\n", v1[i].addr, v1[i].data);
	}
	return 0;
}
