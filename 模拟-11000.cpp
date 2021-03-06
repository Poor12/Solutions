#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	UVA 11000 构造模拟，构造数学模型
*/

int main()
{
	int n;
	cin >> n;
	while (n>-1)
	{
		long long a = 0;//雄峰
		long long num = 1;//总数
		vector<long long> k;
		k.push_back(1);
		k.push_back(2);
		for (int i = 0;i < n;++i) {
			if (i > 1)
				k.push_back(k[i - 1] + k[i - 2]);
			a = num;
			num = num + k[i];
		}
		cout << a << " " << num << endl;
		cin >> n;
	}
	return 0;
}
