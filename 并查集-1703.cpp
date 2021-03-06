//并查集 set[d]为罪犯d所属集合的代表元，set[d+n]为d所属集合对立集合的代表元
//初始时所有罪犯各自属于一个帮派
//仅能判断任两个元素是否属于同一个集合的情况，不能判断每个集合的元素个数或是排列情况
int n, m;
const int maxn = 100000 + 5;
int set[maxn + maxn];
int set_find(int d) {
	if (set[d] < 0)
		return d;
	return set[d] = set_find(set[d]);
}
int main() {
	int loop;
	scanf("%d", &loop);
	while (loop--) {
		scanf("%d%d", &n, &m);
		memset(set, -1, sizeof(set));//两个帮派两个根，k所属的帮派设为set[k],另一个帮派为set[k+n]
		for (int i = 0;i < m;++i) {
			int a, b;
			char s[5];
			scanf("%s %d %d", s, &a, &b);
			if (s[0] == 'A') {
				if (set_find(a) != set_find(b) && set_find(a) != set_find(b + n)) {
					printf("%s\n", "not sure yet");
				}
				else if (set_find(a) == set_find(b)) {
					printf("%s\n", "in the same gang");
				}
				else {
					printf("%s\n", "in different gangs");
				}
			}
			else {
				if (set_find(a) != set_find(b)) {//若a所属的帮派不为b所属的帮派，则a的帮派设为b的另一个帮派，b的帮派设为a的另一个帮派
					set[set_find(a)] = set_find(b + n);
					set[set_find(b)] = set_find(a + n);

				}
			}
		}
	}
	return 0;
}