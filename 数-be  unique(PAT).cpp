#include<stdio.h>
int main()
{
    int n, flag = 0, i, a[100005], num[100005] = {};
    scanf("%d", &n);
    for (i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
        num[a[i]]++;
    }
    for (i = 0;i < n;i++)
    {
        if (num[a[i]] == 1)
        {
            flag = 1;
            printf("%d", a[i]);
            break;
        }
    }
    if (flag == 0)
        printf("None");
    return 0;
}