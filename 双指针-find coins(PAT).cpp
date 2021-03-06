#include<iostream>
#include<cstdio>
#include<algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, a[maxn];
int main() {
	freopen("D:\\data.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n;++i)
		scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	for (int i = 1, j = n;i < j;)
	{
		if (a[i] + a[j] == m)
		{
			printf("%d %d\n", a[i], a[j]);
			return 0;
		}
		else if (a[i] + a[j] > m)
			--j;
		else
			++i;
	}

	printf("no solution\n");
	return 0;
	
}

/*

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
const int maxm = 1000 + 10;
int w[maxn], cnt[maxn] = {0};

int main(){
	int n, m;
	bool flag = false;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &w[i]);
		cnt[w[i]] += 1;
	}
	sort(w+1, w+n+1);
	for(int i=1; i<=n; i++){
		int first = w[i];
		int second = m - first;
		cnt[first] --;
		if(cnt[second] && first <= second){
			flag = true;
			printf("%d %d\n", first, second);
			break;
		}
		else
			cnt[first] ++;
	}
	if(!flag) printf("No Solution\n");
	return 0;
}

*/