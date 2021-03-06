#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define maxn 1010
int np, ng;
struct mouse
{
	int weight;
	int rank;
}mouse[maxn];

int main()
{
	freopen("D:\\data.txt", "r", stdin);
	int np, ng, squ;
	queue<int> q;
	cin >> np >> ng;
	for (int i = 0;i < np;++i)
	{
		cin >> mouse[i].weight;
	}
	for (int i = 0;i < np;++i)
	{
		cin >> squ;
		q.push(squ);
	}
	int temp = np,group;//temp为本轮有多少只老鼠，group为组数
	while (q.size() != 1)
	{
		if (temp%ng == 0)//计算本轮多少组
			group = temp / ng;
		else
			group = temp / ng + 1;
		for (int i = 0;i < group;++i)//枚举每一组，选出该组优胜的老鼠
		{
			int maxm = q.front();
			cout << maxm << endl;
			for (int j = 0;j < ng;++j)
			{
				if (j >= temp - i * ng)
					break;
				if (mouse[q.front()].weight > mouse[maxm].weight)
					maxm = q.front();
				mouse[q.front()].rank = group + 1;//本轮输掉的老鼠排名即是本轮晋级的老鼠个数+1
				q.pop();//出队
			}
			q.push(maxm);//优胜鼠进入下一轮
		}
		temp = group;//下一轮参加比赛的老鼠就是组数
	}
	mouse[q.front()].rank = 1;
	cout << mouse[0].rank;
	for (int i = 1;i < np;++i)
		cout << " " << mouse[i].rank;
	return 0;	
}