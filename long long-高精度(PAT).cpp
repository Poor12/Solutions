#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int i = 1;i <= t;++i)
	{
		long long a, b, c, ans;//long long的最大值2^63-1
		bool flag = 1;
		cin >> a >> b >> c;
		ans = a + b;
		if (a < 0 && b < 0 && ans >= 0) {
			flag = false;
		}
		else if (a > 0 && b > 0 && ans <= 0)
			flag = 1;
		else
			flag = (ans > c);
		cout << "Case #" << i << ": " << (flag ? "true" : "false") << endl;
	}
	return 0;
}