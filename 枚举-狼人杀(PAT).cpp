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
int mystate[110];
int n;
bool judge(int a, int b)
{
	int cntwol = 0, cntpeo = 0;
	int i, x;
	for (i = 1;i <= n;++i)
	{
		if (cntwol > 1 || cntpeo > 1)
			return 0;
		x = mystate[i];
		if (x > 0)
		{
			if (x == a || x == b)
			{
				if (i == a || i == b)
				{
					++cntwol;
				}
				else
				{
					++cntpeo;
				}
			}
		}
		else
		{
			x = -x;
			if (x != a && x != b)
			{
				if (i == a || i == b)
				{
					++cntwol;
				}
				else
				{
					++cntpeo;
				}
			}
		}
	}
	if (cntwol == 1 && cntpeo == 1)
		return 1;
	else
		return 0;
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	scanf("%d", &n);
	int i, j, x;
	for (i = 1;i <= n;++i)
		scanf("%d", &mystate[i]);
	for (i = 1;i <= n;++i)
	{
		for (j = i + 1;j <= n;++j)
		{
			if (judge(i, j))
			{
				printf("%d %d\n", i, j);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}
