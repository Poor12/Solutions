//子集和问题
//S={x1,x2,....xn}，是一个正整数集合，c是一个正整数，子集和问题就是判定是否存在S的一个子集S1，使得S1中的元素的和为c
//子集和问题最突出的实例就是硬币计数问题：给出一个n个正整数组成的集合a1...an,k1a1+...knan=T有多少解
//设c(i,j)是a1,a2,...ai中包含ai且数为j的方案数，显然目标是求c(n,T)，为了计算c(i,j)，我们将前i个正整数设为阶段，将k1a1+k2a2+...kiai的可能数和j设为状态
//显然状态转移方程为
//c(i,j)=0 i=0;c(i,j)=Σc(k,j-ai)
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
//最小币值为5分，因此11种货币以5分为计算单位
long long a[6001];//用11种货币构成n个5分的方式数为a[n]
int b[] = { 1,2,4,10,20,40,100,200,400,1000,2000 };
int main() {
	//freopen("D:\\data.txt", "r", stdin);
	for (int i = 0;i < 6000;++i)
		a[i] = 1;
	for (int i = 1;i < 11;++i)
	{
		for (int j = b[i];j <= 6000;++j)
			a[j] += a[j - b[i]];
	}
	while (true)
	{
		double d;
		scanf("%lf", &d);
		if (d == 0.0) break;
		int n = int(d*20.0);
		printf("%6.2lf%17I64d\n", d, a[n]);
	}
	return 0;
}
