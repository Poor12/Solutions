#include #include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
using namespace std;
/************拉丁方阵问题****************/

typedef struct CLinkList
{
	int data;
	struct CLinkList *next;
}node;


int main()
{
	///建立循环链表
	node *L, *r, *s;
	L = new node;
	r = L;
	int n = 4, i,j;
	for (i = 1;i <= n;i++)       //尾插法建立链表
	{
		s = new node;
		s->data = i;
		r->next = s;
		r = s;
	}
	r->next = L->next;       //让最后一个结点指向第一个有数据结点
	node *p;
	p = L->next;
	//delete L;   //删除第一个空的结点
	
	p = L;
	for (int i = 0;i < n;++i) {
		p = p->next;
		for (int j = 0;j < n;++j) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	return 0;
}
