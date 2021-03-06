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
#include <cmath>
using namespace std;
struct
{
	string value;
	int lc;int rc;
}node[60];
int start;
int mark[50] = { 0 };
void inorder(int x)
{
	if (x == -1)
		return;
	if((node[x].lc!=-1||node[x].rc!=-1)&&x!=start)
		cout << "(";
	inorder(node[x].lc);
	cout << node[x].value;
	inorder(node[x].rc);
	if ((node[x].lc != -1 || node[x].rc!=-1 )&& x != start)
		cout << ")";
}
int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1;i <= n;++i)
	{
		string a;
		int b, c;
		cin >> a >> b >> c;
		if (b != -1)
			mark[b] = 1;//有无父节点
		if (c != -1)
			mark[c] = 1;
		node[i].lc = b;
		node[i].rc = c;
		node[i].value = a;
	}
	start = 1;
	while (mark[start] == 1)
		start++;
	inorder(start);
	return 0;
}