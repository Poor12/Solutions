#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
int m, n, k,num;
int main()
{
	//freopen("D:\\data.txt", "r", stdin);
	cin >> m >> n >> k;
	while (k--)
	{
		stack<int> s;
		vector<int> v;
		for (int i = 1;i <= n;++i)//先输入给出的出栈序列
		{
			cin >> num;
			v.push_back(num);
		}
		int current = 0;
		bool flag = 1;//标记出栈序列是否合法
		for (int i = 1;i <= n;++i)
		{
			s.push(i);
			if (s.size() > m)//此时栈中元素大于栈容量，说明出栈序列非法
			{
				flag = 0;
				break;
			}
			while (!s.empty() && s.top() == v[current])
			{
				s.pop();
				current++;
			}
		}
		if (s.empty() && flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;

}