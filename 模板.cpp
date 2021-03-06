#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
using namespace std;

/*
struct point {
	int x, y;
	point(int x = 0, int y = 0) :x(x), y(y) {}
};
point operator + (const point &a, const point &b) 
{
	return point(a.x + b.x, a.y + b.y);
}
ostream& operator << (ostream &out, const point &p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}
*/
template <typename T>
struct point {
	T x, y;
	point(int x = 0, int y = 0) :x(x), y(y) {}
};
template <typename T>
point<T> operator + (const point<T> &a, const point<T> &b)
{
	return point<T>(a.x + b.x, a.y + b.y);
}
template <typename T>
ostream& operator << (ostream &out, const point<T> &p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

template<typename T>
T sum(T *begin, T *end)
{
	T *p = begin;
	T ans = 0;
	for (T *p = begin;p != end;p++)
	{
		ans = ans + *p;
	}
	return ans;
}


int main()
{
	double a[] = { 1.1,2.2,3.3,4.4 };
	cout << sum(a, a + 4) << "\n";
	point<int> b[] = { point<int>(1,2),point<int>(3,4),point<int>(5,6),point<int>(7,8) };
	cout << sum(b, b + 4) << "\n";
}