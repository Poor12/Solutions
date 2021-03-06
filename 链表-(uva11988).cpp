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
const int maxn = 100000 + 5;
int last, cur, nextt[maxn];//光标位于cur号字符的后面
//next[i]表示在当前显示屏中s[i]右边的字符编号
char s[maxn];
int main() {
	freopen("D:\\data.txt", "r", stdin);
	while (scanf("%s", s + 1) == 1)
	{
		int n = strlen(s + 1);//输入保存在s[1],s[2]
		last = cur = 0;
		nextt[0] = 0;
		for (int i = 1;i <= n;++i)
		{
			char ch = s[i];
			if (ch == '[')
				cur = 0;
			else if (ch == ']')
				cur = last;
			else
			{
				nextt[i] = nextt[cur];
				nextt[cur] = i;
				if (cur == last)
					last = i;
				cur = i;//移动光标
			}
		}
		for (int i = nextt[0];i != 0;i = nextt[i])
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}