#include <iostream>
using namespace std;
int main(){
    int n,a=1,ans=0;
    int left,now,right;
    cin>>n;
    while(n/a){
        left=n/a/10;  //当前位的高位数
        now=n/a%10;
        right=n%a;    //当前位的低位数
        if(now==0) ans+=left*a;                //高位为0到left-1，当前位为1时，每个带a个1
        else if(now==1) ans+=left*a+(right+1); //当前位为1时，还要加上高位为left时低位数个1
        else ans+=(left+1)*a;                  //当前位大于1时，高位0到left当前位为1，每个带a个1
        a*=10;
    }
    cout<<ans;
    return 0;
}