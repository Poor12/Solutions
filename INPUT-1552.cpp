#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
/*
POJ1552-INPUT
*/

int main() {
	int i, j, count, n, a[20];//a[20]存放一组数据
	cin >> a[0];
	while (a[0]!=-1)
	{
		n = 1;
		for (;;n++) {
			cin >> a[n];
			if (a[n] == 0) break;
		}
		count = 0;
		for (i = 0;i < n;++i) {
			for (j = i + 1;j < n;++j) {
				if (a[j]*2==a[i]||a[i]*2==a[j])
				{
					count++;
				}
			}
		}
		cout << count << endl;//多组数据一组输出一个结果是允许的
		cin >> a[0];
	}
	return 0;
}