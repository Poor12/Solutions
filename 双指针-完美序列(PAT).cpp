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
using namespace std;

int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int n, p;
	cin >> n>> p;
	vector<int> shuru(n);
	for (int i = 0;i < n;++i)
		cin >> shuru[i];
	sort(shuru.begin(), shuru.end());
	int front = 0, back = 0, ans = 1;
		while (front < n && back < n)     //遍历一遍序列即可
		{
			if (shuru[back] <= (long long)shuru[front] * p) //num[back]与p均大于10^9，因而num[back]*p可达10^18，需转换成long long类型
			{
				ans = max(ans, back - front + 1); //更新ans，即当前完美子序列的最大元素个数
				back++;           //满足完美序列条件，前端指针自增
			}
			else
			{
				front++;            //不满足时，后端指针自增
			}
		}
	printf("%ld\n", ans);
	return 0;
}