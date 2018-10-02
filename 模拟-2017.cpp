#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	POJ 2017 直叙式模拟
*/

int main()
{
	int n, i, x, y, z, ans;
	while (cin>>n,n>0)
	{
		ans = z = 0;
		for (i = 0;i < n;++i) {
			cin >> x >> y;
			ans += (y - z)*x;
			z = y;
		}
		cout << ans << " miles" << endl;
	}
	return 0;
}
