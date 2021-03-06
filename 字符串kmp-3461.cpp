//字符串存储
/*
	suffix[q]函数表示p[0q-1]的后缀与p的前缀间的最长匹配字串的长度
	suffix[0]=-1;
	suffix[1]=0;
	int k=0;
	for(int i=2;i<=m;++i){
		while(k>=0&&p[k]!=p[i-1])
			k=suffix[k];
		suffix[i]=++k;
	}
	i=0;
	j=0;
	while(i<=n-1&&j<=m-1)
		if(j==-1||T[i]==P[j])
		{	
			i++;
			j++;
		}
		else j=suffix[j];
	if(j>m-1)
		return (i-(m-1));
	else 
		return -1;
*/
#include <cstring>
const int maxw = 10000 + 10;
const int maxt = 10000 + 10;
int match(char w[], char s[], int next[]) {
	int cnt = 0;
	int slen = strlen(s);
	int wlen = strlen(w);
	int p = 0, cur = 0;
	while (cur<slen)
	{
		if (s[cur] == w[p]) {
			cur++;
			p++;
		}
		else if(p>=0)
		{
			p = next[p];
		}
		else
		{
			++cur;
			p = 0;
		}
		if (p == wlen) {
			cout << cur-wlen;
			p = next[p];
			++cnt;
		}
	}
	return cnt;
}
int main() {
	int loop;
	scanf("%d", &loop);
	while (loop--)
	{
		char w[maxw], t[maxt];
		scanf("%s%s", w, t);
		int suffix[maxw];
		suffix[0] = -1;
		suffix[1] = 0;
		int p = 0;
		for (int cur = 2;cur <= strlen(w);++cur) {
			while (p >= 0 && w[p] != w[cur - 1])
				p = suffix[p];
			suffix[cur] = ++p;
		}
		printf("%d\n", match(w, t, suffix));
	}
	return 0;
}
