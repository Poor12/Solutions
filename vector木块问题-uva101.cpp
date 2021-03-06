#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <string>
using namespace std;
const int maxn = 30;
int  n;
vector<int> pile[maxn];
void find_block(int a, int &p, int &h)//找到木块a所在的pile和weight
{
	for (p = 0;p < n;++p)
	{
		for(h=0;h<pile[p].size();++h)
			if (pile[p][h] == a)
				return;
	}
}
void clear_above(int p, int h)//把第p堆高度为h的木块上方的所有木块移回原位
{
	for (int i = h + 1;i < pile[p].size();++i)
	{
		int b = pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(h + 1);
}
void pile_onto(int p, int h, int p2)//第p堆高度为h及其上方的木块整体移动到p2堆的顶部
{
	for (int i = h;i < pile[p].size();++i)
		pile[p2].push_back(pile[p][i]);
	pile[p].resize(h);
}
void print()
{
	for (int i = 0;i < n;++i)
	{
		printf("%d:", i);
		for (int j = 0;j < pile[i].size();++j)
			printf(" %d", pile[i][j]);
		printf("\n");
	}
}
int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int a, b;
	cin >> n;
	string s1, s2;
	for (int i = 0;i < n;++i)
		pile[i].push_back(i);
	while (cin >> s1 >> a >> s2 >> b)
	{
		int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		if (pa == pb)
			continue;
		if (s2 == "onto")
			clear_above(pb, hb);
		if (s1 == "move")
			clear_above(pa, ha);
		pile_onto(pa, ha, pb);
	}
	print();
	return 0;
}