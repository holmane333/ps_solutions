#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, *ary[10010], v[10010], v2[10010], len[10010];

int dfs(int x) {
	if (v[x]) return v[x];
	v[x] = 1;
	for (int i = 0; i < len[x]; ++i) {
		if (!v[ary[x][i]]) {
			v[x] += dfs(ary[x][i]);
		}
	}
	return v[x];
}

int main(void) {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < 10001; ++i) ary[i] = (int*)malloc(sizeof(int));
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ary[b] = (int*)realloc(ary[b], sizeof(int) * (++len[b]));
		ary[b][len[b] - 1] = a;
	}
	
	int res[10010], l = 0, val = 0;
	for (int i = 1; i <= n; ++i) {
		memset(v, 0, sizeof(v));
		int now = dfs(i);
		//printf("%d %d\n", i, now);
		if (val < now) {
			val = now;
			l = 0;
			res[l++] = i;
		}
		else if (val == now) {
			res[l++] = i;
		}
	}
	
	for (int i = 0; i < l; ++i) {
		printf("%d ", res[i]);
	}
	puts("");
	return 0;
}
