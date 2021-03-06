//动态博弈是指参与人的行动有先后顺序，而且后行动者可以观察到先行动者的选择，并据此作出判断
//困难在于前一刻的最优决策在下一刻可能不再是最优，因此求解上有困难
//因此为了做最优选择，每个参与人都必须思考这样一个问题：假如我如此选择，对方将如何应对？假如我是他我将会如何行动？对于他的应对，什么是我的最优选择？
//动态博弈属于一种思想方法，在博弈开始之前规定每一个决策点上的选择，即使这个决策点实际上不会出现。根据这个战略判定，对方如果按最完美的方法与你对弈，你最终能否赢
//简述题意：有n个数和一个区间[A,B],第一个人先取一个数，必须在区间内，后一次取必须比前一次取的数大，并且差值在区间内，问玩家1能够取到的最大差值
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
/*
	dp[i]表示当前这个人拿了第i个数的最大利益
	dp[i] = A[i] - dp[j]表示拿了A[i]的价值,并且让对手有机会拿到第j个数
	所以 这里的j > i且a<= A[j]-A[i]  <=b
	这里的j取不同值的时候dp[i]是取其中min还是max呢？
	经历无数WA之后想清楚这里应该取min
	为什么？
	dp[i]指的是当前的人已经拿了i了！！
	所以对于j的选择其实是对手的选择
	对手也不傻，他的的选择一定是选对你最不利的选择 
	
	本来是想直接逆序迭代写，但是从终态往起始态走存在一个问题
	该终态是否能走到起始态？
	因为每次拿的数比前一个大[a,b]范围的数,所以逆推会出现到不了起点的情况
	所以还是正着来 记忆化先计算后面的值又不会出现错误路径 
*/ 
int dp[11111];
int A[11111];
int n,a,b;
int tot;
bool ok(int x)
{
	return a<=x&&x<=b;
}
int DP(int i)
{
	if (~dp[i]) return dp[i];
	int ans = inf;
	for (int j = i+1;j < tot;++j)
	{
		if (ok(A[j]-A[i]))
		{
			ans = min(ans,A[i] - DP(j));//想清楚 这里是对手的选择 必须用min 
		}
	}
	if (ans == inf)//此人拿过之后后面的人无法再拿
		ans = A[i];
	return dp[i] = ans;
}
int main()
{
	int T;cin>>T; 
	while (T--)
	{
		scanf("%d %d %d",&n,&a,&b);
		tot = 0;
		for (int i = 0,x;i < n;++i)
		{
			scanf("%d",&x);
			if (x < a) continue;
			A[tot++] = x;
		}
		sort(A,A+tot);
		tot = unique(A,A+tot)-A;
		int ans = -inf; 
		mem(dp,-1); 
		for (int i = 0;i < tot;++i)
		{
			if (A[i]>b) break;
			if (ok(A[i]))
			{
				ans = max(ans,DP(i));
			}
		} 
		if (ans == -inf) ans =  0;
		printf("%d\n",ans);
	}
	return 0;
}
