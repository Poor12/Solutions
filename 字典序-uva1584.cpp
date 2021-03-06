#include <iostream>
using namespace std;
#define maxn 105

//长度为n的环状串有n种表示法，分别从某个位置开始顺时针得到，字典序最小的称为最小表示
int lesss(const char *s, int p, int q)
{
	int n = strlen(s);
	for (int i = 0;i < n;++i)
		if (s[(p + i) % n] != s[(q + i) % n])
			return s[(p + i) % n] < s[(q + i) % n];
	return 0;
}
int main()
{
	int T;
	char s[maxn];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int ans = 0;
		int n = strlen(s);
		for (int i = 1;i < n;++i)
			if (lesss(s, i, ans))
				ans = i;
		for (int i = 0;i < n;++i)
			putchar(s[(ans + i) % n]);
		putchar('\n');
	}
	return 0;
}