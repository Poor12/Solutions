#define INF 0x3fffffff
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>

int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int k, i, j;
	int outcome[54];
	int order[54];
	int shuffle1[54], shuffle2[54];
	for (int i = 0;i < 54;++i)
		shuffle2[i] = i;
	scanf("%d", &k);
	for (i = 0;i < 54;++i)
		scanf("%d", order + i);
	for (i = 1;i <= k;++i)
	{
		if (i % 2)
		{
			for (j = 0;j < 54;++j)
			{
				shuffle1[order[j] - 1] = shuffle2[j];
			}
		}
		else
		{
			for (j = 0;j < 54;++j)
				shuffle2[order[j] - 1] = shuffle1[j];
		}
	}


	if (k % 2) for (j = 0;j < 54;j++) outcome[j] = shuffle1[j];
	else for (j = 0;j < 54;j++) outcome[j] = shuffle2[j];//判断1和2哪个才是最终结果
	for (j = 0;j < 54;j++) {
		switch (outcome[j] / 13) {
		case 0:
			printf("S");
			break;
		case 1:
			printf("H");
			break;
		case 2:
			printf("C");
			break;
		case 3:
			printf("D");
			break;
		case 4:
			printf("J");
			break;
		}//输出卡牌的花色
		printf("%d", (outcome[j] % 13) + 1);//输出牌面数字
		if (j < 53) putchar(' ');//输出空格
	}
	return 0;
}