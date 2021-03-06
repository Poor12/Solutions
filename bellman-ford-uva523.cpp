//多源的bellman-ford
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

struct node{
    int cost;
    int nexthop;
};

node route[300][300];

int cost[300][300];

int n;

bool getmap(){
    scanf("%d",&n);
    if(n==0) return 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i][i]);
    }
    return 1;
}

void init_map(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                route[i][j].cost=0;
                route[i][j].nexthop=j;
                continue;
            }
            if(cost[i][j]<0){
                route[i][j].cost=MAXN;
                route[i][j].nexthop=-1;
            }else{
                route[i][j].cost=cost[i][j];
                route[i][j].nexthop=j;
            }
        }
    }
    for(int l=0;l<n-1;l++){//n-1次迭代
       for(int i=1;i<=n;i++){//起始节点
             for(int k=1;k<=n;k++){//边的起始节点
                if(i==k||cost[i][k]<0){
                    continue;
                }
                for(int j=1;j<=n;j++){//边的目标节点
                    if(route[i][j].cost>cost[i][k]+route[k][j].cost+cost[k][k]||(route[i][j].cost==cost[i][k]+route[k][j].cost+cost[k][k]&&route[i][j].nexthop>k)){
                        //路径从小到大。 
                        route[i][j].cost=cost[i][k]+route[k][j].cost+cost[k][k];
                        route[i][j].nexthop=k;
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
            for(f=route[from][to].nexthop;f!=to;f=route[f][to].nexthop){
                printf("-->%d",f);
            }
            printf("-->%d",to);
        }
        printf("\n");
        printf("Total cost : %d\n\n",route[from][to].cost);
    }
}

int main()
{
    #ifdef debug
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    #endif // debug

    while(getmap()){
        init_map();
        solve();
    }
    return 0;
}
