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
bool isPrime(int num)
{
	if (num == 1)
		return 0;
	if (num == 2)
		return 1;
	int r = floor(sqrt(num) + 0.5);
	for (int i = 2;i <= r;++i)
	{
		if (num%i == 0)
			return 0;
	}
	return 1;
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	int msize, n, m;
	scanf("%d%d%d", &msize, &n, &m);
	while (!isPrime(msize))
		msize++;
	vector<int> v(msize, 0);
	for (int i = 0;i < n;++i)
	{
		int num;
		scanf("%d", &num);
		int index = num % msize;
		int r = 1;
		bool find = 0;
		if (v[index] == 0)
			v[index] = num;
		else
		{
			for (int j = 1;j < msize;++j)
			{
				int idx = (index + j * j) % msize;
				if (v[idx] == 0)
				{
					find = 1;
					v[idx] = num;
					break;
				}
			}
			if (!find)
				printf("%d cannot be inserted.\n", num);
		}
		
	}
	int tot = 0;
	for (int i = 0;i < m;++i)
	{
		int num;
		scanf("%d", &num);
		int index = num % msize;
		bool find = 0;
		for (int j = 0;j < msize;++j)
		{
			tot++;
			int idx = (index + j * j) % msize;
			if (v[idx] == num || v[idx] == 0)
			{
				find = 1;
				break;
			}
		}
		if (!find)
			tot++;
	}
	float time = tot * 1.0 / m;
	printf("%.1f\n", time);
	return 0;
}