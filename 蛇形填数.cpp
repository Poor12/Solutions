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
#include <queue>
using namespace std;
#define maxn 20
int a[maxn][maxn];
//蛇形输出
int main()
{
	int n, x, y, tot = 0;
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	tot = a[x = 0][y = n - 1] = 1;
	while (tot < n*n)
	{
		while (x + 1 < n && !a[x + 1][y]) a[++x][y] = ++tot;
		while (y - 1 >= 0 && !a[x][y - 1]) a[x][--y] = ++tot;
		while (x - 1 >= 0 && !a[x - 1][y]) a[--x][y] = ++tot;
		while (y + 1 < n && !a[x][y + 1]) a[x][++y] = ++tot;
	}
	for (x = 0;x < n;++x)
	{
		for (y = 0;y < n;++y)
			printf("%3d",a[x][y]);
		printf("\n");
	}
	return 0;
}
