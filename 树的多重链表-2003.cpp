#include <string>
#include <iostream>
#include <list>
#include <map>
//多重链表可与双亲表示法结合使用只表示一层的节点，否则的话使用嵌套链表的结构
using namespace std;
struct Tman {
	string name;
	Tman *f;//父指针回指
	list<Tman *> s;
	Tman() { f = NULL; };
};
map<string, Tman*> hashh;//多重链表,存储以成员名x为根的子树指针，通过键直接找子树的根，无需遍历
Tman *root;//根节点指针
void print(long dep, Tman *now) {
	if (now == NULL)
		return;
	for (long i = 1;i <= dep;++i)
		cout << '+';//层数个'+'
	cout << now->name << endl;
	for (auto it = now->s.begin();it != now->s.end();it++) {
		print(dep + 1, *it);
	}
}
void fire(string n1) {
	Tman *s = hashh[n1];//以n1为根的子树指针为*s,s的父指针为f
	Tman *f = s->f;
	hashh.erase(n1);//释放以n1为根的子树
	while (s->s.size() != 0) {//从s出发，将其左链的节点依次上升一个层次
		s->name = s->s.front()->name;//儿子队列首节点的名字调整为s的名字 s既是上个节点的儿子队列的首节点也是原先儿子节点的父节点，改变s将导致上下节点的改变
		hashh[s->name] = s;//s调整为以s->name为根的子树指针
		s = s->s.front();//儿子队列的首节点调整为s
	}
	s->f->s.remove(s);//s从其父的儿子队列中移除
	delete s;//删除s
}
void hires(string n1, string n2) {
	Tman *f = hashh[n1];
	Tman *s = new Tman();
	s->name = n2;
	s->f = f;
	f->s.push_back(s);
	hashh[n2] = s;
}
void solve() {
	string s1, s2;
	long i;
	cin >> s1;
	root = new Tman();
	hashh[s1] = root;
	root->name = s1;
	while (cin>>s1)
	{
		if (s1 == "print") {
			print(0, root);
			for (int i = 1;i <= 60;++i) cout << '-';
			cout << endl;
		}
		else if (s1 == "fire") {
			cin >> s2;
			fire(s2);
		}
		else {
			cin >> s2;//空读hires
			cin >> s2;
			hires(s1, s2);
		}
	}
}
int main() {
	solve();
	return 0;
}