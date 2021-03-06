//先找到根，每一次添加的节点根据与根的大小比较可以确定其位于左子树或右子树
#include <string>
string preord(string leaves[],int levels) {
	while (levels>0&&leaves[levels-1].length()==0)//level>0树非空,向上找第一个非空项
	{
		levels--;
	}
	if (levels == 0) return "";
	levels--;
	char root = leaves[levels][0];
	string *left = new string[levels];
	string *right = new string[levels];
	for (int i = 0;i < levels;++i) {
		int past = 0;
		while (past<leaves[i].length()&&leaves[i][past]<root)
		{
			past++;
		}
		left[i] = leaves[i].substr(0, past);
		right[i] = leaves[i].substr(past);
	}
	return root + preord(left, levels) + preord(right, levels);
}
int main() {
	string leaves[26];
	string s;
	while (1) {
		int levels = 0;
		cin >> s;
		while (s[0] != '*'&&s[0]!='$')
		{
			leaves[levels] = s;
			levels++;
			cin >> s;
		}
		cout << preord(leaves, levels);
		if (s[0] == '$')
			break;
	}
	return 0;
}