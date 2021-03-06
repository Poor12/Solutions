//求平方根
#include <math.h>
int main()
{
	double a, x0, x1;
	printf("input a:\n");
	scanf("%lf", &a);
	if (a < 0)
		printf("error!\n");
	else
	{
		x0 = a / 2;
		x1 = (x0 + a / x0) / 2;
		do {
			x0 = x1;
			x1 = (x0 + a / x0) / 2;
		} while (fabs(x0 - x1) >= 1e-6);
	}
	printf("result:\n");
	printf("sqrt(%g)=%g\n", a, x1);
	return 0;
}