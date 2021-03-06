#include <algorithm>
#include <queue>
int main()
{
	int t,x;
	while (scanf("%d",&t)&&t)
	{
		priority_queue<int,vector<int>,greater<int>> pq;
		for (int i = 0;i < t;++i)
		{
			scanf("%d", &x);
			pq.push(x);
		}
		int cost = 0;
		while (pq.size()!=1)
		{
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			cost += a + b;
			pq.push(a + b);
		}
		printf("%d\n",cost);
	}
}