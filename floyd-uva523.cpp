//floyd路径输出
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<list>
#include<queue>
#define mm(a,b) memset(a,b,sizeof(a))
#define ACCELERATE (ios::sync_with_stdio(false),cin.tie(0))
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define MAXN 0x3fffffff
#define PI acos(-1.0)
#define E exp(1.0)
using namespace std;

//#define debug

int cost[300][300];
int pre[300][300];
int tax[300];

int n;

bool getmap(){
    scanf("%d",&n);
    if(n==0) return 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==-1) cost[i][j]=MAXN;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&tax[i]);
    }
    return 1;
}

void floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pre[i][j]=j;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][k]>0&&cost[k][j]>0){
                        if(cost[i][j]>cost[i][k]+cost[k][j]+tax[k]){
                        cost[i][j]=cost[i][k]+cost[k][j]+tax[k];
                        pre[i][j]=pre[i][k];
                    }
                    else if(cost[i][j]==cost[i][k]+cost[k][j]+tax[k]){
                        pre[i][j]=min(pre[i][k],pre[i][j]);
                    }
                }
            }
        }
    }
}

void solve(){
    int from,to,f;
    while(scanf("%d%d",&from,&to)==2&&from>0){
        printf("From %d to %d :\n",from,to);
        printf("Path: %d",from);
        if(from!=to){
            for(f=pre[from][to];f!=to;f=pre[f][to]){
                printf("-->%d",f);
            }
            printf("-->%d",to);
        }
        printf("\n");
        printf("Total cost : %d\n\n",cost[from][to]);
    }
}

int main()
{
    #ifdef debug
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    #endif // debug

    while(getmap()){
        floyd();
        solve();
    }
    return 0;
}
