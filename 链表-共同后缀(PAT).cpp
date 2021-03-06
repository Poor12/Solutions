#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
struct node
{
	char c;
	int next;
	bool operator ==(const node &n1) const
	{
		return c == n1.c&&next == n1.next;
	}
	bool operator !=(const node &n1) const
	{
		return c != n1.c||next == n1.next;
	}
};
node hashh[100000];
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int s1, s2, num;
	cin >> s1 >> s2 >> num;
	for (int i = 0;i < num;++i)
	{
		int tmp;
		cin >> tmp;
		cin >> hashh[tmp].c >> hashh[tmp].next;
	}
	int tmp = s1;
	stack<node> st1, st2;
	while (tmp!=-1)
	{
		st1.push(hashh[tmp]);
		tmp = hashh[tmp].next;
	}
	tmp = s2;
	while (tmp != -1)
	{
		st2.push(hashh[tmp]);
		tmp = hashh[tmp].next;
	}
	bool first = 1;
	node n1, n2;
	while (!st1.empty()&&!st2.empty())
	{
		n1 = st1.top();
		st1.pop();
		n2 = st2.top();
		st2.pop();
		//cout << n1.next << " " << n2.next << endl;
		if (n1.c != n2.c)
		{
			if (first)
			{
				cout << "-1";
				return 0;
			}
			else
			{
				cout << n1.next;
				return 0;
			}
		}
		else
		{
			first = 0;
		}
	}
	cout << s1;
	return 0;
}