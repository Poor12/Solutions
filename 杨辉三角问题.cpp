#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//杨辉三角问题

int main()
{
	cout << "请输入杨辉三角阶数i:";
	int num;
	cin >> num;
	deque<int> ori;
	int ini_value = 1;
	ori.push_back(ini_value);
	ori.push_back(ini_value);
	deque<int> next;
	for (int i = 0;i < num - 2;i++) {
		next.push_back(ini_value);
		while (!ori.empty())
		{
			int i = ori.front();
			ori.pop_front();
			if (!ori.empty()) {
				int tmp = i + ori.front();
				next.push_back(tmp);
			}
			if (ori.empty())
				next.push_back(i);
		}
		ori = next;
		next.clear();
	}
	cout << "杨辉三角第" << num << "行内容如下：" << endl;
	while (!ori.empty())
	{
		cout << ori.front()<<" ";
		ori.pop_front();
	}
	cout << endl;
	return 0;
}

