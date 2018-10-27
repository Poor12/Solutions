//巴什博弈
//游戏情形：n个物品组成一堆，两个人轮流从这堆物品中取物，规定每次至少取一个，最多取m个，最后取尽物体一方赢
//对抗策略：显然，如果n=m+1,由于最多只能取m个，所以无论先取者拿了几个，后取者全能取走，后者胜利。因此如果n=（m+1）*r+s（r为任意自然数，s<=m），如果先取者要拿走s个物品，后取者拿走k个物品，先取者再拿走m+1-k个物品，结果剩下（m+1）*（r-1）个，保持取法总能获胜
//给对手留下（m+1）的倍数
//给一个k，求最小的l，使k%（1+l）=0
#include <algorithm>
int a[10010];
int main() {
	int k, l;
	while (scanf("%d",&k)!=EOF)
	{
		/*
		int len = 0;
		for(int i=1;i*i<=k;++i)//构造因子表
			if (k%i == 0) {
				a[len++] = i;
				a[len++] = k / i;
			}
		sort(a, a + len);
		int flag = 0;
		for(int i=0;i<len;++i)
			if (a[i] > 2) {
				flag = 1;
				printf("%d\n", a[i] - 1);
				break;
			}
		if (!flag) printf("0\n");
		*/
		int i;
		for (i = 2;i < k;++i) {
			if (k % (i+1) == 0)
				break;
		}
		if (i == k)
			printf("0\n");
		else {
			printf("%d\n", i);
		}
	}
}