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

int n;
int num1[35];
int num2[35];
int ans[35];
int len;
int check(int l1, int r1, int l2, int r2)
{
	if (l1 > r1)
		return 0;
	if (l1 == r1)
	{
		ans[++len] = num1[l1];
		return 1;
	}
	int i;
	for (i = l2;i <= r2;++i)
	{
		if (num2[i] == num1[l1 + 1])
			break;
	}
	int ok = 1;
	ok &= check(l1 + 1, l1 + 1 + i - l2, l2, i);
	ans[++len] = num1[l1];
	ok &= check(l1 + i - l2 + 2, r1, i + 1, r2 - 1);
	return ok;
}
//看除了叶子以外的每个节点是否都有两个儿子，如果只有一个的话不确定
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1;i <= n;++i)
		scanf("%d", &num1[i]);
	for (int i = 1;i <= n;++i)
		scanf("%d", &num2[i]);
	puts(check(1, n, 1, n) ? "Yes" : "No");
	for (int i = 1;i <= len;++i)
		printf("%d%c", ans[i], i == len ? '\n' : ' ');
	return 0;
}