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

struct node
{
	int cnt;
	int val;
	bool operator<(const node &a) const
	{
		if (cnt == a.cnt)
			return val < a.val;
		else
			return cnt > a.cnt;
	}
};

int n, k;
int a[50005];
int b[50005];
set<node> s;
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int i, j, x;
	node p;
	scanf("%d%d", &n, &k);
	for (i = 0;i < n;++i)
	{
		scanf("%d", &x);
		if (i > 0)
		{
			printf("%d", &x);
			set<node>::iterator it;
			int cnt = 0;
			for (it = s.begin();it != s.end() && cnt < k;it++)
			{
				cnt++;
				printf(" %d", it->val);
			}
			printf("\n");
		}
		p.cnt = b[x];
		b[x]++;
		p.val = x;
		if (s.find(p) != s.end())
			s.erase(p);
		p.cnt++;
		s.insert(p);
	}
	return 0;
}