#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	POJ 3299 
*/
char a, c;
double b, d,temp,hum,dew;
double dotemp() {//已知露点与湿热指数求温度
	double e = 6.11*exp((1 / 273.16 - 1 / (dew + 273.16))*5417.7530);
	double h = 0.5555*(e - 10);
	return hum - h;
}
double dohum() {
	double e = 6.11*exp((1 / 273.16 - 1 / (dew + 273.16))*5417.7530);
	double h = 0.5555*(e - 10);
	return temp + h;
}
double dohum1(double tt, double dd) {
	double e = 6.11*exp((1 / 273.16 - 1 / (dd+ 273.16))*5417.7530);
	double h = 0.5555*(e - 10);
	return tt + h;
}
double dodew() {
	double h = hum - temp;
	double e = h / 0.5555 + 10;
	return 1 / (1 / 273.16 - log(e / 6.11) / 5417.7530) - 273.16;
}
double dodew2() {
	double x = 0;
	double delta = 100;
	for (delta = 100;delta > .00001;delta *= .5) {
		if (dohum1(temp, x) > hum) x -= delta;
		else x += delta;
	}
	return x;
}
int main() {
	
	while (scanf(" %c %lf %c %lf",&a,&b,&c,&d)==4&&a!='E')//float %f double %lf scanf第一个%c结束后按下回车，回车被保存直到下一个scanf时会被读取，所以如果下一个scanf的格式控制符仍是%c时出错
	{
		//char k = getchar();
		temp = hum = dew = -9999;
		if (a == 'T') temp = b;
		if (a == 'D') dew = b;
		if (a == 'H') hum = b;
		if (c == 'T') temp = d;
		if (c == 'D') dew = d;
		if (c == 'H') hum = d;
		if (temp == -9999) temp=dotemp();
		if (hum == -9999) hum=dohum1(temp,dew);
		if (dew == -9999) dew=dodew2();
		printf("T %0.1lf D %0.1lf H %0.1lf\n", temp, dew, hum);
		
	}
	
	assert(a == 'E');//断言,不是E时会中断
}