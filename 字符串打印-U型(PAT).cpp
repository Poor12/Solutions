#include <stdio.h>
#include <string.h>
 
char str[100];
 
void fun(int n)
{
    int side,bottom;
    int i,j;
    bottom = 3;
     
    int max=0;
    for(i=bottom;i<=n;i++) //寻找满足条件的最大的侧边
    {
        if((n-i)%2 == 0)  //总数减去底边数,必须是偶数
        {
            side = (n-i)/2 + 1;   //侧边数
            bottom = i;       //底边数
            if(bottom >= side&&side>max)   //需满足条件
            {
                max=side;
                //printf("bottom=%d,side=%d\n",bottom,side);
               // break;
            }
        }
    }
     
    side=max;
    for(i=0;i<side-1;i++)  //打印侧边
    {
        printf("%c",str[i]);
        for(j=0;j<bottom-2;j++)
        {
            printf(" ");
        }
        printf("%c",str[n-i-1]);
        printf("\n");
    }
     
    for(i=side-1;i<n-side+1;i++)  //打印底边
    {
        printf("%c",str[i]);
    }
}
 
int main()
{
    int len;
    while(~scanf("%s",str))
    {
        len = strlen(str);
        fun(len);
    }
 
    return 0;
}
