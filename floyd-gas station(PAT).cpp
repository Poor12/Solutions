#include<iostream>
#include<cstdio>
#include<algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	freopen("D:\\data.txt", "r", stdin);
	int n, m, k, ds;
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	vector<vector<int>> dist(n + m + 1, vector<int>(n + m + 1, INT16_MAX));
	for (int i = 1;i <= n + m;++i)
	{
		dist[i][i] = 0;
	}
	int src, des, tempdist;
	char str[5];
	for (int i = 0;i < k;++i)
	{
		scanf("%s", str);
		if (str[0] == 'G')
		{
			sscanf(str + 1, "%d", &src);
			src += n;
		}
		else
		{
			sscanf(str, "%d", &src);
		}
		scanf("%s", str);
		if (str[0] == 'G')
		{
			sscanf(str + 1, "%d", &des);
			des += n;
		}
		else
		{
			sscanf(str, "%d", &des);
		}
		scanf("%d", &tempdist);
		dist[src][des] = min(tempdist, dist[src][des]);
		dist[des][src] = dist[src][des];
	}
	int i, j;
	for(int k=1;k<=n+m;++k)
		for(int i=1;i<=n+m;++i)
			for (int j = 1;j <= n + m;++j)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
	bool isfind = false, isok;
	int mindist = 0, tempmindist, index;
	int sumdist = INT16_MAX, tempsumdist;
	for (int i = n + 1;i <= n + m;++i)
	{
		tempsumdist = 0;
		isok = 1;
		tempmindist = INT16_MAX;
		for (int j = 1;j <= n;++j)
		{
			if (dist[i][j] > ds)
			{
				isok = false;
				break;
			}
			else
			{
				tempsumdist += dist[i][j];
				if (dist[i][j] < tempmindist)
					tempmindist = dist[i][j];
			}
		}
		if (isok)
		{
			if (tempmindist > mindist)
			{
				isfind = 1;
				index = i;
				mindist = tempmindist;
				sumdist = tempsumdist;
			}
			else if (tempmindist == mindist && tempsumdist < sumdist)
			{
				isfind = 1;
				index = i;
				sumdist = tempsumdist;
			}
		}
	}
	if (isfind)
	{
		double avg = sumdist * 1.0 / n;
		printf("G%d\n%d.0 %.1f\n", index - n, mindist, avg);
	}
	else
	{
		printf("no solution\n");
	}
	return 0;
}