//最长公共子序列问题
//给定一个序列，将序列中的一些元素以在原来序列中的顺序出现，但不一定要相邻，称为子序列
//给定两个序列，找出两个序列的最长公共子序列
//给定一个序列X=<X1,X2...Xm>，对i=0,1...m，定义X的第i个前缀X'(i)=<X1...Xi>，设X=<a,b,c,b,d,a,b>,X'(4)=<a,b,c,b>
//设阶段和状态为x的前缀指针i和y的前缀指针j，这样就可以保证x(i-1)和y(j-1)的LCS已经求出。
//设X=<x1..xm>和Y=<y1...yn>为两个输入序列，并设X和Y的LCS为Z=<z1...zk>
//三性质：
//（1）如果Xm=Yn，则Zk=Xm=Yn且Z'(k-1）是X'(m-1)和Y'(n-1)的一个LCS
//（2）如果Xm!=Yn,则zk!=xm蕴含z是x'(m-1)和y的一个LCS
//（3）如果xm!=yn，则zk!=yn蕴含z是x和y'(n-1)的一个LCS
//设c[i,j]为序列X的前缀X'(i)和序列Y的前缀Y'(j)的LCS长度
//c[i,j]=0 i=0或j=0;c[i,j]=c[i-1,j-1]+1,xi=yj;c[i,j]=max{c[i,j-1],c[i-1,j]} xi!=yj

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
#include <limits>
#include <queue>
#include <cstdio>
#include <limits.h>
using namespace std;
#define n 1024
struct text {
	int num;//单词数
	string word[1024];//单词序列
}t1,t2;
string s1, s2;
int f[n][n];//s1中前i个单词与s2中前j个单词中匹配最多单词数为f[i,j]
void devide(string s, text &t)//从s中截除长度为t.num的单词序列t.word[]
{
	int l = s.size();
	t.num = 1;
	for (int i = 0;i < 1000;++i)
	{
		t.word[i].clear();
	}
	for (int i = 0;i < l;++i)
	{
		if ('A' <= s[i] && s[i] <= 'Z' || 'a' <= s[i] && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9')
			t.word[t.num] += s[i];
		else
			++t.num;
	}
	int now = 0;
	for (int i = 1;i <= t.num;++i)
		if (!t.word[i].empty())
			t.word[++now] = t.word[i];
	t.num = now;
}
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	int test = 0;
	while (!cin.eof())
	{
		++test;
		getline(cin, s1);
		devide(s1, t1);
		getline(cin, s2);
		devide(s2, t2);
		printf("%2d. ", test);
		if (s1.empty() || s2.empty())
		{
			printf("Blank!\n");
			continue;
		}
		memset(f, 0, sizeof(f));
		for (int i = 1;i <= t1.num;++i)
		{
			for (int j = 1;j <= t2.num;++j)
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				if (t1.word[i] == t2.word[j])
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			}
		}
		printf("length of longest match:%d \n", f[t1.num][t2.num]);
	}
	return 0;
}