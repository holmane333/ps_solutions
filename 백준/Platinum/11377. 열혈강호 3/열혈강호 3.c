#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, k, ary[1010][1010], len[1010], cnt, visit[1010], ma[1010];

int find(int x) {
	for (int i = 0; i < len[x]; ++i) {
		if (visit[ary[x][i]]) continue;
		visit[ary[x][i]] = 1;
		if (!ma[ary[x][i]] || find(ma[ary[x][i]])) {
			ma[ary[x][i]] = x;
			return 1;
		}
	}
	return 0;
}

int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		int t;
		scanf("%d", &t);
		for (int j = 1; j <= t; ++j) {
			int a;
			scanf("%d", &a);
			ary[i][len[i]++] = a;
		}
	}
	for (int i = 1; i <= n; ++i) {
		memset(visit, 0, sizeof(visit));
		cnt += find(i);
	}
	for (int i = 1; i <= n; ++i) {
		memset(visit, 0, sizeof(visit));
		if (find(i)) {
			++cnt;
			--k;
		}
		if (k == 0) break;
	}
	printf("%d\n", cnt);
	return 0;
}
