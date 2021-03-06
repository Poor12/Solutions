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
typedef struct node
{
	char lx;
	string kc;
	string rq;
	string bh;
	string zong;
	int num;
}node;
typedef struct temp
{
	int bh;
	int num;
}temp;
node no[10004];
temp t[10004];
bool cmp(node n1, node n2)
{
	if (n1.num == n2.num)
		return n1.zong < n2.zong;
	return n1.num > n2.num;
}
bool cmp1(temp n1, temp n2)
{
	if (n1.num == n2.num)
		return n1.bh < n2.bh;
	return n1.num > n2.num;
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;++i)
	{
		char s[20];
		scanf("%s%d", s, &no[i].num);
		int len = strlen(s);
		no[i].lx = s[0];
		no[i].zong = s;
		no[i].kc = "";
		no[i].rq = "";
		no[i].bh = "";
		for (int j = 1;j <= 3;++j)
			no[i].kc += s[j];
		for (int j = 4;j <= 9;++j)
			no[i].rq += s[j];
		for (int j = 10;j < len;++j)
			no[i].bh += s[j];
	}
	sort(no, no + n, cmp);
	for (int i = 0;i < m;++i)
	{
		int c;
		scanf("%d", &c);
		if (c == 1)
		{
			char s;
			getchar();
			scanf("%c", &s);
			int flag = 0;
			printf("Case %d: %d %c\n", i + 1, c, s);
			for (int j = 0;j < n;++j)
			{
				if (no[j].lx == s)
				{
					flag = 1;
					printf("%s %d\n", no[j].zong.c_str(), no[j].num);
				}
			}
			if (flag == 0)
				printf("NA\n");
		}
		else if (c == 2)
		{
			char s1[20];
			scanf("%s", s1);
			string s = s1;
			printf("Case %d: %d %s\n", i + 1, c, s.c_str());
			int cnt = 0;
			int sum = 0;
			for (int j = 0;j < n;++j)
			{
				if (no[j].kc == s)
				{
					cnt++;
					sum += no[j].num;
				}
			}
			if (cnt == 0)
				printf("NA\n");
			else
				printf("%d %d\n", cnt, sum);
		}
		else if (c == 3)
		{
			char s1[20];
			scanf("%s", s1);
			string s = s1;
			printf("Case %d: %d %s\n", i + 1, c, s.c_str());
			int cnt = 0;
			int a[2000] = { 0 };
			for (int j = 0;j < n;++j)
			{
				if (no[j].rq == s)
				{
					int sum = 0;
					for (int k = 0;k < 3;++k)
						sum = sum * 10 + no[j].kc[k] - '0';
					a[sum]++;
				}
			}
			for (int j = 101;j <= 999;++j)
			{
				if (a[j] != 0)
				{
					t[cnt].bh = j;
					t[cnt++].num = a[j];
				}
			}
			sort(t, t + cnt, cmp1);
			for (int j = 0;j < cnt;++j)
				printf("%d %d\n", t[j].bh, t[j].num);
			if (cnt == 0)
				printf("NA\n");
		}
		else
		{
			printf("NA\n");
		}
		
	}

	return 0;
}



