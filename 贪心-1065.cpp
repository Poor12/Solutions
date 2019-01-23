const int N = 5000;
struct node
{
	node& operator=(node &n)
	{
		l = n.l;
		w = n.w;
		isUsed = n.isUsed;
		return *this;
	}
	bool operator>(node &n)
	{
		return l > n.l || (l == n.l&&w > n.w);
	}
	void swap(node &n)
	{
		node tmp = *this;
		*this = n;
		n = tmp;
	}
	int l, w;
	bool isUsed;
}a[N];

int main()
{
	int t, n, i, j, k;
	cin >> t;
	for (i = 0;i < t;++i)
	{
		cin >> n;
		for (j = 0;j < n;++j)
		{
			cin >> a[j].l >> a[j].w;
			a[j].isUsed = 0;
		}
		for (j = 1;j < n;++j)
		{
			for (k = 1;k <= n - j;++k)
			{
				if (a[k - 1] > a[k])
				{
					a[k-1].swap(a[k]);
				}
			}
		}
		node cur = a[0];
		a[0].isUsed = 1;
		int c = 0;
		/*
		while (1)
		{
			for (j = 1;j < n;++j)
				if(a[j].isUsed==0)
					if (a[j].l >= cur.l&&a[j].w >= cur.w)
					{
						//a[j].isUsed = 1;
						//cur = a[j];
					}
			c++;
			for(j=1;j<n;++j)
				if (a[j].isUsed == 0)
				{
					cur = a[j];
					a[j].isUsed = 1;
					break;
				}
			if (j == n)
				break;
		}
		*/
		k = 0;
		while (1)
		{
			for (j = k+1;j < n;++j)
			{
				if (a[j].l >= cur.l&&a[j].w >= cur.w)
				{
					cur = a[j];
					k = j;
				}
				else
				{
					cur = a[j];
					break;
				}	
			}
			c++;
			if (k + 1 == n)
				break;
		}
		cout << c << endl;
	}
}