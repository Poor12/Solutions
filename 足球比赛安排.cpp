//足球比赛安排
//设共有n支队伍参赛，初赛共进行n-1天，每队和其他各队进行一场比赛。要求每队每天只能进行一场比赛，且不能轮空
#include <stdio.h>
#define maxn 64
int aa[maxn + 1][maxn + 1] = { 0 };
void gamecal(int k, int n)//处理编号k开始的n个球队的日程
{
	int i, j;
	if (n == 2)
	{
		aa[k][1] = k;//参赛球队编号
		aa[k][2] = k + 1;//对阵球队编号
		aa[k + 1][1] = k + 1;//参赛球队编号
		aa[k + 1][2] = k;//对阵球队编号
	}
	else
	{
		gamecal(k, n / 2);
		gamecal(k + n / 2, n / 2);
		for (i = k;i < k + n / 2;++i)//填充左上角
		{
			for (j = n / 2 + 1;j <= n;++j)
			{
				aa[i][j] = aa[i + n / 2][j - n / 2];
			}
		}
		for (i = k + n / 2;i < k + n;++i)//填充右下角
		{
			for (j = n / 2 + 1;j <= n;++j)
			{
				aa[i][j] = aa[i - n / 2][j - n / 2];
			}
		}
	}
}
int main()
{
	int m, i, j;
	printf("参赛球队数：");
	scanf("%d", &m);
	j = 2;
	for (i = 2;i < 8;++i)
	{
		j = j * 2;
		if (j == m) break;
	}
	if (i >= 8)
	{
		printf("参赛球队数必须是2的整数次幂，并且不超过64！\n");
		getchar();
		return 0;
	}
	gamecal(1, m);
	printf("\n编号 ");
	for (i = 2;i <= m;++i)
		printf("%2d天 ", i - 1);
	printf("\n");
	for (i = 1;i <= m;++i)
	{
		for (j = 1;j <= m;++j)
			printf("%4d ", aa[i][j]);
		printf("\n");
	}
	getchar();
	return 0;
}