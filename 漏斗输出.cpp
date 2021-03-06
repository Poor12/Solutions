链接：https://www.nowcoder.com/questionTerminal/5427d64b5dea499ba20906da72e12cfa
来源：牛客网

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;//思路：对每个数加1除以2再开方，取整所得结果就是单个边数，在*2-1就是层数
int main()
{
    char s;
    int N,n,t,i,j;//n代表层数，t为未使用的个数,最外层数也为n
    scanf("%d %c",&N,&s);
    n=sqrt((N+1)/2);
    t=N-2*n*n+1;
    n=n*2-1;
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<i;j++)
            printf(" ");
        for(j=n-2*i;j>0;j--)
            printf("%c",s);
            printf("\n");
    }
    for(i=n/2;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
            printf(" ");
        for(j=0;j<2*i-2*(n/2)+1;j++)
            printf("%c",s);
            printf("\n");
    }
    printf("%d\n",t);
    return 0;
}