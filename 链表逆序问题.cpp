//无头节点的链表逆序
/*
	//表头指针为h
	void reverse(&h)
	{
		if(!h) return;
		p=h->next;pr=null;
		while(!p)
		{
			h->next=pr;
			pr=h;
			h=p;
			p=p->next;
		}
		h->next=pr;
	}
*/

//带头节点的链表逆序
/*
	//h为头节点
void reverse(pointer h)
	{
	pointer p,q;
	p=h->next;
	h->next=null;
	while(p){
		q=p;
		p=p->next;
		q->next=h->next;
		h->next=q;
	}
}
*/