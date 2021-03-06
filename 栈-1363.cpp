//出入栈序列的置换
/*
方法一：
	按照"先进后出"的规则，置换中的任何元素出栈前原来在栈中的所有大于x的元素必须出栈，而栈内元素值必须小于x。因为大于x的元素后于x入栈，小于x的元素先于x入栈。
	设置换的合法标志为valid,栈中或已出栈的最大值为max，元素的出入栈的标志序列为p。
	p[x]=0,元素x未入栈
	p[x]=1,元素x在栈中
	p[x]=2,元素x已出栈
	计算过程中：
	初始时，所有元素未入栈，即p中所有元素设为0，max=0.
	依次读入当前置换的每个元素x，按照下述办法判断置换是否合法。
	在目前置换合法的情况下：
	1.看栈中是否存在大于x的元素t。如果有（p[t]==1,x+1<=t<=max),则按照后进先出规则无法出栈，失败退出
	2.调整栈中和已出栈元素的最大值（max=(max>x?max:x)
	3.所有小于x且未入栈的元素p[j]入栈（p[j]由0调整至1，1<=j<=x-1)
	算法复杂度为O（n^3)
*/
/*
const int maxn = 1000 + 10;
int main() {
	int n, p[maxn];
	cin >> n;
		while (n)
		{
			int x, max = 0;
			cin >> x;
			while (x)
			{
				memset(p, 0, sizeof(p));//所有元素未进栈
				bool valid = true;
				for (int i = 1;i <= n;++i) {
					if (valid)
					{
						bool ok = true;
						for(int i=x+1;i<=max;++i)
							if (p[i] == 1) {
								ok = false;
								break;
							}
						if (!ok)
							valid = false;
						else
						{
							max = (max > x ? max : x);
							p[x] = 2;
							for (int i = x - 1;i > 0 && !p[i];--i)
								p[i] = 1;
						}
					}
					if (i < n)
						cin >> x;
				}
				cout << (valid ? "Yes" : "No") << endl;
				cin >> x;
			}
			cout << endl;
			cin >> n;
		}
		return 0;
}
*/

/*模拟进出栈，按照入栈序列进栈，同时比较置换序列，看按照这个顺序是否顺利出栈
1.如果当前进栈的元素是下一个要出栈的元素，直接让它入栈出栈即可。
2.如果当前栈顶元素是下一个出栈元素，则让它出栈。
3.否则当前元素进栈，分析下一个要进栈的元素。
复杂度为O（n）
*/
int main() {
	int a[1005], b[1005], i, j, k, n;//a为入栈序列，栈顶指针为k，b为出栈序列，栈顶指针为j
	while (scanf("%d", &n), n) {
		while (scanf("%d",&b[0]),b[0])
		{
			for (j = 1;j < n;++j)
				scanf("%d", &b[j]);
			for (i = 1, j = 0, k = 0;i < n&&j < n;++i, ++k)
			{
				a[k] = i;
				while (a[k]==b[j])
				{
					if (k > 0) k--;
					else
					{
						a[k] = 0;
						k--;
					}
					j++;
					if (k == -1)
						break;
				}
			}
			if (j == n) printf("yes\n");
			else
				printf("no\n");

		}
		printf("\n");
	}
	return 0;
}