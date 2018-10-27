#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
//括号匹配问题

int main()
{
	cout << "请输入括号序列(以0结束):";
	stack<char> small;
	char a;
	do {
		cin >> a;
		switch (a)
		{
		case '(':
			small.push(a);break;
		case ')':
			if (!small.empty()) {
				small.pop();
				break;
			}
			if (small.empty()) {
				cout << "Wrong" << endl;
				return 0;
			}
		}
	} while (a != '0');
	if (small.empty())
		cout << "ok" << endl;
	else
		cout << "wrong" << endl;
	return 0;
}

