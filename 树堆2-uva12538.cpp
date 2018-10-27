#include <ext/rope>//codeblocks编译器，块状链表(内部实现avl)
#include <iostream>
using namespace std;
using namespace __gnu_cxx;
crope ro,l[50005],tmp;//当前版本ro，版本序列l[],辅助变量tmp,采用crope(容纳字符的rope容器)
char str[205];
//ro.copy(p,c,str) 将ro的p位置开始的c个节点复制给str
int main(){
	int n,op,p,c,d,cnt,v;//指令数n、op命令字、cnt版本数、c版本序号
	scanf("%d",&n);
	d=0;
	cnt=1;
	while(n--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%s",&p,str);
			p-=d;
			ro.insert(p,str);//ro的p位置插入str
			l[cnt++]=ro;
		}
		else if(op==2){
			scanf("%d%d",&p,&c);
			p-=d;c-=d;
			ro.erase(p-1,c);//删除版本ro的p位置开始的c个字符，形成新版本
			l[cnt++]=ro;
		}
		else{
			scanf("%d%d%d",&v,&p,&c);
			p-=d;v-=d;c-=d;
			tmp=l[v].substr(p-1,c);
			d+=count(tmp.begin(),tmp.end(),'c');
			cout<<tmp<<"\n";
		}
	}
}