#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<map>
using namespace std;
#define INF 99999999
#define M 100005
int num[M];
int main()
{
	int n,i,sum1,sum2;
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	sum1=0;
	for(i=0;i<n/2;i++)
	{
		sum1+=num[i];
	}
	sum2=0;
	for(i=n/2;i<n;i++)
	{
		sum2 += num[i];
	}
	printf("%d %d\n",n%2,sum2-sum1);
 
}
