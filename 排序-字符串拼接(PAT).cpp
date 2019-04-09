#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string s[10010];
bool cmp(string a,string b){
    return a+b<b+a;                   //string型直接拼接来比较
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s,s+n,cmp);
    string str;
    for(int i=0;i<n;i++)
        str+=s[i];                   //将排序后数字串拼接起来
    int len=str.length();
    int k;
    for(k=0;k<len;k++){
        if(str[k]!='0') break;      //找到第一个非0的数字
    }
    if(k==len) cout<<'0';           //若全为0，直接输出0
    else{
        for(;k<len;k++)
            cout<<str[k];
    }
    return 0;
}