#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, ary[110][110], len[110], cnt, visit[110], ma[110];

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
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ary[a][len[a]++] = b;
	}
	for (int i = 1; i <= n; ++i) {
		memset(visit, 0, sizeof(visit));
		cnt += find(i);
	}
	printf("%d\n", cnt);
	return 0;
}
