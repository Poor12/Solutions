#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
#define MAX 10012
struct node{
  char name[10];
  int h;
  bool operator >(const node& a)const{
    if(h==a.h){
      return strcmp(a.name,name)>0?true:false;	//最后错误点，没有返回bool型 
    }
    return h>a.h;
  }
};
node a[MAX];
int mem[11][MAX];
int main(){
  int N,K;
  scanf("%d%d",&N,&K);
  
  for(int i=0;i<N;i++){
    getchar();
    scanf("%s%d",a[i].name,&a[i].h);
  }
  sort(a,a+N,greater<node>());
  int n,m;
  n = K;//四舍五入  可能会错  
  m = (int)N/K;//最后一行
  int fr = m+N%K;
  
  int time = 0;	//计数 
  for(int i=0;i<n;i++){
    int r;
    int f = 0;
    if(i==0){	//最上面一行单独判断 
      r = fr-1;
    }
    else r = f+m-1;
    int mid = (f + r)/2 + (f+r)%2;
    int d = mid;
    int c = 1;
    for(int j=f;j<=r;j++){  //左右插入 
      mem[i][d] = time++;
      if(d>=mid)  d=mid-c;	//先左后右 
      else{
        d=mid+c;
        c++;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i==0){
      for(int j=0;j<fr;j++){
        printf("%s",a[mem[i][j]].name);
        if(j!=fr-1)  printf(" ");
        else printf("\n");
      }
    }
    else{
      for(int j=0;j<m;j++){
        printf("%s",a[mem[i][j]].name);
        if(j!=m-1)  printf(" ");
        else printf("\n");
      }
    }
  }
  return 0;
}