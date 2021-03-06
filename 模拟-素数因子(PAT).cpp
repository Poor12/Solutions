#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2;i <= sqrt(n);++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int n, t, x = 0;
	int a[30], b[30];
	cin >> n;
	t = n;
	if (n == 1)
		cout << "1=1";
	else
	{
		int sqr = sqrt(n);
		for (int i = 2;i <= sqr && n > 1;++i)
		{
			if(isPrime(i))
				if (n%i == 0)
				{
					a[x] = i;
					b[x] = 0;
					while (n%i == 0)
					{
						b[x]++;
						n /= i;
					}
					x++;
				}

		}
	}
	if (n != 1)
	{
		a[x] = n;
		b[x++] = 1;
	}
	cout << t << "=";
	for (int i = 0;i < x;++i)
	{
		cout << a[i];
		if (b[i] != 1)
		{
			cout << "^" << b[i];
			if (i < x - 1)
				cout << "*";
		}
	}
	return 0;	
}
