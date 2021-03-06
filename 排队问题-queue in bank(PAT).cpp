#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int at;//来的时间
	int dt;//处理的时间
	int ft;//结束的时间
	int pt;
	friend bool operator<(const node &a, const node &b)
	{
		return a.ft > b.ft;
	}
};
bool compare(node &a, node &b)
{
	return a.at < b.at;
}

priority_queue<node> q;
int main()
{
	//freopen("D:\\data.txt", "r", stdin);
	int n, wn;
	int h, m, s,p;
	cin >> n >> wn;
	vector<node> v(n);
	for (int i = 0;i < n;++i)
	{
		scanf("%d:%d:%d %d", &h,&m,&s,&p);
		v[i].at = h * 60 * 60 + m * 60 + s;
		v[i].pt = p * 60;
	}
	sort(v.begin(), v.end(), compare);
	int i,j,sum=0,count=0;
	for (i = 0;i < n;++i)
	{
		if (v[i].at > 17*60*60)
			break;
		if (q.size() < wn)
		{
			if (v[i].at < 8*60*60)
			{
				v[i].dt = 8 * 60 * 60;
			}
			else
			{
				v[i].dt = v[i].at;
			}
		}
		else
		{
			node a = q.top();
			q.pop();
			if (v[i].at > a.ft)
				v[i].dt = v[i].at;
			else
				v[i].dt = a.ft;
		}
		v[i].ft = v[i].dt + v[i].pt;
		q.push(v[i]);
	}
	for (j = 0;j < i;++j)
	{
		//if(v[j].at)
		sum += v[j].dt - v[j].at;
		count++;
	}
	//cout << sum;
	//cout << count;
	double re = sum / 60.0 / count;
	printf("%.1lf", re);
}