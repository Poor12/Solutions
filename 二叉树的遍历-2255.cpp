//二叉树的中序遍历和前序遍历或后序遍历都能唯一确定二叉树的结构，但前序遍历和后序遍历无法唯一确定
//由二叉树的中序以及后序来确定前序的结果：
//由二叉树的遍历规则可知，后序遍历的最后一个字符为根，中序遍历结果中位于该字符左侧的字串为左子树的结果，右侧的字串为右子树的结果
//设中序遍历结果：s'=s1'...sk'...sn',后序遍历结果为s''...sn''
//先输出根sn'',然后分析左右子树
//若k>1,说明左子树存在，位于sk'左侧的字串为左子树中序遍历的结果，后序遍历中的前缀s1''...sk-1''为左子树后序遍历的结果
//若k<n,说明右子树存在，同理分析右子树
//分别递归左右子树
FILE *input;
char preord[30], inord[30];
int read_case() {
	if (feof(input)) return 0;
	fscanf(input, "%s %s", preord, inord);
	return 1;
}
void recover(int preleft,int preright,int inleft,int inright) {
	int root, leftsize, rightsize;
	assert(preleft <= preright && inleft <= inright);
	for (root = inleft;root <= inright;++root) {
		if (inord[root] == preord[preleft])
			break;
	}
	leftsize = root - inleft;
	rightsize = inright - root;
	if (leftsize > 0) {
		recover(preleft + 1, preleft + leftsize, inleft, root - 1);
	}
	if (rightsize > 0) {
		recover(preright-rightsize+1,preright , root+1, inright);
	}
	printf("%c", inord[root]);
}
void solve_case() {
	int n = strlen(preord);
	recover(0, n - 1, 0, n - 1);
	printf("\n");
}
int main() {
	input = fopen("a.txt", "rb");
	assert(input != NULL);
	while (read_case())
	{
		solve_case();
	}
	fclose(input);
	return 0;
}