#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
/*
	POJ 2196 进制转换 
*/
int calc(int k, int b) //转化进制并求和
{
	
	int x, sum = 0;
	
	while (k)
	{
		
		x = k % b;
		
		sum += x;
		
		k = k / b;

	}
	
	return sum;
}

int main()
{
	
	for (int i = 2992;i <= 9999;++i)
	{
		
		if (calc(i, 10) == calc(i, 12) && calc(i, 12) && calc(i, 16))
		{

			cout << i << endl;
		
		}
	
	}
	
	return 0;
	
}