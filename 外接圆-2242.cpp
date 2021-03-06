/* POJ2242 HDU1374 ZOJ1090 UVA438 The Circumference of the Circle */

/* 利用海伦公式进行计算
	a=AB,b=BC,c=CA,p=(a+b+c)/2
	s=根号p(p-a)(p-b)(p-c)=1/2*a*b*sin(ab)
	c/sin(ab)=d(外接圆直径)
*/

#include <iomanip>


const double PI = acos(-1.0);

int main(void)
{
	double x1, y1, x2, y2, x3, y3;
	while (~scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3)) {
		double a = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
		double b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
		double c = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		double p = (a + b + c) * 0.5;
		double s = sqrt(p * (p - a) * (p - b) * (p - c));
		double d = a * b * c / (2.0 * s);

		//        printf("%.2lf\n", d * PI);
		cout << setiosflags(ios::fixed) << setprecision(2) << d * PI << endl;
	}

	return 0;
}
