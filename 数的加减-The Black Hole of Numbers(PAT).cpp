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
inline int result(vector<int> a)
{
	int re=0;
	for (int i = 0;i < a.size();++i)
	{
		re = re * 10 + a[i];
	}
	return re;
}
int main()
{
	//freopen("D:\\data.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int num,n1,n2,n3;
	cin >> num;
	vector<int> digs;
	do {
		digs.clear();
		while (num)
		{
			digs.push_back(num % 10);
			num = num / 10;
		}
		sort(digs.begin(), digs.end(), greater<int>());
		n1 = result(digs);
		sort(digs.begin(), digs.end());
		n2 = result(digs);
		n3 = n1 - n2;
		printf("%04d - %04d = %04d\n", n1, n2, n3);
		num = n3;
	} while (num != 6174);
	return 0;
}