#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int pd(long long sum){
    if(sum==1||sum==0) return 0;
    if(sum==2||sum==3) return 1;
    int r=floor(sqrt(sum)+0.5);
    for(int i=2;i<=r;i++){
        if(sum%i==0) return 0;
    }
    return 1;
}
int main(){
    int l,k;
    cin>>l>>k;
    string str;
    cin>>str;
    int flag=1;
    for(int i=0;i<=l-k;i++){
        long long sum=0;
        int cnt=0;
        for(int j=i;j<i+k;j++){
            if(str[j]=='0') cnt++;
            else break;
        }
        for(int j=i;j<i+k;j++){
            sum=sum*10+str[j]-'0';
        }
        if(pd(sum)){
            flag=0;
            for(int j=0;j<cnt;j++) printf("0");
            printf("%lld\n",sum);
            break;
        }
    }
    if(flag) printf("404");
    return 0;
}