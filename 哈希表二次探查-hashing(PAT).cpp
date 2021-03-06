#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

int msize, n,k;
vector<int> v;
bool isprime(int v)//1不是素数
{
	if (v == 1)
		return false;
	for (int i = 2;i <= sqrt(v);++i)
	{
		if (v%i == 0)
			return false;
	}
	return true;
}
int getprime(int v)
{
	while (isprime(v)==0)
	{
		v++;
	}
	return v;
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	cin >> msize >> n;
	msize = getprime(msize);
	//cout << msize << endl;
	v.resize(n);
	vector<bool> result(msize, 0);
	for (int i = 0;i < n;++i)
	{
		cin >> v[i];
		int j;
		for (j = 0;j < msize;++j)
		{
			k = (v[i] + j * j) % msize;
			if (!result[k])
			{
				result[k] = 1;
				cout << k;
				break;
			}
		}
		if (j == msize)
			cout << "-";
		if (i != n - 1)
			cout << " ";
	}

	return 0;
}
