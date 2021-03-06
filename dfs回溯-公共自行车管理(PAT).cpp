#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void dfs(int start, int index, int end);
int cmax, n, sp, m;
int costTimes, outBikes, inBikes;
int resultTimes = INT_MAX;
int resultOutBikes, resultInBikes;
vector<int> bikes, path, resultpath;
vector<bool> visited;
vector<vector<int>> times;
int main()
{
	cin >> cmax >> n >> sp >> m;
	bikes.resize(n + 1, 0);
	visited.resize(n + 1, 0);
	times.resize(n + 1, vector<int>(n + 1, 0));
	for (int i = 1;i <= n;++i)
		cin >> bikes[i];
	int m, n, dist;
	for (int i = 0;i < m;++i)
	{
		cin >> m >> n >> dist;
		times[m][n] = dist;
		times[n][m] = dist;
	}
	dfs(0, 0, sp);
	cout << resultOutBikes << " 0";
	for (int i = 1;i < resultpath.size();++i)
	{
		cout << "->" << resultpath[i];
	}
	cout << " " << resultInBikes;
	return 0;
}

void dfs(int start, int index, int end)
{
	visited[index] = 1;
	path.push_back(index);
	costTimes += times[start][index];

	if (index == end)
	{
		inBikes = 0, outBikes = 0;
		for (int i = 1;i < path.size();++i)
		{
			if (bikes[path[i]] > cmax / 2)
			{
				inBikes += bikes[path[i]] - cmax / 2;
			}
			else
			{
				if ((cmax / 2 - bikes[path[i]]) < inBikes)
				{
					inBikes -= (cmax / 2 - bikes[path[i]]);
				}
				else
				{
					outBikes += (cmax / 2 - bikes[path[i]]) - inBikes;
					inBikes = 0;
				}
			}
		}
		if (costTimes != resultTimes)
		{
			if (costTimes < resultTimes)
			{
				resultTimes = costTimes;
				resultpath = path;
				resultOutBikes = outBikes;
				resultInBikes = inBikes;
			}
		}
		else if (outBikes != resultOutBikes)
		{
			if (outBikes < resultOutBikes)
			{
				resultpath = path;
				resultOutBikes = outBikes;
				resultInBikes = inBikes;
			}
		}
		else if (inBikes < resultInBikes)
		{
			resultpath = path;
			resultOutBikes = outBikes;
			resultInBikes = inBikes;
		}
	}
	else
	{
		for (int i = 1;i <= n;++i)
		{
			if (times[index][i] != 0 && !visited[i])
				dfs(index, i, end);
		}
	}

	visited[index] = false;
	path.pop_back();
	costTimes -= times[start][index];
}