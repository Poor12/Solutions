#include <deque>
//双端队列
deque<int> q;
char in[10];
int main() {
	int n, c, ca = 0, a, i;
	while (1) {
		scanf("%d%d", &n, &c);
		if (n == 0 && c == 0) break;
		ca++;
		printf("Case %d:\n", ca);
		for (int i = 1;i <= n && i <= 1000;++i) {
			q.push_back(i);
		}
		while (c--) {
			scanf("%s", in);
			if (strcmp(in, "N") == 0) {
				printf("%d\n", q.front());
				q.push_back(q.front());
				q.pop_front();
			}
			else if (strcmp(in, "E") == 0)
			{
				scanf("%d",&a);
				deque<int>::iterator it;
				for (it = q.begin();it != q.end();it++) {
					if ((*it) == a) {
						q.erase(it);
						break;
					}
				}
				q.push_front(a);
			}
		}
	}
	return 0;
}

