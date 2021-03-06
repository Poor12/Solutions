#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
using namespace std;
struct Matrix
{
	int a, b;
	Matrix(int a = 0, int b = 0) :a(a), b(b) {}
}m[26];
stack<Matrix> s;
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0;i < n;++i)
	{
		string name;
		cin >> name;
		int k = name[0] - 'A';
		cin >> m[k].a >> m[k].b;
	}
	string expr;
	while (cin >> expr)
	{
		int len = expr.length();
		bool error = false;
		int ans = 0;
		for (int i = 0;i < len;++i)//遇到字母时入栈，遇到右括号时出栈
		{
			if (isalpha(expr[i]))
				s.push(m[expr[i] - 'A']);
			else if (expr[i] == ')')
			{
				Matrix m2 = s.top();s.pop();
				Matrix m1 = s.top();s.pop();
				if (m1.b != m2.b)
				{
					error = 1;
					break;
				}
				ans += m1.a*m1.b*m2.b;
				s.push(Matrix(m1.a, m2.b));
			}
		}
		if (error)
			printf("error\n");
		else
			printf("%d\n", ans);

	}
	return 0;
}
