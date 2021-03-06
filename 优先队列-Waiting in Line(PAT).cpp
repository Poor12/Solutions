#include <cstdio>
#include <queue>
using namespace std;
const int MAXK = 1010;
const int ONTIME = 8 * 60;
const int OFFTIME = 17 * 60;

int N, M, K, Q, C;
int wftime[21] = { 0 };
struct node {
	int stime, ftime, wid;
	friend bool operator <(const node&a, const node&b) {
		if (a.ftime != b.ftime) return a.ftime > b.ftime;
		return a.wid > b.wid;
	}
}customer[MAXK], cid;
priority_queue<node> q;
void printtime(int ftime, int stime) {
	if (ftime - stime + ONTIME >= OFFTIME) printf("Sorry\n");
	else printf("%02d:%02d\n", (ftime + ONTIME) / 60, (ftime + ONTIME) % 60);
}
int main()
{
	int query, t, winid;
	scanf("%d%d%d%d", &N, &M, &K, &Q);//n窗口数，m队伍最大容量，k顾客，q查询
	C = N * M;
	for (int i = 1;i <= K;++i) {
		scanf("%d", &t);
		customer[i].stime = t;
		if (q.size() < C) {
			winid = customer[i].wid = (i - 1) % N + 1;
		}
		else {
			cid = q.top();
			q.pop();
			winid = customer[i].wid = cid.wid;
		}
		customer[i].ftime = t + wftime[winid];
		wftime[winid] = customer[i].ftime;
		q.push(customer[i]);
	}
	for (int i = 0;i < Q;++i) {
		scanf("%d", &query);
		printtime(customer[query].ftime, customer[query].stime);
	}
	return 0;
}