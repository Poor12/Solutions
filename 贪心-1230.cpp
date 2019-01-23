//在当前列的有墙格中，选择右方最长的d-k堵墙拆除
#include <iostream>
using namespace std;
int map[105][105];
int t,max_x,max_y,sum_s,n,k,x,y,x1,y2;
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(map, 0, sizeof(map));
		max_x = 0;
		max_y = 0;
		sum_s = 0;//最少需要拆除的墙数
		scanf("%d%d", &n, &k);
		for (int i = 1;i <= n;++i)
		{
			scanf("%d%d%d%d", &x, &y, &x1, &y2);
			if (x > max_x) max_x = x;
			if (x1 > max_x) max_x = x1;
			if (y > max_y) max_y = y;
			if (x < x1)
			{
				for (int j = x;j <= x1;++j)
					map[j][y] = i;
			}
			else
				for (int j = x1;j <= x;++j)
					map[j][y] = i;
		}
		for (int i = 0;i <= max_x;++i)
		{
			int tem = 0;
			for (int j = 0;j <= max_y;++j)
				if (map[i][j] > 0)
					tem++;
			int offset = tem - k;
			if (offset > 0)
			{
				sum_s += offset;
				while (offset--)
				{
					int max_s = 0, max_bh;
					for (int k = 0;k <= max_y;++k)
					{
						if (map[i][k] > 0)
						{
							int tem_s = 0;
							for (int z = i + 1;z <= max_x;++z)
								if (map[z][k] == map[z-1][k])
									tem_s++;
								else break;
							if (max_s < tem_s)
							{
								max_s = tem_s;max_bh = k;
							}
						}
					}
					for (int a = i;a <= i + max_s;++a)
						map[a][max_bh] = 0;
				}
			}
		}
		printf("%d\n", sum_s);
	}
}