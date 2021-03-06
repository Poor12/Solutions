#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int NN = 1e4+100;
int vis[NN][NN],a[NN][NN],b[NN]; 
int main()
{
	ios::sync_with_stdio(false);
	int N,i,j,n,m,k,flag;
	cin>>N;
	for(i=1;i<=N;i++) cin>>b[i];
	sort(b+1,b+1+N,greater<int>());
	for(i=1;i<=sqrt(N);i++) {
		if(N%i==0) m=i,n=N/i;
    }   
	for(i=1;i<=n;i++) vis[i][m+1]=1;
	for(i=1;i<=m;i++) vis[n+1][i]=1;
	for(i=1;i<=n;i++) vis[i][0]=1;
	k=0,flag=1,i=1,j=1;
	while(1) {
		a[i][j]=b[++k];
		if(k==N) break;
		vis[i][j]=1;
		if(flag==1) {
			if(vis[i][j+1]==0) j++;
			else flag=2,i++;
		}
		else if(flag==2) {
			if(vis[i+1][j]==0) i++;
			else flag=3,j--;
		}
		else if(flag==3) {
			if(vis[i][j-1]==0) j--;
			else i--,flag=4;
		}
		else {
			if(vis[i-1][j]==0) i--;
			else j++,flag=1;
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(j!=1) cout<<" ";
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
 
 
