//分型图
#include <stdio.h>
#include <string.h>
int orders[27][4];
int maxPeoples, endStation, numOrders;;
int max;
int leane[8];
void train(int n, int sum)
{
     int i; 
     if (sum > max)	//最优性要求
        max = sum;
     if(n >= numOrders)//边界条件
          return;
     for (i = orders[n][0]; i < orders[n][1]; i++)//子状态约束条件
         if (leane[i]+orders[n][2] > maxPeoples)
            break;
     if (i >= orders[n][1]) {
        for (i = orders[n][0]; i < orders[n][1]; i++)
            leane[i] += orders[n][2];
        train(n+1, sum+orders[n][3]);//子状态运行
        for (i = orders[n][0]; i < orders[n][1]; i++)
            leane[i] -= orders[n][2];
     }
     train(n+1, sum);//下一状态
}
int main()
{
    int i;
    int a, b, p; 
    while (scanf("%d%d%d", &maxPeoples, &endStation, &numOrders), maxPeoples||endStation||numOrders) {
          memset(leane, 0, sizeof(leane));
          for (i = 0; i < numOrders; i++) {
              scanf("%d%d%d", &a, &b, &p);
              orders[i][0] = a;
              orders[i][1] = b;
              orders[i][2] = p;
              orders[i][3] = (b-a)*p;
          }
          max = 0;
          train(0, 0);
          printf("%d\n", max);
    }
    return 0;
}
