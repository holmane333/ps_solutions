#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int n;
int visit[200010], count[200010], len[200010], res[200010];
int* ary[200010];

void bfs(int q[], int ft, int rr) {
	int cnt = 0;
	int t = 1;
	while(ft != rr) {
		//for (int i = rr; i < ft; ++i) printf("%d ", q[i]); puts("");
		int a = q[rr++];
		if (a == -1) {
			++cnt;
			++t;
			if (cnt >= 2) break;
			q[ft++] = -1;
			continue;
		}
		cnt = 0;
		for (int i = 0; i < len[a]; ++i) {
			if (visit[ary[a][i]]) continue;
			count[ary[a][i]]++;
			if (count[ary[a][i]] >= len[ary[a][i]] / 2 + len[ary[a][i]] % 2) {
				q[ft++] = ary[a][i];
				res[ary[a][i]] = t;
				visit[ary[a][i]] = 1;
			}
		}
	}
}

int main(void) {
	memset(res, -1, sizeof(res));
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		ary[i] = malloc(sizeof(int));
		while(1){
			int a;
			scanf("%d", &a);
			if (a == 0) break;
			++len[i];
			ary[i] = realloc(ary[i], sizeof(int) * len[i]);
			ary[i][len[i] - 1] = a;
		}
	}
	int t;
	scanf("%d", &t);
	int queue[2000010], ft = 0, rr = 0;
	for (int i = 0; i < t; ++i) {
		int a;
		scanf("%d", &a);
		queue[ft++] = a;
		res[a] = 0;
		visit[a] = 1;
	}
	queue[ft++] = -1;
	//printf("%d %d\n", ft, rr);
	/*for (int i = 1; i <= n; ++i) printf("%d ", len[i]); puts("");
	for (int i = 1; i <= n; ++i) {
		for (int j= 0; j < len[i]; ++j) printf("%d ", ary[i][j]); puts("");
	}*/
	bfs(queue, ft, rr);
	for (int i = 1; i <= n; ++i) printf("%d ", res[i]); puts("");
	//for (int i = 1; i <= n; ++i) printf("%d ", count[i]); puts("");
	return 0;
}
