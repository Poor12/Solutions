//相除的实现
//1.把除数向左移位然后与被除数比较，直到发现仅次于被除数的那个值
//2.用被除数减去该值后，作为新的被除数
//3.继续1和2直到被除数为0
int divide(int dividend, int divisor) {
	int sign = 1;
	if (dividend == 0) return 0;
	if (dividend < 0) sign *= -1;
	if (divisor < 0) sign *= -1;
	unsigned int dvd = dividend > 0 ? dividend : -dividend;
	unsigned int dvs = divisor > 0 ? divisor : -divisor;
	unsigned int inc[32];
	unsigned int migValue = dvs;
	int i = 0;
	while (migValue>0&&migValue<=dvd)
	{
		inc[i] = migValue;
		migValue = migValue << 1;
		i++;
	}
	i--;
	unsigned int res = 0;
	while (i>=0&&dvd!=0)
	{
		if (dvd >= inc[i])
		{
			dvd = dvd - inc[i];
			res += 1 << i;
		}
		i--;
	}
	res *= sign;
	return res;
}