//线性表排序 map的使用
#include <string>
#include <map>
typedef map<string, int> record;
record h;
string s;
int n;
int main() {
	n = 0;
	while (getline(cin,s))
	{
		n++;
		h[s]++;
	}
	for (auto it = h.begin();it != h.end();it++) {
		string name = (*it).first;
		int k = (*it).second;
		printf("%s %.4lf\n", name.c_str(), double(k) * 100 / double(n));
	}
	return 0;
}
