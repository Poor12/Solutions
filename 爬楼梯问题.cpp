//爬楼梯 n个台阶，每次走一个或两个，有多少种不同方法
int climbstairs(int n)
{
	int fn_2 = 1, fn_1 = 2;
	if (n == 1) return fn_2;
	if (n == 2) return fn_1;
	int fn;
	for (int i = 3;i <= n;++i)
	{
		fn = fn_2 + fn_1;
		fn_2 = fn_1;
		fn_1 = fn;
	}
	return fn;
}