#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;
const int maxn = 1000 + 10;
int n, target[maxn],out[maxn];

int main()
{
	//freopen("D:\\data.txt", "r", stdin);
	while (scanf("%d", &n) == 1)
	{
		stack<int> s;
		for (int i = 0;i < n;++i)
			scanf("%d", &out[i]);
		for (int i = 0;i < n;++i)
			scanf("%d", &target[i]);
		int ok = 1;
		int current = 0;
		for (int i = 0;i < n;++i)
		{
			s.push(target[i]);
			while (!s.empty() && s.top() == out[current])
			{
				s.pop();
				current++;
			}
		}
		if (s.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}