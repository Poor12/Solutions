//一元多项式中x是形式变量，ai是多项式的系数，使得ai！=0的最大i称为多项式的系数，如果对所有的i，ai都为0，则该多项式的系数为-∞，如果多项式的度数是0或-∞，则该多项式是平凡的，否则是非平凡的。
//判断多项式是否可以化简
int main()
{
	//freopen("t.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	if (n <= 1)
	{
		printf("YES\n");
		return 0;
	}
	if (n > 2)
	{
		printf("NO\n");
		return 0;
	}
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (b * b - 4 * a * c >= 0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}