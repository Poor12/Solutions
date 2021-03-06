#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define FOR(i, x, y) for(int i = x; i <= y; i++)
#define rFOR(i, x, y) for(int i = x; i >= y; i--)
#define MAXN 100010
#define oo 0x3f3f3f3f
using namespace std;
typedef long long LL;
int a[MAXN];
bool cmp(LL a,LL b)
{
    return a>b;
}
int main()
{
     #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif // LOCAL
 
    int n;
    scanf("%d",&n);
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    int ans=n;
    int cnt=0;
    int i=1;
    while(cnt!=ans&&i<=n)
    {
        while(a[i]<=ans&&cnt!=ans){
            ans--;
        
        }
        while(cnt!=ans&&a[i]>ans&&i<=n){
            i++;cnt++;
        }
    }
  
    printf("%d",ans);
    
    return 0;
}
