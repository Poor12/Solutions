//找出最大的n，使n！不大于2^k-1
//log2(n!)=log2（n）+.....+log2(1)<=log2(2^k-1)
#include <math.h>
int y, Y, i, j, m;
double f, w;
int main() {
	while (1==scanf("%d",&y)&&y)
	{
		w = log(4);
		for (Y = 1960;Y <= y;Y += 10)
			w *= 2;
		i = 1;
		f = 0;
		while (f < w)
		{
			f += log((double)++i);
		}
		printf("%d\n", i - 1);
	}
	if (y) printf("fishy ending %d\n", y);
}