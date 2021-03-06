//复制带有随机指针的链表
//给定一个链表，其中每个节点包含一个额外的随机指针，他可以指向链表中的任何节点或为空
struct node {
	int data;
	node* next;
	node* random;//随机指针
	node(int d) :data(d) {};
};
node* copyRandomList(node* head) {
	node* cur = head;
	//插入节点
	while (cur)
	{
		node* temp = new node(cur->data);
		temp->next = cur->next;
		cur->next = temp;
		cur = temp->next;
	}
	//复制随机指针
	cur = head;
	while (cur)
	{
		node* temp = cur->next;
		if (cur->next)
			temp->random = cur->random->next;
		cur = temp->next;
	}
	//将链表拆分
	cur = head;
	node* dup = head == NULL ? NULL : head->next;
	while (cur)
	{
		node* temp = cur->next;
		cur->next = temp->next;
		if (temp->next != NULL)
			temp->next = temp->next->next;
		cur = cur->next;
	}
	return dup;
}