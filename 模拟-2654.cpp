int w[100], l[100];//选手i获胜的场数以及失败的场数
int p1, p2, i, j, k, m, n;
char m1[10], m2[10];
int main()
{
	while (1==scanf("%d",&n)&&n!=0)
	{
		scanf("%d", &k);
		memset(w, 0, sizeof(w));
		memset(l, 0, sizeof(l));
		for (int i = 0;i < k;++i)
		{
			scanf("%d %s %d %s", &p1,m1,&p2,m2);
			if ((!strcmp(m1, "rock") && !strcmp(m2, "scissors")) || (!strcmp(m1, "scissors") && !strcmp(m2, "paper")) || (!strcmp(m1, "paper") && !strcmp(m2, "rock")))
			{
				w[p1]++;
				l[p2]++;
			}
			else if ((!strcmp(m1, "scissors") && !strcmp(m2, "rock")) || (!strcmp(m1, "paper") && !strcmp(m2, "scissors")) || (!strcmp(m1, "rock") && !strcmp(m2, "paper")))
			{
				l[p1]++;
				w[p2]++;
			}
		}
		for (int i = 1;i <=n;++i)
		{
			if(w[i]+l[i]) printf("%.3f\n", float(w[i]) / (w[i] + l[i]));
			else printf("-\n");
		}	
		printf("\n");
	}
}