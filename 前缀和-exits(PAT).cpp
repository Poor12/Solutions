

#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,tot,sum[maxn]; 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&sum[i]);tot+=sum[i];
        sum[i]+=sum[i-1];
    }
    scanf("%d",&m);
    for(int i=1,x,y;i<=m;++i){
        scanf("%d %d",&x,&y);
        if(x>y) swap(x,y);
        printf("%d\n",min(sum[y-1]-sum[x-1],tot-(sum[y-1]-sum[x-1])));
    }
    return 0;
} 
